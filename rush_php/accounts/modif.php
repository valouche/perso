<?php
function	login_valid($accounts)
{
    foreach ($accounts as $tab)
    {
	if (($tab['login'] == $_POST['login']) && ($tab['passwd'] == hash("whirlpool", $_POST['oldpw'])))
	    return 1;
    }
    return 0;
}
$pvfile = "../../private/passwd";
$passwd = file_get_contents($pvfile);
$accounts = unserialize($passwd);
if ($_POST['oldpw'] != "" && !login_valid($accounts))
	header("Location: ../index.php?msg=Login%20Invalide");
foreach ($accounts as &$tab)
{
	if ($tab['login'] == $_POST['login'])
	{
		$tab['passwd'] = hash("whirlpool", $_POST['newpw']);
		file_put_contents($pvfile, serialize($accounts));
		header("Location: ../index.php?msg=Mot%20de%20passe%20modifie%20avec%20succes!");
		exit;
	}
}
header("Location: ../index.php?msg=Utilisateur%20inexistant");
?>

