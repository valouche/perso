<?PHP
if (!$_POST['name'] && !$_POST['category'] && !$_POST['desc'] && !$_POST['price'])
{
	header("Location: ../index.php?msg=Veuillez%20remplir%20au%20moins%20un%20champs");
	exit;
} 
if ($_POST['type'] == "category")
	$data = unserialize(file_get_contents("../../private/category"));
else if ($_POST['type'] == "product")
	$data = unserialize(file_get_contents("../../private/shop"));
foreach ($data as $key => &$el)
{
	if ($el['name'] == $_POST['tochange'])
	{
		$chk++;
		break;
	}
}
if ($chk == 0)
{
	header("Location: ../index.php?msg=Produit/Categorie%20inexistant(e)");
	exit;
}
if ($_POST['type'] == "product")
{
	if ($_POST['name'])
		$el['name'] = $_POST['name'];
    if ($_POST['category'])
		$el['category'] = array_values(array_filter(explode(" ", $_POST['category'])));
    if ($_POST['price'])
		$el['price'] = $_POST['price'];
    if ($_POST['desc'])
		$el['desc'] = $_POST['desc'];
    $data = serialize($data);
	file_put_contents ("../../private/shop", $data);
	header("Location: ../index.php?msg=Article%20modifie");
}
else
{
	$el['name'] = $_POST['name'];
	$data = serialize($data);
	file_put_contents ("../../private/category", $data);
	header("Location: ../index.php?msg=Categorie%20modifiee!");
  }
?>
