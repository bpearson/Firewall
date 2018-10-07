<?php

$rootDir = dirname(__DIR__);

require_once $rootDir.'/autoload.php';

try {
    \Firewall\Main::init();
    \Firewall\Main::build();
} catch (\Exception $e) {
    var_dump('ERROR: '.$e->getMessage());
    exit(1);
}//end try-catch

exit(0);
