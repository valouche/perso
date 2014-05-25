<?PHP
session_start();
$name = array_search("Retirer du panier", $_POST);
$brk = 0;
foreach ($_SESSION['cart'] as $key => $value)
{
	foreach ($value as $key2 => $el)
	{
		if ($el['product'] == $name)
		{
			$brk = 1;
			break ;
		}
		if ($brk == 1)
			break ;
	}
} 
unset($_SESSION['cart'][$key]);
header("Location: cart.php");
?>
