<html>	
	<head>
		<link rel="stylesheet" type="text/css" href="../styles/style.css" media="all" />
	</head>
	<body>
<?php
$data = array_values(array_filter(unserialize(file_get_contents("../../private/orders"))));
foreach ($data as $key => $order)
{
	$i = 0;
	echo '<table border="1">';
	echo "<tr><td style='font-weight: bold;'>Commande de $order[login]</td><td>Nom de l'article</td><td>Quantite</td><td>Prix a l'unite en euros</td><td>Prix total en euros</td></tr>";
	$login = $order[login];
	foreach ($order['log_order'] as $art)
	{
		echo "<tr><td>Produit no.$i</td><td>";
		echo "$art[product]</td><td>";
		echo "$art[qty]</td><td>";
		echo "$art[price]</td><td>";
		echo $art['price'] * $art['qty']."</td></tr>";
		$total = $total + ($art['price'] * $art['qty']);
		$i++;
	}
	echo "<tr><td colspan=4 style='text-align: right;'>TOTAL</td><td>$total</td></tr>";
	echo "</table>";
}
?>
		<br /><a href="../">Retour accueil</a><br />
	</body>
</html>
