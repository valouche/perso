<?php
include ("auth.php");
session_start();
if (isset($_GET['msg']))
    echo $_GET['msg']."<br />";
if (($isadmin = auth($_POST['login'], $_POST['passwd'])) !== FALSE)
{
    $_SESSION['loggued_on_user'] = $_POST['login'];
    $_SESSION['isadmin'] = $isadmin;
    header("Location: ../index.php?msg=Connection%20reussie");
}
else
{
    $_SESSION['loggued_on_user'] = "";
    header("Location: ../index.php?msg=Identifiant%20ou%20mot%20de%20passe%20incorrect.");
}
?>
