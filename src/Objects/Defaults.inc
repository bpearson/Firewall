<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;
use \Firewall\Main;


class Defaults extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_DEFAULTS';

    /**
     * The defaults.
     *
     * @var array
     */
    public $defaults = [];


    /**
     * Constructor.
     *
     * @param object $parent The parent node.
     * @param mixed  $value  The object value(s).
     *
     * @return void
     */
    public function __construct($parent, $value)
    {
        parent::__construct($parent, $value);

        if (is_array($value) === false) {
            throw new \Exception('Invalid defaults value');
        }//end if

        // Set the defaults.
        $commands = ($value['commands'] ?? []);
        foreach ($commands as $engine => $command) {
            $fwEngine = Main::getEngine($engine);
            if ($fwEngine !== null) {
                $fwEngine->command = $command;
            }//end if
        }//end foreach

    }//end constructor


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (($this->parentNode->type ?? null) !== 'FIREWALL_STATEMENT') {
            throw new \Exception('Defaults can only exist at the top');
        }//end if

        parent::validate();

    }//end validate()

    public function __toString()
    {
        $content = '';

        return $content;

    }//end __toString()


}//end class
