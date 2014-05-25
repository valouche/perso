<html>
	<head>
		<link rel="stylesheet" type="text/css" href="../styles/style.css" media="all" />
		<meta charset="utf-8">
	</head>
	<body>
<?php
session_start();
if (is_array($cart = $_SESSION['cart']) === FALSE)
	header("Location: ../index.php?msg=Votre%20panier%20est%20vide");
else
{
	$i = 1;
	$total = 0;
	echo '<table class="carttab" border="1">';
	echo "<tr><td>Numero</td><td>Nom</td><td>Quantite</td><td>Prix a l'unite</td><td>Prix total</td></tr>";
	foreach ($cart as $elem)
	{
		echo "<tr><td>$i</td><td>$elem[product]</td><td>$elem[qty]</td><td>$elem[price]</td><td style='text-align: right;'>".$elem['qty'] * $elem['price'].'€ </td><td><form method="post" action="del.php"><input type="submit" name="'.$elem['product'].'" value="Retirer du panier"></form></td></tr>';
		$total = $total + ($elem['price'] * $elem['qty']);
		$i++;
	}
	echo '<tr><td colspan="4" style="text-align: right">TOTAL</td><td style="text-align: right;">'.$total.'€</td></tr>';
	echo "</table>";
	echo '<br /><a href="order.php">Valider mon panier</a><br />';
	echo '<a href="../index.php">Retour</a>';
}
?>
	</body>
</html>
