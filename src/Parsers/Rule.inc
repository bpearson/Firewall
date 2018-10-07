<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Rule extends AbstractParser
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
            $parseValue = [$parseValue];
        }//end if

        foreach ($parseValue as $value) {
            $object               = new Objects\Rule($firewall);
            $object->value        = strtolower($value);
            $firewall->children[] = $object;
        }//end foreach

    }//end parse()


}//end class
