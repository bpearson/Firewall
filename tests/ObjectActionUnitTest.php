<?php
namespace Firewall\Tests;


use \Firewall\BaseTest;
use \Firewall\Main;
use \Firewall\Objects;


class ObjectActionUnitTest extends BaseTest
{


    /**
     * Test for objects.
     *
     * @return void
     */
    public function testCast()
    {
        $object = new Objects\Action(null, '');
        $this->assertSame("# Action: \n)\n;;\n", (string) $object);

        $object = new Objects\Action(null, '');
        $object->name = 'test';
        $this->assertSame("# Action: test\ntest)\n;;\n", (string) $object);

        // TODO Do with a child or two.

    }//end testCast()


    /**
     * Test for objects.
     *
     * @return void
     */
    public function testType()
    {
        $object = new Objects\Action(null, '');
        $this->assertSame('FIREWALL_ACTION', $object->type);

    }//end testType()


    /**
     * Test for objects.
     *
     * @return void
     */
    public function testValidate()
    {
        $parent = new Objects\Actions(null, '');
        $object = new Objects\Action($parent, '');

        try {
            $exception = false;
            $object->validate();
        } catch (\Exception $e) {
            $exception = true;
        }

        $this->assertFalse($exception);

        $parent = new Objects\Base('');
        $object = new Objects\Action($parent, '');

        try {
            $exception = false;
            $object->validate();
        } catch (\Exception $e) {
            $exception = true;
        }

        $this->assertTrue($exception);

    }//end testValidate()


}//end class
