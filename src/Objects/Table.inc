<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


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


    public function __toString()
    {
        $content = '';
        if ($this->value !== 'filter') {
            $content = ' -t '.$this->value;
        }//end if

        return $content;

    }//end __toString()


}//end class
