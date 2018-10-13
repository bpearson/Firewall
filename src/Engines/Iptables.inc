<?php
namespace Firewall\Engines;

use \Firewall\AbstractEngine;

class Iptables extends AbstractEngine
{

    /**
     * Chains.
     *
     * @var array
     */
    public $chains = ['input', 'forward', 'output', 'prerouting', 'postrouting', 'notrack', 'secmark', 'connsecmark'];

    /**
     * The command.
     *
     * @var string
     */
    public $command = '/sbin/iptables';

    /**
     * Protocols.
     *
     * @var array
     */
    public $protocols = ['tcp', 'udp', 'udplite', 'icmp', 'icmpv6', 'esp', 'ah', 'sctp', 'mh', 'all'];

    /**
     * Tables.
     *
     * @var array
     */
    public $tables = ['filter', 'nat', 'mangle', 'raw', 'security'];

    /**
     * Types.
     *
     * @var array
     */
    public $types = ['append', 'insert', 'delete'];

    /**
     * Clear.
     *
     * @param array $options The options.
     *
     * @return string
     */
    public function clear(array $options=[])
    {
        $command  = $this->command.' -F'.implode('', $options)."\n";
        $command .= $this->command.' -X'.implode('', $options)."\n";
        $command .= $this->command.' -Z'.implode('', $options)."\n";

        return $command;

    }//end clear()


    /**
     * Policy.
     *
     * @param mixed $value   The value.
     * @param array $options The options.
     *
     * @return string
     */
    public function policy($value, array $options=[])
    {
        $command = $this->command.' -P '.strtoupper($value['value']).' '.strtoupper($value['policy']).implode('', $options)."\n";

        return $command;

    }//end policy()


    /**
     * Rule.
     *
     * @param mixed  $value   The value.
     * @param string $type    The rule type.
     * @param array  $options The options.
     *
     * @return string
     */
    public function rule($value, string $type, array $options=[])
    {
        switch($type) {
            case 'insert':
                $ruleType = ' -I ';
            break;

            case 'delete':
                $ruleType = ' -D ';
            break;

            case 'append':
            default:
                $ruleType = ' -A ';
            break;
        }//end switch

        $command = $this->command.$ruleType.strtoupper($value).implode('', $options)."\n";

        return $command;

    }//end rule()


    /**
     * User rule.
     *
     * @param mixed $value   The value.
     * @param array $options The options.
     *
     * @return string
     */
    public function userRule($value, array $options=[])
    {
        $command = $this->command.' -N '.strtoupper($value).implode('', $options)."\n";

        return $command;

    }//end userRule()


}//end class
