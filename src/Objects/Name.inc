<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Name extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_NAME';


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

        if (is_string($value) === false) {
            throw new \Exception('Invalid name');
        }//end if

        $this->name = $value;
        if (in_array($this->parentNode->type, ['FIREWALL_STATEMENT', 'FIREWALL_ACTION']) === true) {
            // Automatically populate up when needed.
            $this->parentNode->setName($value);
        }//end if

    }//end constructor


    public function __toString()
    {
        $content = '';

        return $content;

    }//end __toString()


}//end class
