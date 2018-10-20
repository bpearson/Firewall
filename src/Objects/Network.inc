<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Network extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_NETWORK_INTERFACE';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * The network device target.
     *
     * @var string
     */
    public $device = '';

    /**
     * If true, use as input.
     *
     * @var boolean
     */
    public $in = false;

    /**
     * If true, use as output.
     *
     * @var boolean
     */
    public $out = false;


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
            $value = ['device' => $value];
        }//end if

        $this->device = ($value['device'] ?? $this->device);
        $this->in     = ($value['in'] ?? $this->in);
        $this->out    = ($value['out'] ?? $this->out);

    }//end constructor


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        parent::validate();

        if (empty($this->device) === true) {
            throw new \Exception('Network cannot have an empty value');
        }//end if

    }//end validate()


    public function __toString()
    {
        $content = '';
        /**
        if (empty($this->device) === false) {
            if ($this->in === true) {
                $content = ' -i '.$this->device;
            }//end if

            if ($this->out === true) {
                $content = ' -o '.$this->device;
            }//end if
        }//end if
        **/

        return $content;

    }//end __toString()


}//end class
