<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;
use \Firewall\Main;


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
        $content = '';
        $engine  = Main::getEngine();
        if ($engine !== null) {
            $options = $this->getOptions();
            $content = $engine->userRule($this->value, $options);
        }//end if

        return $content;

    }//end __toString()


}//end class
