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
     * Port number.
     *
     * @var string
     */
    public $port = '';

    /**
     * Direction of the port.
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
            $value = ['port' => [$value]];
        } else if (is_array($value) === true && isset($value[0]) === true) {
            $value = ['port' => $value];
        } else if (is_array($value) === true && isset($value['port']) === true && is_array($value['port']) === false) {
            $value['port'] = [$value['port']];
        }//end if

        $this->direction = strtolower(($value['direction'] ?? $this->direction));
        $this->port      = ($value['port'] ?? $this->port);

    }//end constructor


    public function __toString()
    {
        $content = '';
        /**
        if (empty($this->port) === false) {
            if ($this->hasOption('FIREWALL_PROTOCOL') === false) {
                // Protocol not defined, so dummy up a protocol and automatically add it.
                $protocol = new Protocol(null, 'tcp');
                $content .= (string) $protocol;
            }//end if

            foreach ($this->port as $port) {
                if (empty($port) === true) {
                    continue;
                }//end if

                if (strpos($port, ':') !== false || strpos($port, ',') !== false) {
                    // Multiple ports.
                    $content .= ' -m multiport';
                    if ($this->direction === 'destination') {
                        $content .= ' --dports '.$port;
                    } else {
                        $content .= ' --sports '.$port;
                    }//end if
                } else {
                    // Single port.
                    if ($this->direction === 'destination') {
                        $content .= ' --dport '.$port;
                    } else {
                        $content .= ' --sport '.$port;
                    }//end if
                }//end if
            }//end foreach
        }//end if
        **/

        return $content;

    }//end __toString()


}//end class
