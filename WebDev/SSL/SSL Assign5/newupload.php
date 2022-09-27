<?php
session_start();
if(!isset($_SESSION["login"]) || $_SESSION["login"]==False)
{
	header("Location:index.php");
	exit();
}
?>
<html>
<head>
<link rel="stylesheet" href="style.css">
<title>Upload</title>
</head>
<body>
<div align="center">
<h1>Choose files to upload</h1>
<h3>Instructions</h3>
<ul align = "center">
  <li>All images must have .jpg extention.</li>
  <li>Individual images cannot exceed 200KB in size.</li>
  <li>Atmost 10 images can be uploaded at a time.</li>
</ul>
<form action="upload.php" enctype="multipart/form-data" method="post">
<input type="file" name="img[]" multiple><br/>
<input type="submit" value="Upload" name="upl">
</form>
<form action = "album.php" method="post">
<input type="submit" class="button" value="Back" />
</form>
<table id="imgtab">
<?php
	$dir = "images/*.jpg";
	$img = glob($dir);
	$c = count($img);
	$i = 0;
	if($c>0)
	{
		echo '<p style="color: lightgreen; width: 40%;">Click on an Image to Delete it</p>';
	}
	while($i<$c)
	{
			echo '<td><a href="upload.php?action=delete&filename='.$img[$i].'">
			<img src ="'.$img[$i].'" width=120 height=120 style="border: 2px solid red;" /></a></td>';
			$i++;
	}
?>
</table>
</div>
</body>
</html>