<?php
mkdir("../private", 0775);
$data = array();
file_put_contents("../private/category", serialize($data));
file_put_contents("../private/shop", serialize($data));
file_put_contents("../private/orders", serialize($data));
chmod("../private/shop", 0775);
chmod("../private/category", 0775);
chmod("../private/orders", 0775);
$passwd[] = array("login" => "admin", "passwd" => hash("whirlpool", "root"), "isadmin" => 1);
file_put_contents("../private/passwd", serialize($passwd));
chmod("../private/passwd", 0775);
header("Location: index.php?msg=Installation%20Terminee!");
?>
