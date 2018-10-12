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
        if (isset($parseValue['chain']) === true) {
            $parseValue = [$parseValue];
        } else if (is_array($parseValue) === false) {
            $parseValue = ['chain' => $parseValue];
        }//end if

        foreach ($parseValue as $value) {
            if (is_string($value) === true) {
                $value = ['chain' => $value];
            }//end if

            $object               = new Objects\Rule($firewall);
            $object->value        = strtolower(($value['chain'] ?? $object->value));
            $object->rule         = strtolower(($value['rule'] ?? $object->rule));
            $firewall->children[] = $object;
        }//end foreach

    }//end parse()


}//end class
