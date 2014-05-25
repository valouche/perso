<?php
session_start();
if (!$_SESSION['loggued_on_user'])
{
    header("Location: ../index.php?msg=Veuillez%20vous%20connecter%20pour%20valider%20votre%20panier");
    exit ;
}
if (!$_SESSION['cart'])
{
	header("Location: ../index.php?msg=Panier%20vide");
	exit;
}
$data = unserialize(file_get_contents("../../private/orders"));
$cart = $_SESSION['cart'];
$data[] = array("login" => $_SESSION['loggued_on_user'], "log_order" => $cart);  
file_put_contents("../../private/orders", serialize($data));
header("Location: ../index.php?msg=Merci!%20Commande%20validee!");
?>
