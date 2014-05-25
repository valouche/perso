<?PHP
session_start();
$name = array_search("Ajouter au panier", $_POST);
foreach ($_SESSION['cart'] as $key => &$el)
{
	foreach ($el as $value)
	  {
		if ($name == $value)
		{	
			$el['qty'] = $el['qty'] + $_POST['qty'];
			header("Location: ../index.php?msg=Article%20ajoute%20au%20panier");
			exit;
		}
	  }
}
$_SESSION['cart'][] = array("product" => $name, "qty" => $_POST['qty'], "price" => $_POST['price']);
header("Location: ../index.php?msg=Article%20ajoute%20au%20panier");
?>
