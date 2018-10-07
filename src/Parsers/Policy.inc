<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Policy extends AbstractParser
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
            // Short cut policy.
            $parseValue = ['chain' => $parseValue];
        }//end if

        $object               = new Objects\Policy($firewall);
        $object->value        = strtolower(($parseValue['chain'] ?? ''));
        $object->policy       = strtolower(($parseValue['policy'] ?? 'drop'));
        $firewall->children[] = $object;

    }//end parse()


}//end class
