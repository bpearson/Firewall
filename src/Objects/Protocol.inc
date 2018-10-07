<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


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
     * Value of the table.
     *
     * @var string
     */
    public $value = 'tcp';


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false) {
            $content = ' -p '.$this->value;
        }//end if

        return $content;

    }//end __toString()


}//end class
