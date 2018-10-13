<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;
use \Firewall\Main;


class Table extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_TABLE';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Value of the table.
     *
     * @var string
     */
    public $value = 'filter';


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->value) === true) {
            throw new \Exception('Table cannot have an empty value');
        }//end if

        $engine = Main::getEngine();
        if ($engine !== null && in_array($this->value, $engine->tables) === false) {
            throw new \Exception(sprintf('Invalid table %s', $this->value));
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = '';
        if ($this->value !== 'filter') {
            $content = ' -t '.$this->value;
        }//end if

        return $content;

    }//end __toString()


}//end class
