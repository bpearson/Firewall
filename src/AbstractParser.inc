<?php
namespace Firewall;


abstract class AbstractParser
{


    /**
     * Parse the value.
     *
     * @param object $firewall The firewall object.
     * @param mixed  $value    The value to parse.
     *
     * @return void
     */
    abstract public static function parse(&$firewall, $value);


}//end class
