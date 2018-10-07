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


    public function __toString()
    {
        $content = ' -j '.strtoupper($this->value);

        return $content;

    }//end __toString()


}//end class
