<?php
namespace Firewall\Parsers;


use \Firewall\AbstractParser;
use \Firewall\Main;
use \Firewall\Objects;


class Defaults extends AbstractParser
{


    /**
     * Parse the value.
     *
     * @param object $firewall   The firewall object.
     * @param mixed  $parseValue The value to parse.
     *
     * @return void
     * @throws \Exception When the object is invalid.
     */
    public static function parse(&$firewall, $parseValue)
    {
        if (is_array($parseValue) === false) {
            throw new \Exception('Invalid defaults value');
        } else if (($firewall->type ?? null) !== 'FIREWALL_STATEMENT') {
            throw new \Exception('Defaults can only exist at the top');
        }//end if

        $object               = new Objects\Defaults($firewall);
        $object->value        = $parseValue;
        $firewall->children[] = $object;

        // Set the defaults.
        $commands = ($parseValue['commands'] ?? []);
        foreach ($commands as $engine => $command) {
            $fwEngine = Main::getEngine($engine);
            if ($fwEngine !== null) {
                $fwEngine->command = $command;
            }//end if
        }//end foreach


    }//end parse()

}//end class
