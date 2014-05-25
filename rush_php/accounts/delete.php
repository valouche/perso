<?PHP
session_start();
if ($_SESSION['isadmin'] == 1)
{
    $data = unserialize(file_get_contents("../../private/passwd"));
	foreach ($data as $key => &$el)
	{
		if ($el['login'] == $_POST['todel'])
			break;
	}
	unset($data[$key]);
    $data = serialize($data);
    file_put_contents ("../../private/passwd", $data);
    header("Location: ../index.php?msg=Utilisateur%20supprime%20avec%20succes!");
}
else
	header("Location: ../index.php?msg=Permission%20Refusee");
?>
