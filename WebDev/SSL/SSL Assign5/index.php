<html>
<head>
<link rel="stylesheet" href="style.css">
<style>
form{
	text-align: center;
	width: 30%;
}
</style>
<title>Login Page</title>
</head>
<body>
<?php 
session_start();
if(!isset($_SESSION["login"]))
{
	$_SESSION["login"] = False;
}
else if($_SESSION["login"] == True)
{
	echo '<div align="center">
			<h2 style="background-color: black; color: lightgreen; padding: 22px; width: 50%;">
			Already logged in, please click on open.
			</h2></div><br>';
	echo '<div align="center"><form action="album.php">
			<input type="submit" value ="Open"/>
			</form></div>';
	exit();
}
?>
<div align="center" class="log">
<h1 align="center">Login to your Album</h1>
<form align = "center" action="login.php" method="post" style="background-color: lightgreen; border: 3px solid;">
<label for="id"><b>User ID</b></label><br><input type="text" name = "id" /><br>
<label for="pass"><b>Password</b></label><br><input type="password" name = "pass" /><br>
<input type="submit" value ="Login"/>
</div>
</form>
</body>
</html>