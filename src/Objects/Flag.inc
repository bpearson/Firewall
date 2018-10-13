<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Flag extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_FLAG';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Value of the object.
     *
     * @var array
     */
    public $value = [];

    /**
     * Match of the object.
     *
     * @var array
     */
    public $match = [];


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->value) === true) {
            throw new \Exception('Flag cannot have an empty value');
        }//end if

        if (empty($this->match) === true) {
            throw new \Exception('Flag cannot have an empty match');
        }//end if

        foreach ($this->value as $value) {
            if (in_array($value, ['syn', 'ack', 'fin', 'rst', 'urg', 'psh', 'all', 'none']) === false) {
                throw new \Exception('Invalid value in flag');
            }//end if
        }//end foreach

        foreach ($this->match as $match) {
            if (in_array($match, ['syn', 'ack', 'fin', 'rst', 'urg', 'psh', 'all', 'none']) === false) {
                throw new \Exception('Invalid match in flag');
            }//end if
        }//end foreach

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false && empty($this->match) === false) {
            $mask     = strtoupper(implode(',', $this->value));
            $match    = strtoupper(implode(',', $this->match));
            $content .= ' --tcp-flags '.$mask.' '.$match;
        }//end if

        return $content;

    }//end __toString()


}//end class
