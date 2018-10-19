<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class State extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_STATE';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * State.
     *
     * @var array
     */
    public $state = [];


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

        if (is_array($value) === true) {
            $value = implode(',', $value);
        }//end if

        $this->state = explode(',', strtolower($value));

    }//end constructor


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->state) === true) {
            throw new \Exception('State cannot have an empty value');
        }//end if

        foreach ($this->state as $state) {
            if (in_array($state, ['invalid', 'established', 'new', 'related', 'untracked']) === false) {
                throw new \Exception('Invalid state "'.$state.'"');
            }//end if
        }//end foreach

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = ' -m conntrack --ctstate '.strtoupper(implode(',', $this->state));

        return $content;

    }//end __toString()


}//end class
