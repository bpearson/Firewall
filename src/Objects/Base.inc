<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Base extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_STATEMENT';

    /**
     * Source file.
     *
     * @var string
     */
    public $file = null;


    /**
     * Constructor.
     *
     * @param string $path The path to source file.
     *
     * @return void
     */
    public function __construct(string $path)
    {
        $this->file = $path;

    }//end constructor


    public function __toString()
    {
        $content  = '#!/bin/bash'."\n";
        $content .= '#'."\n";
        $content .= '# Firewall: '.$this->name."\n";
        $content .= '#'."\n";
        $service  = false;
        foreach($this->children as $child)
        {
            if ($service === false && $child instanceof \Firewall\Objects\Actions) {
                $service  = true;
                $content .= 'case "$1" in'."\n";
            }//end if

            $content .= (string) $child;
        }//end foreach

        if ($service === true) {
            $content .= '*)'."\n";
            $content .= 'echo "Invalid"'."\n";
            $content .= 'exit 1'."\n";
            $content .= ';;'."\n";
            $content .= 'esac'."\n";
        }//end if

        return $content;

    }//end __toString()


}//end class
