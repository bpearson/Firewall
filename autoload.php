<?php

$rootDir = __DIR__;

include_once $rootDir.'/src/Main.inc';

// Core code.
foreach (glob($rootDir.'/src/*.inc') as $file) {
    $name = basename($file, '.inc');
    if ($name === 'Main') {
        continue;
    }//end if

    include_once $file;
}//end foreach

// Objects.
foreach (glob($rootDir.'/src/Objects/*.inc') as $file) {
    include_once $file;
}//end foreach

// Parsers.
foreach (glob($rootDir.'/src/Parsers/*.inc') as $file) {
    include_once $file;
}//end foreach
