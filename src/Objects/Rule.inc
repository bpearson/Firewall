<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;
use \Firewall\Main;


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
        $content = '';
        $engine  = Main::getEngine();
        if ($engine !== null) {
            $options = $this->getOptions();
            $content = $engine->rule($this->value, $options);
        }//end if

        return $content;

    }//end __toString()


}//end class
