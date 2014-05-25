<?php
session_start();
print_r($_SESSION);
$array = unserialize("../../private/passwd");
print_r($array);
echo $array;
?>
