<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Import extends AbstractParser
{


    /**
     * Parse the value.
     *
     * @param object $firewall   The firewall object.
     * @param mixed  $parseValue The value to parse.
     *
     * @return void
     */
    public static function parse(&$firewall, $parseValue)
    {
        $top          = $firewall->findTopLevel();
        $validParents = [
            'FIREWALL_ACTIONS_LIST',
            'FIREWALL_LINES_LIST',
        ];
        if ($top === null) {
            throw new \Exception('Unable to find the top statement');
        } else if (file_exists($top->file) === false) {
            throw new \Exception('Unable to find the source file path');
        } else if (isset($firewall->parentNode) === false || in_array($firewall->parentNode->type, $validParents) === false) {
            throw new \Exception('Import node cannot be used at this location');
        }//end if

        $importFile = self::_getImportPath($top->file, $parseValue);
        if ($importFile !== false) {
            $import = Main::parse($importFile);
            if (empty($import->children) === false) {
                foreach ($import->children as $position => $parent) {
                    if (in_array($parent->type, $validParents) === false) {
                        throw new \Exception('Invalid parent node');
                    }//end if

                    foreach ($parent->children as $child) {
                        $child->parentNode                = $firewall->parentNode;
                        $firewall->parentNode->children[] = $child;
                    }//end foreach
                }//end foreach
            }//end if

            unset($import);
        }//end if

    }//end parse()


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


}//end class
