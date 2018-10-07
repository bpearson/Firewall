<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Comment extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_COMMENT';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Value of the object.
     *
     * @var string
     */
    public $value = '';


    public function __toString()
    {
        $content = '';
        if (empty($this->value) === false) {
            $content = ' -m comment --comment "'.$this->value.'"';
        }//end if

        return $content;

    }//end __toString()


}//end class
