<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;
use \Firewall\Main;


class Table extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_TABLE';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * Table.
     *
     * @var string
     */
    public $table = 'filter';


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

        $this->table = strtolower($value);

    }//end constructor


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (empty($this->table) === true) {
            throw new \Exception('Table cannot have an empty value');
        }//end if

        $engine = Main::getEngine();
        if ($engine !== null && in_array($this->table, $engine->tables) === false) {
            throw new \Exception(sprintf('Invalid table %s', $this->table));
        }//end if

        parent::validate();

    }//end validate()


    public function __toString()
    {
        $content = '';
        /**
        if ($this->table !== 'filter') {
            $content = ' -t '.$this->table;
        }//end if
        **/

        return $content;

    }//end __toString()


}//end class
