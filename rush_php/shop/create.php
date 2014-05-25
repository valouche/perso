<?PHP
function	exists($name, $data)
{
	foreach ($data as $el)
	{
		if ($el['name'] == $name)
		{
			header("Location: ../index.php?msg=ERREUR:%20Existe%20deja");
			exit;
		}
	}
}
function	cat_exists($check, $categories)
{
	$found = 0;
	foreach ($categories as $elem)
	{
		foreach ($check as $elm)
		{
			if ($elm == $elem['name'])
				$found++;
		}
		if ($found == 0)
			return FALSE;
	}
	return TRUE;
}
if ($_POST['product'] == "OK")
{
	if (is_array($data = unserialize(file_get_contents("../../private/shop"))) === FALSE)
		$data = array();
	exists($_POST['name'], $data);
	$categories = array_values(array_filter(explode(" ", $_POST['categories'])));
	$file_cat = unserialize(file_get_contents("../../private/category"));
	if (cat_exists($categories, $file_cat) === FALSE)
	{
		header("Location: ../index.php?msg=Une%20ou%20plusieurs%20categorie%20n'existe%20pas");
		exit;
	}
	$data[] = array("name" => $_POST["name"], "desc" =>  $_POST["desc"], "price" => $_POST["price"], "categories" => $categories);
	$ser = serialize($data);
	file_put_contents ("../../private/shop", $ser);
	header("Location: ../index.php?msg=Produit%20ajoute!");
}
else
{
	if (is_array($tab_cat = unserialize(file_get_contents("../../private/category"))) === FALSE)
		$tab_cat = array();
	exists($_POST['name'], $tab_cat);
	$tab_cat[] = array("name" => $_POST["name"]);
	$ser = serialize($tab_cat);
	file_put_contents ("../../private/category", $ser);
	header("Location: ../index.php?msg=Categorie%20ajoutee!");
}
?>
