<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Line extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_LINE';


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (($this->parentNode->type ?? null) !== 'FIREWALL_LINES_LIST') {
            throw new \Exception('Line can only exist under Lines');
        }//end if

        parent::validate();

    }//end validate()


}//end class
