<?php
namespace Firewall;


use \PHPUnit\Framework\TestCase;


class BaseTest extends TestCase
{


    /**
     * Get a class property.
     *
     * @param mixed  $class The class to use.
     * @param string $name  The property name.
     *
     * @return mixed
     */
    public function getClassProperty($class, $name)
    {
        try {
            $value    = null;
            $refClass = new \ReflectionClass($class);
            if ($refClass->hasProperty($name) === true) {
                $refProp = $refClass->getProperty($name);
                if ($refProp->isPublic() === false) {
                    $refProp->setAccessible(TRUE);
                }

                if ($refProp->isStatic() === false && is_object($class) === true) {
                    $value = $refProp->getValue($class);
                } else {
                    $value = $refProp->getValue(null);
                }
            }//end if
        } catch (\ReflectionException $re) {
            $value = null;
        }//end try

        return $value;

    }//end getClassProperty()


    /**
     * Set a class property.
     *
     * @param mixed  $class The class to use.
     * @param string $name  The property name.
     * @param string $value The property value.
     *
     * @return boolean
     */
    public function setClassProperty($class, $name, $value)
    {
        try {
            $changed  = false;
            $refClass = new \ReflectionClass($class);
            if ($refClass->hasProperty($name) === true) {
                $refProp = $refClass->getProperty($name);
                if ($refProp->isPublic() === false) {
                    $refProp->setAccessible(true);
                }

                if ($refProp->isStatic() === false && is_object($class) === true) {
                    $refProp->setValue($class, $value);
                    $changed = true;
                } else {
                    $refProp->setValue(null, $value);
                    $changed = true;
                }
            }//end if
        } catch (\ReflectionException $re) {
            $changed = false;
        }//end try

        return $changed;

    }//end setClassProperty()


    /**
     * Run a class method.
     *
     * @param mixed  $class  The class to use.
     * @param string $method The class method.
     * @param array  $args   The args to pass to the method.
     *
     * @return mixed
     */
    public function runClassMethod($class, $method, $args=array())
    {
        try {
            $result   = false;
            $refClass = new \ReflectionClass($class);
            if ($refClass->hasMethod($method) === true) {
                $refMethod = $refClass->getMethod($method);
                if ($refMethod->isPublic() === false) {
                    $refMethod->setAccessible(true);
                }

                if ($refMethod->isStatic() === false && is_object($class) === true) {
                    $result = $refMethod->invokeArgs($class, $args);
                } else {
                    $result = $refMethod->invokeArgs(null, $args);
                }
            }//end if
        } catch (\ReflectionException $re) {
            $result = false;
        }//end try

        return $result;

    }//end runClassMethod()


}//end class
