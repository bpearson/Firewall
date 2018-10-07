<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class InterfaceIn extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_INTERFACE_IN';

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


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false) {
            $content = ' -i '.$this->value;
        }//end if

        return $content;

    }//end __toString()


}//end class
