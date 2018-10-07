<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class LogPrefix extends AbstractParser
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
        $prefix               = new Objects\LogPrefix($firewall);
        $prefix->value        = $parseValue;
        $firewall->children[] = $prefix;

    }//end parse()


}//end class
