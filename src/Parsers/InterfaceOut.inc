<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class InterfaceOut extends AbstractParser
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
        $interface            = new Objects\InterfaceOut($firewall);
        $interface->value     = $parseValue;
        $firewall->children[] = $interface;

    }//end parse()


}//end class
