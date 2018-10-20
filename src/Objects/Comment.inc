<?php
namespace Firewall\Objects;


use \Firewall\AbstractObject;


class Comment extends AbstractObject
{

    /**
     * Type.
     *
     * @var string
     */
    public $type = 'FIREWALL_COMMENT';

    /**
     * Option.
     *
     * @var boolean
     */
    public $option = true;

    /**
     * The comment.
     *
     * @var string
     */
    public $comment = '';


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

        if (is_string($value) === false) {
            throw new \Exception('Invalid comment');
        }//end if

        $this->comment = $value;

    }//end constructor


    public function __toString()
    {
        $content = '';
        /**
        if (empty($this->comment) === false) {
            $content = ' -m comment --comment "'.$this->comment.'"';
        }//end if
        **/

        return $content;

    }//end __toString()


}//end class
