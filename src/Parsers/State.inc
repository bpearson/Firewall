<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class State extends AbstractParser
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
        if (is_string($parseValue) === false) {
            throw new \Exception('Invalid value passed to state');
        }//end if

        $object               = new Objects\State($firewall);
        $object->value        = explode(',', strtolower($parseValue));
        $firewall->children[] = $object;

    }//end parse()


}//end class
