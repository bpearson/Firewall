<?php
namespace Firewall;


abstract class AbstractEngine
{

    /**
     * The command.
     *
     * @var string
     */
    public $command = null;

    /**
     * Clear.
     *
     * @param array $options The options.
     *
     * @return string
     */
    abstract public function clear(array $options=[]);


    /**
     * Policy.
     *
     * @param mixed $value   The value.
     * @param array $options The options.
     *
     * @return string
     */
    abstract public function policy($value, array $options=[]);


    /**
     * Rule.
     *
     * @param mixed $value   The value.
     * @param array $options The options.
     *
     * @return string
     */
    abstract public function rule($value, array $options=[]);


    /**
     * User rule.
     *
     * @param mixed $value   The value.
     * @param array $options The options.
     *
     * @return string
     */
    abstract public function userRule($value, array $options=[]);


}//end class
