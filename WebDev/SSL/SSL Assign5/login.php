<html>
<head>
<link rel="stylesheet" href="style.css">
<title>
</title>
</head>
<body>
<?php
session_start();
$id = $_POST["id"];
$pass = $_POST["pass"];
if(!isset($id))
{
	header("Location:index.php");
	exit();
}
if($id=="eval" and $pass=="eva")
{
	$_SESSION["login"] = True;
	$_SESSION["imgcount"] = 0;
	echo'<div align="center">
			<h2 style="background-color: black; color: lightgreen; padding: 22px; width: 50%;">
			Login successful! Click on Open to view your album.
			</h2></div><br>';
	echo '<form action="album.php" align="center">
			<input type="submit" value ="Open"/>
			</form>';
}
else
{
	echo '<div align="center">
			<h2 style="background-color: black; color: red; padding: 22px; width: 40%;">
			Login Credentials do not match. Please Re-Enter
			</h2></div><br>';
	echo '<form action="index.php" align="center">
			<input type="submit" value ="Re-Enter"/>
			</form>';
}
?>
</body>
</html>