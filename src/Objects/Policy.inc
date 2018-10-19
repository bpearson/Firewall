<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;
use \Firewall\Main;


class Policy extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_DEFAULT_POLICY';

    /**
     * Chain.
     *
     * @var string
     */
    public $chain = '';

    /**
     * Policy.
     *
     * @var string
     */
    public $policy = 'drop';


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
            // Short cut policy.
            $value = ['chain' => $value];
        }//end if

        $this->chain  = strtolower(($value['chain'] ?? $this->chain));
        $this->policy = strtolower(($value['policy'] ?? $this->policy));

    }//end constructor


    public function __toString()
    {
        $content = '';
        $engine  = Main::getEngine();
        if ($engine !== null) {
            $options = $this->getOptions();
            $value   = [
                'value'  => $this->chain,
                'policy' => $this->policy,
            ];
            $content = $engine->policy($value, $options);
        }//end if

        return $content;

    }//end __toString()


}//end class
