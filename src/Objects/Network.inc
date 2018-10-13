<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Network extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_NETWORK_INTERFACE';

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
    public $value = '';

    /**
     * If true, use as input.
     *
     * @var boolean
     */
    public $in = false;

    /**
     * If true, use as output.
     *
     * @var boolean
     */
    public $out = false;


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->value) === true) {
            throw new \Exception('Network cannot have an empty value');
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false) {
            if ($this->in === true) {
                $content = ' -i '.$this->value;
            }//end if

            if ($this->out === true) {
                $content = ' -o '.$this->value;
            }//end if
        }//end if

        return $content;

    }//end __toString()


}//end class
