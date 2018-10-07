<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Comment extends AbstractParser
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
        $object               = new Objects\Comment($firewall);
        $object->value        = $parseValue;
        $firewall->children[] = $object;

    }//end parse()


}//end class
