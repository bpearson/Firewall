<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Protocol extends AbstractParser
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
        $parseValue = strtolower($parseValue);
        if (in_array($parseValue, ['tcp', 'udp', 'icmp']) === false) {
            throw new \Exception(sprintf('Invalid protocol %s', $parseValue));
        }//end if

        $object               = new Objects\Protocol($firewall);
        $object->value        = $parseValue;
        $firewall->children[] = $object;

    }//end parse()


}//end class
