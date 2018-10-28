<?php
namespace Firewall;

use \Firewall\Main;
use \Firewall\Objects;
use \Firewall\Util;

class Yaml
{

    /**
     * Cache var for the current file.
     *
     * @var array
     */
    private static $_current = [];


    /**
     * Parse each element of the Yaml.
     *
     * @param object $parent The parent firewall object.
     * @param mixed  $key    The element key (only mixed for the integer keys).
     * @param mixed  $value  The element value.
     *
     * @return void
     */
    public static function parse(&$parent, $key, $value)
    {
        if (is_integer($key) === true) {
            throw new \Exception(sprintf('Invalid child element under %s', $parent->type));
        } else {
            $classObject = '\\Firewall\\Objects\\'.Util::camelCase($key);
        }//end if

        if ($key === 'import') {
            // Special case element.
            $validParents = [
                'FIREWALL_ACTIONS_LIST',
                'FIREWALL_LINES_LIST',
            ];
            if (isset($parent->parentNode) === false || in_array($parent->parentNode->type, $validParents) === false) {
                throw new \Exception('Import node cannot be used at this location');
            }//end if

            $importFile = self::_getImportPath(self::_get(), $value);
            if ($importFile !== false) {
                $import = Yaml::parseFile($importFile);
                if (empty($import->children) === false) {
                    foreach ($import->children as $position => $parentNode) {
                        if (in_array($parentNode->type, $validParents) === false) {
                            throw new \Exception('Invalid parent node');
                        }//end if

                        foreach ($parentNode->children as $child) {
                            $child->parentNode              = $parent->parentNode;
                            $parent->parentNode->children[] = $child;
                        }//end foreach
                    }//end foreach
                }//end if

                unset($import);
            }//end if

            return;
        }//end if

        if ($key === 'rule' && is_array($value) === true && isset($value[0]) === true) {
            // Multiple children.
            foreach ($value as $childValue) {
                Yaml::parse($parent, 'rule', $childValue);
            }//end foreach
        } else {
            $child = new $classObject($parent, $value);
            if (in_array($key, ['action', 'actions', 'line', 'lines']) === true) {
                if (is_array($value) === false) {
                    throw new \Exception('Invalid line element: '.$value);
                } else {
                    foreach ($value as $childKey => $childValue) {
                        switch ($key) {
                            case 'actions':
                                $childKey = 'action';
                            break;

                            case 'lines':
                                $childKey = 'line';
                            break;

                            case 'rule':
                                if (is_integer($childKey) === true) {
                                    $childKey = 'rule';
                                }//end if
                            break;

                            default:
                                $childKey = $childKey;
                            break;
                        }//end switch

                        Yaml::parse($child, $childKey, $childValue);
                    }//end foreach
                }//end if
            }//end if

            $parent->children[] = $child;
        }//end if

    }//end parse()


    /**
     * Parse a file.
     *
     * @param string $file The file to parse.
     *
     * @return object
     */
    public static function parseFile(string $file)
    {
        self::_set($file);
        $contents = yaml_parse_file(self::_get());
        $parent   = new Objects\Base(self::_get());
        if (is_array($contents) === true) {
            foreach ($contents as $key => $value) {
                Yaml::parse($parent, $key, $value);
            }//end foreach
        }//end if

        self::_clear();

        return $parent;

    }//end parseFile()


    /**
     * Clear the current file.
     *
     * @return void
     */
    private static function _clear()
    {
        reset(self::$_current);
        end(self::$_current);
        $current = key(self::$_current);
        unset(self::$_current[$current]);

    }//end _clear()


    /**
     * Get the current file.
     *
     * @return string
     */
    private static function _get()
    {
        reset(self::$_current);
        end(self::$_current);
        $current = key(self::$_current);
        $file    = (self::$_current[$current] ?? false);
        if (file_exists($file) === false) {
            throw new \Exception('No current file found');
        }//end if

        return $file;

    }//end _get()


    /**
     * Get the path of the import file.
     *
     * @param string $source The source file path.
     * @param string $value  The value of the import.
     *
     * @return string|false
     */
    private static function _getImportPath($source, $value)
    {
        $file = false;
        if (file_exists($value) === true) {
            // Absolute path.
            $file = $value;
        } else if (file_exists(dirname($source).'/'.$value) === true) {
            // Relative path.
            $file = dirname($source).'/'.$value;
        }//end if

        return $file;

    }//end _getImportPath()


    /**
     * Set the current file.
     *
     * @param string $file The file to set.
     *
     * @return void
     */
    private static function _set(string $file)
    {
        if (file_exists($file) === false) {
            throw new \Exception(sprintf('Invalid file %s', $file));
        }//end if

        reset(self::$_current);
        end(self::$_current);
        self::$_current[] = $file;

    }//end _set()


}//end class
