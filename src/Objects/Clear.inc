<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;
use \Firewall\Main;


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
        $content = '';
        $engine  = Main::getEngine();
        if ($engine !== null) {
            $options = $this->getOptions();
            $content = $engine->clear($options);
        }//end if

        return $content;

    }//end __toString()


}//end class
