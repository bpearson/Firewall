<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Table extends AbstractParser
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
        if (in_array($parseValue, ['filter', 'nat', 'mangle']) === false) {
            throw new \Exception(sprintf('Invalid table %s', $parseValue));
        }//end if

        $table                = new Objects\Table($firewall);
        $table->value         = $parseValue;
        $firewall->children[] = $table;

    }//end parse()


}//end class
