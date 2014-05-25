<?php session_start(); ?>
<html>
    <head>
		<link rel="stylesheet" type="text/css" href="styles/style.css" media="all" />
		<meta charset="utf-8">
    </head>
    <body>
	<div id="header" class="transparent">
		<div id="account" class="transparent">
			<span class="center"><h4>Mon compte</h4></span>
			<span id="loguser">
			<?php if ($_SESSION['loggued_on_user'] != ""){
			echo "Connecte en tant que: <b>".$_SESSION['loggued_on_user']."</b><br />";?>
			</span>
			<a class="headerinf" href="accounts/modif_form.php">Modifier mon mot de passe</a><br />
			<a class="headerinf" href="accounts/logout.php">Se deconnecter</a><br />
			<?php }?>
			<?php if (!isset($_SESSION['loggued_on_user']) || ($_SESSION['loggued_on_user'] == "")) { ?>
			<a class="headerinf" href="accounts/login.html">Se connecter</a><br />
			<a class="headerinf" href="accounts/create.html">Creer un compte</a>
			<?php }?>
		</div>
		<div id="msgbox" class="transparent">
			<span class="center"><h4>Message Box</h4></span>
			<span id="msgtxt"><?php echo $_GET['msg']."<br />";?></span>
		</div>
		<div id="basket" class="transparent">
			<span class="center"><h4>Mon panier</h4></span>
			<?php if (isset($_SESSION['cart']) && $_SESSION['cart'] != "") { ?>
			<span id="b_art">Il y a <?php $i = 0; foreach ($_SESSION['cart'] as $elem)	$i++; echo $i; ?> articles dans le panier</span>
			<a class="headerinf" href="cart/cart.php">Voir mon panier</a><br />
			<a class="headerinf" href="cart/order.php">Valider mon panier</a>
			<?php } else { ?>
			<span id="cart_empty">Votre panier est vide</span>
			<?php } ?>
	    </div>
	</div>
	<div id="content" class="transparent">
<?php
$data = unserialize(file_get_contents("../private/shop"));
if (is_array($data) === FALSE)
	echo "Aucun article dans la boutique\n";
else
{
	echo "<table>\n";
	echo "<tr>\n";
	echo '<td class="title">Nom</td>';
	echo '<td class="title">Description</td>';
	echo '<td class="title">Categories</td>';
	echo '<td class="title">Prix</td>';
	echo '<td class="title"><br /></td>';
	foreach ($data as $elem)
	{
		echo "<tr>\n";
		echo '<td class="name">'.$elem['name']."</td>\n";
		echo '<td class="desc">'.$elem['desc']."</td>\n";
		echo '<td class="cat">';
		foreach ($elem['categories'] as $cat)
			echo $cat.", ";
		echo '</td>'."\n";
		echo '<td class="price">'.$elem['price']."€</td>\n";
		echo '<td class="add_to_cart"><form method="post" action="./cart/add.php"><input class="qty" type="number" name="qty" value="1" min="1"><input type="hidden" name="price" value="'.$elem['price'].'"><input type="submit" name="'.$elem['name'].'" value="Ajouter au panier"></form></td>';
		echo "</tr>\n";
	}
	echo "</table>\n";
}
?>
	</div>
<?php if ($_SESSION['isadmin'] == 1) { ?>
	<div id="footer" class="transparent">
		<div id="adm_shop">
			<a class="footerinf" href="shop/create.html" >Ajouter un article</a><br />
			<a class="footerinf" href="shop/create_c.html" >Ajouter une categorie</a><br />
			<a class="footerinf" href="shop/modif.html" >Modifier un article / une categorie</a><br />
			<a class="footerinf" href="shop/delete.html" >Supprimer un article / une categorie</a><br />
		</div>
		<div id="adm_users">
			<a class="footerinf" href="accounts/create.html" >Ajouter un utilisateur</a><br />
			<a class="footerinf" href="accounts/modif_form.php" >Modifier le mot de passe d'un utilisateur</a><br />
			<a class="footerinf" href="accounts/delete.html" >Supprimer un utilisateur</a>
		</div>
		<div id="adm_orders">
			<a class="footerinf" href="admin/orders.php" >Voir les commandes</a>
		</div>
	</div>
<?php }?>
    </body>
</html>
