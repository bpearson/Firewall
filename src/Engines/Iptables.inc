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
        $options  = $this->_formatOptions($options);
        $command  = $this->command.' -F'.$options."\n";
        $command .= $this->command.' -X'.$options."\n";
        $command .= $this->command.' -Z'.$options."\n";

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
        $options = $this->_formatOptions($options);
        $command = $this->command.' -P '.strtoupper($value['value']).' '.strtoupper($value['policy']).$options."\n";

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

        $options = $this->_formatOptions($options);
        $command = $this->command.$ruleType.strtoupper($value).$options."\n";

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
        $options = $this->_formatOptions($options);
        $command = $this->command.' -N '.strtoupper($value).$options."\n";

        return $command;

    }//end userRule()


    /**
     * Format options.
     *
     * @param array $options The options.
     *
     * @return string
     */
    private function _formatOptions(array $options)
    {
        $optString = '';
        $required  = [];
        foreach ($options as $key => $option) {
            switch ($key) {
                case 'address':
                    $address   = ($option['address'] ?? null);
                    $direction = ($option['direction'] ?? null);
                    if (empty($address) === false) {
                        if ($direction === 'destination') {
                            $optString .= ' -d '.$address;

                            // Make sure protocol is set.
                            if (isset($required['protocol']) === false || $required['protocol'] !== false) {
                                $required['protocol'] = true;
                            }//end if
                        } else {
                            $optString .= ' -s '.$address;

                            // Make sure protocol is set.
                            if (isset($required['protocol']) === false || $required['protocol'] !== false) {
                                $required['protocol'] = true;
                            }//end if
                        }//end if
                    }//end if
                break;

                case 'comment':
                    $comment = ($option['comment'] ?? null);
                    if (empty($comment) === false) {
                        $optString .= ' -m comment --comment "'.$comment.'"';
                    }//end if
                break;

                case 'flag':
                    $mask  = ($option['mask'] ?? null);
                    $match = ($option['match'] ?? null);
                    if (empty($mask) === false && empty($match) === false) {
                        $mask       = strtoupper(implode(',', $mask));
                        $match      = strtoupper(implode(',', $match));
                        $optString .= ' --tcp-flags '.$mask.' '.$match;

                        // Make sure protocol is set.
                        if (isset($required['protocol']) === false || $required['protocol'] !== false) {
                            $required['protocol'] = true;
                        }//end if
                    }//end if
                break;

                case 'limit':
                    $limit = ($option['limit'] ?? null);
                    $unit  = ($option['unit'] ?? null);
                    if (empty($limit) === false && empty($unit) === false) {
                        $optString .= ' -m limit --limit '.$limit.'/'.$unit;
                    }//end if
                break;

                case 'network':
                    $device = ($option['device'] ?? null);
                    $in     = ($option['in'] ?? false);
                    $out    = ($option['out'] ?? false);
                    if (empty($device) === false) {
                        if ($in === true) {
                            $optString .= ' -i '.$device;
                        }//end if

                        if ($out === true) {
                            $optString .= ' -o '.$device;
                        }//end if
                    }//end if
                break;

                case 'port':
                    $ports     = ($option['port'] ?? []);
                    $direction = ($option['direction'] ?? null);
                    if (empty($ports) === false) {
                        $multiple = false;
                        $optPort  = '';
                        $ports    = array_filter($ports);
                        $ports    = implode(',', $ports);
                        if (strpos($ports, ':') !== false || strpos($ports, ',') !== false) {
                            $optString .= ' -m multiport ';
                            if ($direction === 'destination') {
                                $optString .= ' --dports '.$ports;
                            } else {
                                $optString .= ' --sports '.$ports;
                            }//end if
                        } else {
                            if ($direction === 'destination') {
                                $optString .= ' --dport '.$ports;
                            } else {
                                $optString .= ' --sport '.$ports;
                            }//end if
                        }//end if

                        // Make sure protocol is set.
                        if (isset($required['protocol']) === false || $required['protocol'] !== false) {
                            $required['protocol'] = true;
                        }//end if
                    }//end if
                break;

                case 'protocol':
                    $protocol = ($option['protocol'] ?? null);
                    if (empty($protocol) === false) {
                        $optString = ' -p '.$protocol.$optString;

                        // Protocol set.
                        $required['protocol'] = false;
                    }//end if
                break;

                case 'state':
                    $state = ($option['state'] ?? null);
                    if (empty($state) === false) {
                        $optString .= ' -m conntrack --ctstate '.strtoupper(implode(',', $state));
                    }//end if
                break;

                case 'table':
                    $table = ($option['table'] ?? null);
                    if (empty($table) === false && $table !== 'filter') {
                        $optString .= ' -t '.$table;
                    }//end if
                break;

                case 'target':
                    $target = ($option['target'] ?? null);
                    $prefix = ($option['prefix'] ?? '');
                    if (empty($target) === false) {
                        $optString .= ' -j '.strtoupper($target);
                        if ($target === 'log' && empty($prefix) === false) {
                            $optString .= ' --log-prefix "'.str_replace('"', '\'', $prefix).'"';
                        }//end if
                    }//end if
                break;

                default:
                    var_dump($key);
                    var_dump($option);
                break;
            }//end switch
        }//end foreach

        // Check for some requirements.
        foreach ($required as $key => $require) {
            if ($require === true) {
                switch ($key) {
                    case 'protocol':
                        // Always prepend protocol.
                        $optString = ' -p tcp'.$optString;
                    break;
                }//end switch
            }//end if
        }//end foreach

        return $optString;

    }//end _formatOptions()


}//end class
