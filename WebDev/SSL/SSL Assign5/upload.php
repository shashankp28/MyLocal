<html>
<head>
<link rel="stylesheet" href="style.css">
<title></title>
</head>
<body>
<div align="center">
<?php
session_start();
if(!isset($_SESSION["login"]) || $_SESSION["login"]==False)
{
	header("Location:index.php");
	exit();
}
if(isset($_GET['action']) && $_GET['action'] == 'delete') 
	{
		$dir = "images/*.jpg";
		$img = glob($dir);
		$c = count($img);
		if($_SESSION["imgcount"] == $c-1 && $_SESSION["imgcount"]!=0)
		{
				$_SESSION["imgcount"]--;
		}
       unlink($_GET['filename']);
       header("Location:newupload.php");
       exit();
   }
function back()
{
	echo '<p style="color: red;" align="center">UPLOAD FAILED!<br>Please click the back button to upload again.</p><br>';
	echo '<form action = "newupload.php" method="post">
		<input type="submit" class="button" value="Back" />
		</form>';
	exit();
}
if(!isset($_FILES['img']['name']))
{
	header("Location:newupload.php");
    exit();
}
$total = count($_FILES['img']['name']);
	if($total>10)
	{
		echo '<p style="color: red;">Only a maximum of 10 images can be uploaded at a time.</p><br>';
		back();
	}
for($i=0 ; $i < $total ; $i++)
{
	$filename = $_FILES['img']['tmp_name'][$i];
	$fn = $_FILES['img']['name'][$i];
	$ext = pathinfo($fn, PATHINFO_EXTENSION);
	$size = filesize($filename);
	if($filename == "")
	{
		echo '<p style="color: red;">No images were selected to upload.</p><br>';
		back();
	}
	if(file_exists("./images/" . $fn))
	{
		echo '<p style="color: red;">A file named '.$fn.' already exists.</p><br>';
		back();
	}
	if($ext != 'jpg')
	{
		echo '<p style="color: red;">'.$fn.' does not have the extention of .jpg.</p><br>';
		back();
	}
	if($size > 200000)
	{
		echo '<p style="color: red;">'.$fn.' exceeds the size limit of 200 KB.</p><br>';
		back();
	}
	if($filename != "")
	{
		$newFilePath = "./images/" . $fn;
		move_uploaded_file($filename, $newFilePath);
	}	
}
for($i=0 ; $i < $total ; $i++)
{
	$filename = $_FILES['img']['tmp_name'][$i];
	$fn = $_FILES['img']['name'][$i];
	$newFilePath = "./images/" . $fn;
	move_uploaded_file($filename, $newFilePath);
}
echo '<p style="color: lightgreen;">Upload Successful.<br>You can browse the album or upload more files</p>';
echo '<form action="album.php">
		<input type="submit" value ="Album"/>
		</form>
		<form action = "newupload.php" method="post">
		<input type="submit" class="button" value="Upload" />
		</form>';
$_SESSION["imgcount"] = 0;
?>
</div>
<div align="center">
<p style="color: lightgreen; width: 40%;">Preview</p>
<table>
<tr>
<?php 
for($i=0 ; $i < $total ; $i++)
{
	$fn = $_FILES['img']['name'][$i];
	$newFilePath = "./images/" . $fn;
	echo '<td><img src ="'.$newFilePath.'" width=120 height=120 style="border: 2px solid red;" /></td>';
}
?>
</tr>
</table>
</div>
</body>
</html>