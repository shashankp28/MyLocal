<!DOCTYPE html>
<html>
<head>
<title></title>
</head>
<body>
<?php
session_start();
$user = 'root';
$pass = '';
$con = new mysqli('localhost', $user, $pass);
if($con->connect_error)
{
	die("Connection Error: " . $conn->connect_error);
}
$sql = 'CREATE DATABASE IF NOT EXISTS Shop';
if($con->query($sql) === False)
{
	die("Error: ". $con->error);
}
$con = new mysqli('localhost', $user, $pass, 'shop');
$sql = 'CREATE TABLE IF NOT EXISTS product
		(No int NOT NULL AUTO_INCREMENT,
		item varchar(120) NOT NULL,
		 cost smallint(6) NULL,
		 PRIMARY KEY (No))';
if ($con->query($sql) === FALSE)
{
	die("Error creating table: " . $con->error);
}
$sql = "SELECT * FROM product";
$result = $con->query($sql) or die("Error: ". $con->error);
if($result->num_rows == 0)
{
	$sql = "INSERT INTO product(item, cost)
			VALUES ('Vacuum Cleaner', '2000')";
	$con->query($sql);
	$sql = "INSERT INTO product(item, cost)
			VALUES ('Mirror', '500')";
	$con->query($sql);
	$sql = "INSERT INTO product(item, cost)
			VALUES ('Earphone', '800')";
	$con->query($sql);
	$sql = "INSERT INTO product(item, cost)
			VALUES ('Toy Car', '80')";
	$con->query($sql);
	$sql = "INSERT INTO product(item, cost)
			VALUES ('Bottle', '600')";
	$con->query($sql);
}
$sql = 'CREATE TABLE IF NOT EXISTS users
		(No int NOT NULL AUTO_INCREMENT,
		user varchar(120) NOT NULL UNIQUE,
		 pass varchar(120) NULL,
		 PRIMARY KEY (No))';
if ($con->query($sql) === FALSE)
{
	die("Error creating table: " . $con->error);
}
	echo 'Sign-Up';
	echo '<form action="sign.php" method="POST">
	<label for="new_user"><b>New Username</b><input type="text" name="new_user" required><br>
	<label for="new_pass"><b>Password</b><input type="password" name="new_pass" required><br>
	<label for="new_pass_conf"><b> Confirm Password</b><input type="password" name="new_pass_conf" required><br>
	<input type="submit" value="Sign-Up"><br></form>';
	echo 'Sign-In';
	echo '<form action="sign.php" method="POST">
	<label for="user"><b>Username</b><input type="text" name="user" required><br>
	<label for="pass"><b>Password</b><input type="password" name="pass" required><br>
	<input type="submit" value="Sign-In"><br></form>';
?>
</body>
</html>