<?php

$rootDir = __DIR__;

include_once $rootDir.'/src/Main.inc';

// Composer.
if (file_exists(__DIR__.'/vendor/autoload.php') === true) {
    include_once __DIR__.'/vendor/autoload.php';
}//end if

// Core code.
foreach (glob($rootDir.'/src/*.inc') as $file) {
    $name = basename($file, '.inc');
    if ($name === 'Main') {
        continue;
    }//end if

    include_once $file;
}//end foreach

// Engines.
foreach (glob($rootDir.'/src/Engines/*.inc') as $file) {
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
