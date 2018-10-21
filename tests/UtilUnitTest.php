<?php
namespace Firewall\Tests;


use \PHPUnit\Framework\TestCase;
use \Firewall\Util;


class UtilUnitTest extends TestCase
{


    /**
     * Test for Util::camelCase.
     *
     * @return void
     */
    public function testCamelCase()
    {
        // Valid Cases.
        $this->assertSame('Util', Util::camelCase('util'));
        $this->assertSame('Util', Util::camelCase('UTIL'));
        $this->assertSame('Util', Util::camelCase('Util'));
        $this->assertSame('Util', Util::camelCase('UtIl'));
        $this->assertSame('Util', Util::camelCase('uTiL'));
        $this->assertSame('UtilTest', Util::camelCase('util-test'));
        $this->assertSame('UtilTest', Util::camelCase('UTIL-test'));
        $this->assertSame('UtilTest', Util::camelCase('Util-test'));
        $this->assertSame('UtilTest', Util::camelCase('UtIl-test'));
        $this->assertSame('UtilTest', Util::camelCase('uTiL-test'));

    }//end testCamelCase()


    /**
     * Test for Util::stripNamespace.
     *
     * @return void
     */
    public function testStripNamespace()
    {
        // Valid Cases.
        $this->assertSame('Util', Util::stripNamespace('\Firewall\Util'));
        $this->assertSame('Util', Util::stripNamespace('\Firewall\Nested\Util'));
        $this->assertSame('Util', Util::stripNamespace('Util'));

        // Invalid Cases.
        $this->assertSame('', Util::stripNamespace('Util\\'));

    }//end testStripNamespace()


}//end class
