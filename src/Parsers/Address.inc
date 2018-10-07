<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Address extends AbstractParser
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
            // Shortcut single address.
            $parseValue = ['address' => $parseValue];
        }//end if

        $object               = new Objects\Address($firewall);
        $object->direction    = ($parseValue['direction'] ?? 'destination');
        $object->value        = ($parseValue['address'] ?? '');
        $firewall->children[] = $object;

    }//end parse()


}//end class
