<?php
function	auth($login, $passwd)
{
    $pvfile = "../../private/passwd";
    $content = file_get_contents($pvfile);
    $accounts = unserialize($content);
    foreach ($accounts as $tab)
    {
    	if (($tab['login'] == $login) && ($tab['passwd'] == hash("whirlpool", $passwd)))
			return $tab['isadmin'];
    }
    return FALSE;
}
?>
