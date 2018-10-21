<?php
namespace Firewall\Tests;


use \Firewall\BaseTest;
use \Firewall\Main;
use \Firewall\Util;


class SimpleUnitTest extends BaseTest
{


    /**
     * Test for Main::build().
     *
     * @return void
     */
    public function testSimple()
    {
        ob_start();
            $_SERVER['argv'] = [1 => Main::getBaseDir().'/simple.yml'];
            Main::init();
            Main::build();
            $tested = ob_get_contents();
        ob_end_clean();

        $this->assertSame(file_get_contents(Main::getBaseDir().'/simple.sh'), $tested);

    }//end testSimple()


}//end class
