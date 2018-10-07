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
        $target               = new Objects\Target($firewall);
        $target->value        = strtolower($parseValue);
        $firewall->children[] = $target;

    }//end parse()


}//end class
