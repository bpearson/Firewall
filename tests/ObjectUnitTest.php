<?php
namespace Firewall\Tests;


use \Firewall\BaseTest;
use \Firewall\Main;
use \Firewall\Objects;


class ObjectUnitTest extends BaseTest
{


    /**
     * Test for objects.
     *
     * @return void
     */
    public function testObjectActionCast()
    {
        $object = new Objects\Action(null, '');
        $this->assertSame("# Action: \n)\n;;\n", (string) $object);

        $object = new Objects\Action(null, '');
        $object->name = 'test';
        $this->assertSame("# Action: test\ntest)\n;;\n", (string) $object);

        // TODO Do with a child or two.

    }//end testObjectActionCast()


    /**
     * Test for objects.
     *
     * @return void
     */
    public function testObjectActionType()
    {
        $object = new Objects\Action(null, '');
        $this->assertSame('FIREWALL_ACTION', $object->type);

    }//end testObjectActionType()


    /**
     * Test for objects.
     *
     * @return void
     */
    public function testObjectActionValidate()
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

    }//end testObjectActionValidate()


}//end class
