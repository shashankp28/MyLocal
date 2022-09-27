<!DOCTYPE html>
<html>
<head>
<title></title>
</head>
<body>
<?php
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
$con = new mysqli('localhost', $user, $pass, 'Shop');
$sql = 'CREATE TABLE IF NOT EXISTS product
		(No int NOT NULL AUTO_INCREMENT,
		Item varchar(120) NOT NULL,
		 Cost smallint(6) NULL,
		 PRIMARY KEY (No))';
if ($con->query($sql) === FALSE)
{
	die("Error creating table: " . $con->error);
}
$sql = 'CREATE TABLE IF NOT EXISTS users
		(No int NOT NULL AUTO_INCREMENT,
		user varchar(120) NOT NULL,
		 pass varchar(120) NULL,
		 PRIMARY KEY (No))';
if ($con->query($sql) === FALSE)
{
	die("Error creating table: " . $con->error);
}
?>
</body>
</html>