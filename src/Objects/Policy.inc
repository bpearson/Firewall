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
        $engine  = Main::getEngine();
        if ($engine !== null) {
            $options = $this->getOptions();
            $value   = [
                'value'  => $this->value,
                'policy' => $this->policy,
            ];
            $content = $engine->policy($value, $options);
        }//end if

        return $content;

    }//end __toString()


}//end class
