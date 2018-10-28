<?php
namespace Firewall;


class Main
{

    /**
     * The default engine.
     *
     * @var string
     */
    private static $_engine = null;

    /**
     * Engines.
     *
     * @var array
     */
    private static $_engines = [];

    /**
     * The file.
     *
     * @var string
     */
    private static $_file = null;


    /**
     * Build the firewall script.
     *
     * @return void
     */
    public static function build()
    {
        $firewall = Yaml::parseFile(self::$_file);
        Main::validate($firewall);

        echo (string) $firewall."\n";

    }//end build()


    /**
     * Return the base dir.
     *
     * @return string
     */
    public static function getBaseDir()
    {
        return dirname(__DIR__);

    }//end getBaseDir()


    /**
     * Return a firewall engine.
     *
     * @param mixed $engine Override the default engine.
     *
     * @return object|null
     */
    public static function getEngine($engine=null)
    {
        if ($engine === null) {
            $engine = self::$_engine;
        }//end if

        $fwEngine = (self::$_engines[$engine] ?? null);

        return $fwEngine;

    }//end getEngine()


    /**
     * Initialise.
     *
     * @return void
     * @throws Exception If no file was passed in.
     */
    public static function init()
    {
        self::$_file = ($_SERVER['argv'][1] ?? null);
        if (self::$_file === null || file_exists(self::$_file) === false) {
            throw new \Exception('No file passed in');
        }//end if

        // Start engines.
        self::$_engine = 'iptables';
        foreach (glob(__DIR__.'/Engines/*.inc') as $engineFile) {
            $name  = basename($engineFile, '.inc');
            $class = '\\Firewall\\Engines\\'.$name;

            self::$_engines[strtolower($name)] = new $class();
        }//end foreach

        if (isset(self::$_engines[self::$_engine]) === false) {
            throw new \Exception(sprintf('Missing firewall engine (%s)', self::$_engine));
        }//end if

    }//end init()


    /**
     * Validate the firewall object.
     *
     * @param object $firewall The firewall object.
     *
     * @return void
     * @throws Exception When validation fails.
     */
    public static function validate($firewall)
    {
        $firewall->validate();
        foreach ($firewall->children as $child) {
            Main::validate($child);
        }//end foreach

    }//end validate()


}//end class
