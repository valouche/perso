<?php
session_start();
unset($_SESSION['loggued_on_user']);
unset($_SESSION['isadmin']);
unset($_SESSION['cart']);
header("Location: ../index.php?msg=Deconnexion%20Reussie");
?>
