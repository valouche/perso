<?PHP
if ($_POST['todel'] == "category")
{
	$data_c = unserialize(file_get_contents("../../private/category"));
   	foreach ($data_c as $key => &$value)
	  {
		if ($value['name'] == $_POST['name'])
		{
			$chk++;
			break ;
		}
	  }
	if ($chk == 0)
	{
		header("Location: ../../index.php?msg=Categorie%20inexistante");
		exit;
	}
	unset($data_c[$key]);
	$data_c = serialize($data_c);
	file_put_contents ("../../private/category", $data_c);
	header("Location: ../index.php?msg=Categorie%20supprimee");
}
else if ($_POST['todel'] == "product")
{
	$data = unserialize(file_get_contents("../../private/shop"));
	foreach ($data as $key => &$el)
	{
		if ($el['name'] == $_POST['name'])
		{
			$chk++;
			break;
		}
	}
	if ($chk == 0)
	{
		header("Location: ../index.php?msg=Produit%20inexistant");
		exit;
	}
	unset($data[$key]);
	$data = serialize($data);
	file_put_contents ("../../private/shop", $data);
	header("Location: ../index.php?msg=Article%20supprime");
}
?>
