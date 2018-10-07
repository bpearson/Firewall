<?php
namespace Firewall;


class Util
{


    /**
     * Format a string to camelcase.
     *
     * @param string $value The value to format.
     *
     * @return string
     */
    public static function camelCase(string $value)
    {
        return str_replace(' ', '', ucwords(str_replace('-', ' ', $value)));

    }//end camelCase()


}//end class
