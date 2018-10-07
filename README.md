
# Firewall

## Summary

A simple way of building complex firewall rules by writing an abstract ruleset in YAML which will be converted to a BASH script.

## Usage

Generate the script by the following:

```sh
$ php scripts/build.php /path/to/firewall.yml > firewall.sh
```

## Example

A simple example can be found under simple.yml with the resulting script under simple.sh.

