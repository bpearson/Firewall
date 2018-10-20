<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;
use \Firewall\Main;


class Protocol extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_PROTOCOL';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Protocol.
     *
     * @var string
     */
    public $protocol = 'tcp';


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

        $this->protocol = strtolower($value);

    }//end constructor


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        $engine = Main::getEngine();
        if (empty($this->protocol) === true) {
            throw new \Exception('Protocol cannot have an empty value');
        } else if ($engine !== null && in_array($this->protocol, $engine->protocols) === false) {
            throw new \Exception(sprintf('Invalid protocol %s', $this->protocol));
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = '';
        /**
        if (empty($this->protocol) === false) {
            $content = ' -p '.$this->protocol;
        }//end if
        **/

        return $content;

    }//end __toString()


}//end class
