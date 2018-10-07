<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Lines extends AbstractParser
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
        if (is_array($parseValue) === false) {
            throw new \Exception('Invalid lines format');
        }//end if

        $parent = new Objects\Lines($firewall);
        foreach ($parseValue as $position => $childValue) {
            $child    = new Objects\Line($parent);
            $imported = false;
            foreach ($childValue as $key => $value) {
                if ($key === 'import') {
                    $imported = true;
                }//end if

                Main::process($child, $key, $value);
            }//end foreach

            if ($imported === false) {
                $parent->children[] = $child;
            }//end if
        }//end foreach

        $firewall->children[] = $parent;

    }//end parse()


}//end class
