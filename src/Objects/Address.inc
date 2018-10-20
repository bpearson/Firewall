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
     * The address to target.
     *
     * @var string
     */
    public $address = '';

    /**
     * Direction of the address.
     *
     * @var string
     */
    public $direction = 'destination';


    /**
     * Constructor.
     *
     * @param object $parent The parent node.
     * @param mixed  $value  The object value(s).
     *
     * @return void
     */
    public function __construct($parent, $value)
    {
        parent::__construct($parent, $value);

        if (is_array($value) === false) {
            // Shortcut single address.
            $value = ['address' => $value];
        }//end if

        $this->direction = strtolower(($value['direction'] ?? $this->direction));
        $this->address   = ($value['address'] ?? $this->address);

    }//end constructor


    public function __toString()
    {
        $content = '';
        /**
        if (empty($this->address) === false) {
            if ($this->hasOption('FIREWALL_PORT') === false && $this->hasOption('FIREWALL_PROTOCOL') === false) {
                // Port and Protocol not defined, so dummy up a protocol and automatically add it.
                $protocol = new Protocol(null);
                $content .= (string) $protocol;
            }//end if

            if ($this->direction === 'destination') {
                $content .= ' -d '.$this->address;
            } else {
                $content .= ' -s '.$this->address;
            }//end if
        }//end if
        **/

        return $content;

    }//end __toString()


}//end class
