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
        return str_replace(' ', '', ucwords(str_replace('-', ' ', strtolower($value))));

    }//end camelCase()


    /**
     * Strip the namespace from a class.
     *
     * @param string $className The class name.
     *
     * @return string
     */
    public static function stripNamespace(string $className)
    {
        $lastPos = strrpos($className, '\\');
        if ($lastPos !== false) {
            $className = substr($className, ($lastPos + 1));
        }//end if

        return $className;

    }//end stripNamespace()


}//end class
