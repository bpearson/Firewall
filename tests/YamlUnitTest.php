<?php
namespace Firewall\Tests;


use \Firewall\BaseTest;
use \Firewall\Yaml;


class YamlUnitTest extends BaseTest
{


    /**
     * Test for Yaml::_set.
     *
     * @return void
     */
    public function testSet()
    {
        $file = __FILE__;
        $this->assertSame([], $this->getClassProperty('\\Firewall\\Yaml', '_current'));
        $this->runClassMethod('\\Firewall\\Yaml', '_set', [$file]);
        $this->assertSame([1=>$file], $this->getClassProperty('\\Firewall\\Yaml', '_current'));

    }//end testSet()


}//end class
