<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Target extends AbstractParser
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
            $parseValue = ['target' => $parseValue];
        }//end if

        $object               = new Objects\Target($firewall);
        $object->value        = strtolower(($parseValue['target'] ?? ''));
        $object->prefix       = ($parseValue['prefix'] ?? '');
        $firewall->children[] = $object;

    }//end parse()


}//end class
