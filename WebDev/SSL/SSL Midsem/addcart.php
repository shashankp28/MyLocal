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
$id = $_GET['id'];
$sql = "SELECT * FROM product WHERE item like '$id'";
	$result = $con->query($sql) or die("Error: ". $con->error);
	while($row = $result->fetch_assoc())
	{
		$sql = "INSERT INTO cart".$_SESSION["user"]."(item, cost)
			VALUES ('".$row['item']."', '".$row['cost']."')";
		$con->query($sql) or die('<h1>Failed to add: '.$con->error.'</h1><br><form action="shop.php" method="POST">
		<input type="submit" value="Back"><br>
		</form>');
	}
	header('location:shop.php');
	exit();
?>
</body>
</html>