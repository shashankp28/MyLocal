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
$con = new mysqli('localhost', $user, $pass, 'shop');
if(isset($_POST["new_user"]) && isset($_POST["new_pass"]) && isset($_POST["new_pass_conf"]))
{
	if($_POST["new_pass"] != $_POST["new_pass_conf"])
	{
		echo '<h1>Passwords do not match</h1>';
		echo '<form action="index.php" method="POST">
		<input type="submit" value="Back"><br>
		</form>';
		exit();
	}
	$sql = "INSERT INTO users(user, pass)
			VALUES ('".$_POST["new_user"]."', '".$_POST["new_pass"]."')";
	$con->query($sql) or die('<h1>Failed to add: '.$con->error.'</h1><br><form action="index.php" method="POST">
	<input type="submit" value="Back"><br>
	</form>');
	echo '<h1>Sign-Up Successful</h1>';
		echo '<form action="index.php" method="POST">
		<input type="submit" value="Back"><br>
		</form>';
	exit();
}
elseif(isset($_POST["user"]) && isset($_POST["pass"]))
{
	$u = $_POST["user"];
	$p = $_POST["pass"];
	$sql = "SELECT * FROM users WHERE user like '$u'";
	$result = $con->query($sql) or die("Error: ". $con->error);
	if($result->num_rows == 0)
	{
		echo '<h1>Invalid Credentials</h1>';
		echo '<form action="index.php" method="POST">
		<input type="submit" value="Back"><br>
		</form>';
		exit();
	}
	while($row = $result->fetch_assoc())
	{
		$x = $row['pass'];
		if($row['pass'] == $p)
		{
			$sql = 'CREATE TABLE IF NOT EXISTS cart'.$u.'
				(No int NOT NULL AUTO_INCREMENT,
				item varchar(120) NOT NULL UNIQUE,
				cost smallint(6) NULL,
				PRIMARY KEY (No))';
			if ($con->query($sql) === FALSE)
			{
				die("Error creating table: " . $con->error);
			}
			$_SESSION["user"] = $u;
			header('location:shop.php');
			exit();
		}
		echo '<h1>Invalid Credentials</h1>';
		echo '<form action="index.php" method="POST">
		<input type="submit" value="Back"><br>
		</form>';
		exit();
	}
	
}
?>
</body>
</html>