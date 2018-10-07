<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Policy extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_DEFAULT_POLICY';

    /**
     * Value.
     *
     * @var string
     */
    public $value = '';

    /**
     * Policy.
     *
     * @var string
     */
    public $policy = 'drop';


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false) {
            $options  = $this->getOptions();
            $content  = '/sbin/iptables -P '.strtoupper($this->value).' '.strtoupper($this->policy).$options."\n";
        }//end if

        return $content;

    }//end __toString()


}//end class
