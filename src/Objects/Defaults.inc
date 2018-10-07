<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Defaults extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_DEFAULTS';

    /**
     * The defaults.
     *
     * @var array
     */
    public $value = [];


    public function __toString()
    {
        $content = '';

        return $content;

    }//end __toString()


}//end class
