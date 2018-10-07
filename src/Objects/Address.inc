<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Address extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_ADDRESS';

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
     * Direction of the address.
     *
     * @var string
     */
    public $direction = 'destination';


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false) {
            if ($this->hasOption('FIREWALL_PORT') === false && $this->hasOption('FIREWALL_PROTOCOL') === false) {
                // Port and Protocol not defined, so dummy up a protocol and automatically add it.
                $protocol = new Protocol(null);
                $content .= (string) $protocol;
            }//end if

            if ($this->direction === 'destination') {
                $content .= ' -d '.$this->value;
            } else {
                $content .= ' -s '.$this->value;
            }//end if
        }//end if

        return $content;

    }//end __toString()


}//end class
