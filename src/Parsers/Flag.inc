<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Flag extends AbstractParser
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
            throw new \Exception('Invalid value passed to flag');
        }//end if

        $object               = new Objects\Flag($firewall);
        $object->value        = explode(',', strtolower(($parseValue['mask'] ?? $object->value)));
        $object->match        = explode(',', strtolower(($parseValue['match'] ?? $object->match)));
        $firewall->children[] = $object;

    }//end parse()


}//end class
