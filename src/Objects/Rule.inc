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

    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (($this->parentNode->type ?? null) !== 'FIREWALL_LINE') {
            throw new \Exception('Rules can only exist under lines');
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = '/sbin/iptables -A '.strtoupper($this->value).$this->getOptions()."\n";

        return $content;

    }//end __toString()


}//end class
