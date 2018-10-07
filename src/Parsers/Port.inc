<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Port extends AbstractParser
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
        if (is_array($parseValue) === false) {
            // Shortcut single port.
            $parseValue = ['port' => (int) $parseValue];
        }//end if

        $object               = new Objects\Port($firewall);
        $object->direction    = ($parseValue['direction'] ?? 'destination');
        $object->value        = self::_getPortValues($parseValue);
        $firewall->children[] = $object;

    }//end parse()


    /**
     * Get port values.
     *
     * @param array $value The value to parse.
     *
     * @return string
     */
    private static function _getPortValues(array $value)
    {
        $port = '';
        if (isset($value['port']) === true) {
            if (is_array($value['port']) === true) {
                $port .= implode(',', $value['port']);
            } else {
                $port .= $value['port'];
            }//end if
        }//end if

        if (isset($value['range']) === true) {
            if (is_array($value['range']) === true) {
                $range = implode(',', $value['range']);
            } else {
                $range = $value['range'];
            }//end if

            if (empty($port) === true) {
                $port .= $range;
            } else {
                $port .= ','.$range;
            }//end if
        }//end if

        return $port;

    }//end _getPortValues()


}//end class
