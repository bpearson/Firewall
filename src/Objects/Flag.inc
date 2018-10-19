<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Flag extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_FLAG';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * The flag mask.
     *
     * @var array
     */
    public $mask = [];

    /**
     * The flag match.
     *
     * @var array
     */
    public $match = [];


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
            throw new \Exception('Invalid value passed to flag');
        }//end if

        $this->mask  = explode(',', strtolower(($value['mask'] ?? $this->mask)));
        $this->match = explode(',', strtolower(($value['match'] ?? $this->match)));

    }//end constructor


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->mask) === true) {
            throw new \Exception('Flag cannot have an empty value');
        }//end if

        if (empty($this->match) === true) {
            throw new \Exception('Flag cannot have an empty match');
        }//end if

        foreach ($this->mask as $value) {
            if (in_array($value, ['syn', 'ack', 'fin', 'rst', 'urg', 'psh', 'all', 'none']) === false) {
                throw new \Exception('Invalid value in flag');
            }//end if
        }//end foreach

        foreach ($this->match as $match) {
            if (in_array($match, ['syn', 'ack', 'fin', 'rst', 'urg', 'psh', 'all', 'none']) === false) {
                throw new \Exception('Invalid match in flag');
            }//end if
        }//end foreach

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = '';
        if (empty($this->mask) === false && empty($this->match) === false) {
            $mask     = strtoupper(implode(',', $this->mask));
            $match    = strtoupper(implode(',', $this->match));
            $content .= ' --tcp-flags '.$mask.' '.$match;
        }//end if

        return $content;

    }//end __toString()


}//end class
