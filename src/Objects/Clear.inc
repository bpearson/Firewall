<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Clear extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_CLEAR';


    public function __toString()
    {
        $content  = '/sbin/iptables -F'.$this->getOptions()."\n";
        $content .= '/sbin/iptables -X'.$this->getOptions()."\n";
        $content .= '/sbin/iptables -Z'.$this->getOptions()."\n";

        return $content;

    }//end __toString()


}//end class
