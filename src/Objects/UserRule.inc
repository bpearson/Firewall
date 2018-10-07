<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class UserRule extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_USER_RULE';

    /**
     * Value.
     *
     * @var string
     */
    public $value = null;


    public function __toString()
    {
        $options = $this->getOptions();
        $content = '/sbin/iptables -N '.strtoupper($this->value).$options."\n";

        return $content;

    }//end __toString()


}//end class
