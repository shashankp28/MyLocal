<html>
<head>
<link rel="stylesheet" href="style.css">
<title>Album</title>
</head>
<body>
<div align="center"><h1>Photo Album</h1></div>
<?php
session_start();
if(!isset($_SESSION["login"]) || $_SESSION["login"]==False)
{
	header("Location:index.php");
	exit();
}
if($_SESSION["login"]==False)
{
	header("Location:index.php");
	exit();
}
	$dir = "images/*.jpg";
	$img = glob($dir);
	$i = $_SESSION["imgcount"];
	$c = count($img);
if(array_key_exists('inc', $_POST) && $_SESSION["imgcount"]<count($img)-1 && $c>0)
{
    $_SESSION["imgcount"]++;
	header("Location:album.php");
	exit();
}
else if(array_key_exists('dec', $_POST) && $_SESSION["imgcount"]>0 && $c>0) 
{
	$_SESSION["imgcount"]--;
	header("Location:album.php");
	exit();
}
else if(array_key_exists('fir', $_POST) && $c>0) 
{
	$_SESSION["imgcount"] = 0;
	header("Location:album.php");
	exit();
}
else if(array_key_exists('las', $_POST) && $c>0) 
{
	$_SESSION["imgcount"] = $c - 1;
	header("Location:album.php");
	exit();
}
	if($c==0)
	{
		echo'<div align="center">
			<h2 style="background-color: black; color: red; padding: 22px; width: 40%;">
			There are no photos in this album.<br>Please click on upload to add photos
			</h2></div><br>';
	}
	else
	{
		echo '<img src ="'.$img[$i].'" height="500" style="width: 50%; 	margin-left: auto; margin-right: auto;"><br>';
		echo '<div align="center"><h4>'.($i+1).'/'.$c.'</h4></div>';
	}
	echo '<div align="center"><form class="pure-form pure-form-aligned" method="post">
		<input type="submit" name="fir" class="button" value="First" />
		<input type="submit" name="dec" class="button" value="Previous" />
		<input type="submit" name="inc" class="button" value="Next" />
		<input type="submit" name="las" class="button" value="Last" />
		</form></div>'
        ;
?>
<form action="newupload.php" method="post" align="center">
<input type="submit" name="upl" class="button" value="Upload/Delete" />
</form>
</body>
</html>