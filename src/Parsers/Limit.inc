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
        $limit                = new Objects\Limit($firewall);
        $limit->value         = (int) $parseValue;
        $firewall->children[] = $limit;

    }//end parse()


}//end class
