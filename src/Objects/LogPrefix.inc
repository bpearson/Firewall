<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class LogPrefix extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_LOG_PREFIX';

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
        $content = ' --log-prefix "'.$this->value.'"';

        return $content;

    }//end __toString()


}//end class
