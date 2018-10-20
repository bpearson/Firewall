<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Limit extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_LIMIT';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Value of the limit.
     *
     * @var integer
     */
    public $limit = 0;

    /**
     * Unit of the limit.
     *
     * @var string
     */
    public $unit = 'second';


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
            // Shortcut single port.
            $value = ['limit' => $value];
        }//end if

        $this->limit = strtolower(($value['limit'] ?? $this->limit));
        $this->unit  = strtolower(($value['unit'] ?? $this->unit));

    }//end constructor


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->limit) === true) {
            throw new \Exception('Limit cannot have an empty value');
        }//end if

        if (in_array($this->unit, ['second', 'minute', 'hour', 'day']) === false) {
            throw new \Exception('Invalid unit set on limit');
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = '';
        //$content = ' -m limit --limit '.$this->limit.'/'.$this->unit;

        return $content;

    }//end __toString()


}//end class
