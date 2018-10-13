<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Defaults extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_DEFAULTS';

    /**
     * The defaults.
     *
     * @var array
     */
    public $value = [];


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (($this->parentNode->type ?? null) !== 'FIREWALL_STATEMENT') {
            throw new \Exception('Defaults can only exist at the top');
        }//end if

        parent::validate();

    }//end validate()

    public function __toString()
    {
        $content = '';

        return $content;

    }//end __toString()


}//end class
