<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;
use \Firewall\Main;


class Protocol extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_PROTOCOL';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Value of the object.
     *
     * @var string
     */
    public $value = 'tcp';


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        $engine = Main::getEngine();
        if (empty($this->value) === true) {
            throw new \Exception('Protocol cannot have an empty value');
        } else if ($engine !== null && in_array($this->value, $engine->protocols) === false) {
            throw new \Exception(sprintf('Invalid protocol %s', $this->value));
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false) {
            $content = ' -p '.$this->value;
        }//end if

        return $content;

    }//end __toString()


}//end class
