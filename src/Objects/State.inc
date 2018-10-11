<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class State extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_STATE';

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
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->value) === true) {
            throw new \Exception('State cannot have an empty value');
        }//end if

        foreach ($this->value as $value) {
            if (in_array($value, ['invalid', 'established', 'new', 'related', 'untracked']) === false) {
                throw new \Exception('Invalid state "'.$value.'"');
            }//end if
        }//end foreach

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = ' -m conntrack --ctstate '.strtoupper(implode(',', $this->value));

        return $content;

    }//end __toString()


}//end class
