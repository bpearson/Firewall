<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Limit extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_LIMIT';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Value of the limit.
     *
     * @var integer
     */
    public $value = 0;

    /**
     * Unit of the limit.
     *
     * @var string
     */
    public $unit = 'second';


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->value) === true) {
            throw new \Exception('Limit cannot have an empty value');
        }//end if

        if (in_array($this->unit, ['second', 'minute', 'hour', 'day']) === false) {
            throw new \Exception('Invalid unit set on limit');
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = ' -m limit --limit '.$this->value.'/'.$this->unit;

        return $content;

    }//end __toString()


}//end class
