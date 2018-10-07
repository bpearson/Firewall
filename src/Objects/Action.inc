<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Action extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_ACTION';


    public function __toString()
    {
        $content  = '# Action: '.$this->name."\n";
        $content .= $this->name.')'."\n";
        foreach($this->children as $child)
        {
            $content .= (string) $child;

        }//end foreach

        $content .= ';;'."\n";

        return $content;

    }//end __toString()


}//end class
