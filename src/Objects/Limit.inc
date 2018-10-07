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
     * Value of the table.
     *
     * @var integer
     */
    public $value = 0;


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false) {
            $content = ' -m limit --limit '.$this->value.'/min';
        }//end if

        return $content;

    }//end __toString()


}//end class
