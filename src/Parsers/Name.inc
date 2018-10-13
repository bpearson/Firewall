<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Objects;


class Name extends AbstractParser
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
            throw new \Exception('Invalid name');
        }//end if

        $object = new Objects\Name($firewall);
        $object->setName($parseValue);

        $firewall->children[] = $object;
        if (in_array($firewall->type, ['FIREWALL_STATEMENT', 'FIREWALL_ACTION']) === true) {
            // Automatically populate up when needed.
            $firewall->setName($parseValue);
        }//end if

    }//end parse()


}//end class
