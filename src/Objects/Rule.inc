<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Rule extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_RULE';

    /**
     * Value of the rule.
     *
     * @var string
     */
    public $value = 'input';


    public function __toString()
    {
        $content = '/sbin/iptables -A '.strtoupper($this->value).$this->getOptions()."\n";

        return $content;

    }//end __toString()


}//end class
