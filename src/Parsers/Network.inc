<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Network extends AbstractParser
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
            $parseValue = ['device' => $parseValue];
        }//end if

        $object               = new Objects\Network($firewall);
        $object->value        = ($parseValue['device'] ?? $object->value);
        $object->in           = ($parseValue['in'] ?? $object->in);
        $object->out          = ($parseValue['out'] ?? $object->out);
        $firewall->children[] = $object;

    }//end parse()


}//end class
