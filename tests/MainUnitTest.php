<?php
namespace Firewall\Tests;


use \Firewall\BaseTest;
use \Firewall\Main;


class MainUnitTest extends BaseTest
{


    /**
     * Test for Main::getBaseDir.
     *
     * @return void
     */
    public function testGetBaseDir()
    {
        $this->assertSame(dirname(__DIR__), Main::getBaseDir());

    }//end testGetBaseDir()


    /**
     * Test for Main::getEngine.
     *
     * @return void
     */
    public function testGetEngine()
    {
        $engine = Main::getEngine();
        $this->assertSame(null, $engine);
        $this->assertFalse($engine instanceof \Firewall\AbstractEngine);
        $this->assertFalse($engine instanceof \Firewall\Engines\Iptables);

        $engine = Main::getEngine('iptables');
        $this->assertSame(null, $engine);
        $this->assertFalse($engine instanceof \Firewall\AbstractEngine);
        $this->assertFalse($engine instanceof \Firewall\Engines\Iptables);

        $engine = Main::getEngine('kwigybo');
        $this->assertSame(null, $engine);
        $this->assertFalse($engine instanceof \Firewall\AbstractEngine);
        $this->assertFalse($engine instanceof \Firewall\Engines\Iptables);

        $_SERVER['argv'][1] = __FILE__;
        Main::init();

        $engine = Main::getEngine();
        $this->assertNotSame(null, $engine);
        $this->assertTrue($engine instanceof \Firewall\AbstractEngine);
        $this->assertTrue($engine instanceof \Firewall\Engines\Iptables);

        $engine = Main::getEngine('iptables');
        $this->assertNotSame(null, $engine);
        $this->assertTrue($engine instanceof \Firewall\AbstractEngine);
        $this->assertTrue($engine instanceof \Firewall\Engines\Iptables);

        $engine = Main::getEngine('kwigybo');
        $this->assertSame(null, $engine);
        $this->assertFalse($engine instanceof \Firewall\AbstractEngine);
        $this->assertFalse($engine instanceof \Firewall\Engines\Iptables);

    }//end testGetEngine()


}//end class
