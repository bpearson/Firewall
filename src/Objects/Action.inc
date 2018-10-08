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


    /**
     * Validate.
     *
     * @return void
     * @throws \Exception When validation fails.
     */
    public function validate()
    {
        if (($this->parentNode->type ?? null) !== 'FIREWALL_ACTIONS_LIST') {
            throw new \Exception('Action can only exist under Actions');
        }//end if

        parent::validate();

    }//end validate()


    /**
     * Cast to string
     *
     * @return string
     */
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
