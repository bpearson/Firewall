<?php
namespace Firewall;


class AbstractObject
{

    /**
     * Name.
     *
     * @var string
     */
    public $name = null;

    /**
     * Type.
     *
     * @var string
     */
    public $type = null;

    /**
     * If true, this is an option node.
     *
     * @var boolean
     */
    public $option = false;


    /**
     * Child storage.
     *
     * @var array
     */
    public $children = [];

    /**
     * Parent node.
     *
     * @var object
     */
    public $parentNode = null;


    /**
     * Constructor.
     *
     * @param object $parent The parent node.
     *
     * @return void
     */
    public function __construct($parent)
    {
        $this->parentNode = $parent;
        if ($this->type === null) {
            throw new \Exception('Invalid type');
        }//end if

    }//end constructor


    public function __toString()
    {
        $content  = '';
        foreach($this->children as $child) {
            if ($child->option === false) {
                $content .= (string) $child;
            }//end if
        }//end foreach

        return $content;

    }//end __toString()


    /**
     * Get the options for a line.
     *
     * @return string
     */
    public function getOptions()
    {
        $options = '';
        if ($this->parentNode !== null && $this->parentNode->type === 'FIREWALL_LINE') {
            // TODO: Does it need to go higher than 1?
            foreach ($this->parentNode->children as $child) {
                if ($child->option === true) {
                    if ($child->type === 'FIREWALL_PROTOCOL') {
                        // Hardcode protocol to be the first.
                        $options = (string) $child.$options;
                    } else {
                        $options .= (string) $child;
                    }//end if
                }//end if
            }//end foreach
        }//end if

        return $options;

    }//end getOptions()


    /**
     * Returns true, if a line has a particular option.
     *
     * @param string $option The option to search for.
     *
     * @return boolean
     */
    public function hasOption($option)
    {
        $hasOption = false;
        if ($this->parentNode !== null && $this->parentNode->type === 'FIREWALL_LINE') {
            // TODO: Does it need to go higher than 1?
            foreach ($this->parentNode->children as $child) {
                if ($child->type === $option) {
                    $hasOption = true;
                    break;
                }//end if
            }//end foreach
        }//end if

        return $hasOption;

    }//end hasOption()


    /**
     * Set a name.
     *
     * @param string $name The name to set.
     *
     * @return void
     */
    public function setName($name)
    {
        $this->name = $name;

    }//end setName()


    public function find($type, $depth=-1)
    {
        if (is_array($type) === false) {
            $type = [$type];
        }//end if

        $nodes = [];
        if ($options['started'] === true && in_array($this->type, $type) === true) {
            $nodes[] = $this;
        }//end if

        if (($depth === -1 || $depth > 0) && isset($this->children) === true) {
            if ($depth > 0) {
                $depth--;
            }//end if

            foreach ($this->children as $index => $child) {
                if ($child instanceof \Firewall\AbstractObject) {
                    $nodes = array_merge($nodes, $child->find($type, $depth, $options));
                }//end if
            }//end foreach
        }//end if

        return $nodes;

    }//end find()


    public function findChild($type)
    {
        if (is_array($type) === false) {
            $type = [$type];
        }//end if

        $nodes = [];
        if (isset($this->children) === true) {
            foreach ($this->children as $index => $child) {
                if ($child instanceof \Firewall\AbstractObject && in_array($child->type, $type) === true) {
                    $nodes[] = $child;
                }//end if
            }//end foreach
        }//end if

        return $nodes;

    }//end findChild()


    public function findParent($type, $depth=-1)
    {
        if (is_array($type) === false) {
            $type = [$type];
        }//end if

        $nodes = [];
        if (in_array($this->type, $type) === true) {
            // Self reference.
            $nodes[] = $this;
        }//end if

        if (($depth === -1 || $depth > 0)
            && isset($this->parentNode) === true
            && $this->parentNode instanceof \Firewall\AbstractObject
        ) {
            if ($depth > 0) {
                $depth--;
            }//end if

            $nodes = array_merge($nodes, $this->parentNode->findParent($type, $depth));
        }//end if

        return $nodes;

    }//end findParent()


    public function findParentSibling($type, $depth=-1)
    {
        if (is_array($type) === false) {
            $type = [$type];
        }//end if

        $nodes = [];
        if (in_array($this->type, $type) === true) {
            // Self reference.
            $nodes[] = $this;
        }//end if

        if (($depth === -1 || $depth > 0)
            && isset($this->parentNode) === true
            && $this->parentNode instanceof \Firewall\AbstractObject
        ) {
            if ($depth > 0) {
                $depth--;
            }//end if

            foreach ($this->parentNode->children as $child) {
                if ($child === $this) {
                    break;
                } else if ($child !== $this) {
                    if (in_array($child->type, $type) === true) {
                        $nodes[] = $child;
                    }//end if
                }//end if
            }//end foreach

            $nodes = array_merge($nodes, $this->parentNode->findParentSibling($type, $depth));
        }//end if

        return $nodes;

    }//end findParentSibling()


    public function findSibling($type, $depth=-1)
    {
        if (is_array($type) === false) {
            $type = [$type];
        }//end if

        $nodes = [];
        if (in_array($this->type, $type) === true) {
            // Self reference.
            $nodes[] = $this;
        }//end if

        if (($depth === -1 || $depth > 0)
            && isset($this->parentNode) === true
            && $this->parentNode instanceof \Firewall\AbstractObject
        ) {
            if ($depth > 0) {
                $depth--;
            }//end if

            $started = false;
            foreach ($this->parentNode->children as $key => $child) {
                if ($started === true || $child === $this) {
                    $nodes   = array_merge($nodes, $child->find($type, $depth));
                    $started = true;
                }//end if
            }//end foreach
        }//end if

        return $nodes;

    }//end findSibling()


    public function findTopLevel()
    {
        $top   = null;
        $stmts = $this->findParent(['FIREWALL_STATEMENT']);
        $stmts = array_reverse($stmts);
        foreach ($stmts as $stmt) {
            if ($stmt->parentNode === null) {
                $top = $stmt;
                break;
            }//end if
        }//end foreach

        return $top;

    }//end findTopLevel()


}//end class