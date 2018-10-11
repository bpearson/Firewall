<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Limit extends AbstractParser
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
            // Shortcut single port.
            $parseValue = ['rate' => $parseValue];
        }//end if

        $object               = new Objects\Limit($firewall);
        $object->value        = (int) ($parseValue['rate'] ?? 0);
        $object->unit         = strtolower(($parseValue['unit'] ?? 'second'));
        $firewall->children[] = $object;

    }//end parse()


}//end class
