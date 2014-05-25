<?PHP
if ($_POST['submit'] != "OK")
     header("Location: ../index.php?msg=ERREUR:%20Veuillez%20utiliser%20le%20formulaire%20Web");
$data = unserialize(file_get_contents("../../private/passwd"));
foreach ($data as $key => $el)
{
	echo $el['login']."\n";
	if ($el['login'] == $_POST['login'])
	{
		header("Location: ../index.php?msg=ERREUR:%20Login%20deja%20utilise");
		exit;
	}
}
$data[] = array("login" => $_POST["login"], "passwd" =>  hash("whirlpool", $_POST["passwd"]), "isadmin" => 0);
$data = serialize($data);
file_put_contents("../../private/passwd", $data);
chmod("../../private/passwd", 0775);
header("Location: ../index.php?msg=Compte%20cree!%20Connectez%20vous%20:)");
?>
