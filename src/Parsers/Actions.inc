<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Actions extends AbstractParser
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
            throw new \Exception('Invalid actions format');
        }//end if

        $parent = new Objects\Actions($firewall);
        foreach ($parseValue as $position => $childValue) {
            $child = new Objects\Action($parent);
            foreach ($childValue as $key => $value) {
                Main::process($child, $key, $value);
            }//end foreach

            $parent->children[] = $child;
        }//end foreach

        $firewall->children[] = $parent;

    }//end parse()


}//end class
