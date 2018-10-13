<?php
namespace Firewall;


abstract class AbstractEngine
{

    /**
     * Chains.
     *
     * @var array
     */
    public $chains = [];

    /**
     * The command.
     *
     * @var string
     */
    public $command = null;

    /**
     * Protocols.
     *
     * @var array
     */
    public $protocols = [];

    /**
     * Tables.
     *
     * @var array
     */
    public $tables = [];

    /**
     * Types.
     *
     * @var array
     */
    public $types = [];

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
     * @param mixed  $value   The value.
     * @param string $type    The rule type.
     * @param array  $options The options.
     *
     * @return string
     */
    abstract public function rule($value, string $type, array $options=[]);


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
