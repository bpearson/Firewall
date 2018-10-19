<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Target extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_TARGET';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Target.
     *
     * @var string
     */
    public $target = 'drop';

    /**
     * Log prefix.
     *
     * @var string
     */
    public $prefix = '';


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
            $value = ['target' => $value];
        }//end if

        $this->target = strtolower(($value['target'] ?? $this->target));
        $this->prefix = ($value['prefix'] ?? $this->prefix);

    }//end constructor


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->target) === true) {
            throw new \Exception('Target cannot have an empty value');
        }//end if

        if ($this->target !== 'log' && empty($this->prefix) === false) {
            throw new \Exception('Prefix can only used with LOG target');
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = ' -j '.strtoupper($this->target);
        if ($this->target === 'log' && empty($this->prefix) === false) {
            $content .= ' --log-prefix "'.$this->prefix.'"';
        }//end if

        return $content;

    }//end __toString()


}//end class
