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
     * Chain of the rule.
     *
     * @var string
     */
    public $chain = 'input';

    /**
     * Type of rule.
     *
     * @var string
     */
    public $rule = 'append';


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

        if (is_string($value) === true) {
            $value = ['chain' => $value];
        }//end if

        $this->chain = strtolower(($value['chain'] ?? $this->chain));
        $this->rule  = strtolower(($value['rule'] ?? $this->rule));

    }//end constructor


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

        if (empty($this->chain) === true) {
            throw new \Exception('Rule value cannot be empty');
        }//end if

        $engine = Main::getEngine();
        if ($engine !== null && in_array($this->rule, $engine->types) === false) {
            throw new \Exception(sprintf('Rule type cannot be %s', $this->rule));
        }//end if

        parent::validate();

    }//end validate()


    /**
     * Cast to string
     *
     * @return string
     */
    public function __toString()
    {
        $content = '';
        $engine  = Main::getEngine();
        if ($engine !== null) {
            $options = $this->getOptions();
            $content = $engine->rule($this->chain, $this->rule, $options);
        }//end if

        return $content;

    }//end __toString()


}//end class
