<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Target extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_TARGET';

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
    public $value = 'drop';

    /**
     * Log prefix.
     *
     * @var string
     */
    public $prefix = '';


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->value) === true) {
            throw new \Exception('Target cannot have an empty value');
        }//end if

        if ($this->value !== 'log' && empty($this->prefix) === false) {
            throw new \Exception('Prefix can only used with LOG target');
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = ' -j '.strtoupper($this->value);
        if ($this->value === 'log' && empty($this->prefix) === false) {
            $content .= ' --log-prefix "'.$this->prefix.'"';
        }//end if

        return $content;

    }//end __toString()


}//end class
