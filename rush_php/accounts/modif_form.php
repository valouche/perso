<?php session_start(); ?>
<html>
	<head>
		<link rel="stylesheet" type="text/css" href="../styles/style.css" media="all" />
    </head>
	<body>
    <form action="modif.php" method="post">
	Identifiant: <input type="text" name="login" value="" required />
	<?php if ($_SESSION['isadmin'] == 0) { ?>
	<br />
	Ancien mot de passe: <input type="password" name="oldpw" value="" required />
	<?php } ?>
	<br />
	Nouveau mot de passe: <input type="password" name="newpw" value="" required />
	<input type="submit" name="submit" value="OK" />
    </form>
   <br /><a href="../">Retour accueil</a><br />
</body></html>
