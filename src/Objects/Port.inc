<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Port extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_PORT';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Value of the object.
     *
     * @var string
     */
    public $value = '';

    /**
     * Direction of the port.
     *
     * @var string
     */
    public $direction = 'destination';


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false) {
            if ($this->hasOption('FIREWALL_PROTOCOL') === false) {
                // Protocol not defined, so dummy up a protocol and automatically add it.
                $protocol = new Protocol(null);
                $content .= (string) $protocol;
            }//end if

            if (strpos($this->value, ':') !== false || strpos($this->value, ',') !== false) {
                // Multiple ports.
                $content .= ' -m multiport';
                if ($this->direction === 'destination') {
                    $content .= ' --dports '.$this->value;
                } else {
                    $content .= ' --sports '.$this->value;
                }//end if
            } else {
                // Single port.
                if ($this->direction === 'destination') {
                    $content .= ' --dport '.$this->value;
                } else {
                    $content .= ' --sport '.$this->value;
                }//end if
            }//end if
        }//end if

        return $content;

    }//end __toString()


}//end class
