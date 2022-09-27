<!DOCTYPE html>
<html>
<head>
<title></title>
<link rel="stylesheet" href="style.css">
<style>
form{
	text-align: center;
	width: 30%;
}
</style>
</head>
<body>
<?php
if(!isset($_SERVER['HTTP_REFERER']))
{
    header('location:main.php');
    exit;
}
$user = 'root';
$pass = '';
$con = new mysqli('localhost', $user, $pass, 'publications');
if(isset($_POST["author_a"]) && isset($_POST["publisher"]))
{
	$sql = "INSERT INTO authors(author, publisher)
			VALUES ('".$_POST["author_a"]."', '".$_POST["publisher"]."')";
	$con->query($sql) or die('<h1>Failed to add: '.$con->error.'</h1><br><form action="main.php" method="POST">
	<input type="submit" value="Back"><br>
	</form>');
	header('location:main.php');
	exit();
}
elseif(isset($_POST["author_t"]) && isset($_POST["title"]) && isset($_POST["year"]))
{
	$sql = "INSERT INTO titles(title, author, year)
			VALUES ('".$_POST["title"]."', '".$_POST["author_t"]."', '".$_POST["year"]."')";
	$con->query($sql) or die('<h1>Failed to add: '.$con->error.'</h1><br><form action="main.php" method="POST">
	<input type="submit" value="Back"><br>
	</form>');
	header('location:main.php');
	exit();
}
elseif(isset($_POST["old_title"]) && isset($_POST["upd_year"]))
{
	$ot = $_POST["old_title"];
	$uy = $_POST["upd_year"];
	$sql = "SELECT * FROM titles WHERE title like '%$ot%'";
	$result = $con->query($sql) or die("Error: ". $con->error);
	if($result->num_rows == 0)
	{
		echo '<h1>Nothing Found!</h1>';
		echo '<form action="main.php" method="POST">
		<input type="submit" value="Back"><br>
		</form>';
		exit();
	}
	while($row = $result->fetch_assoc())
	{
		$x = $row['title'];
		$sql = "UPDATE titles SET year = '$uy' WHERE title = '$x'";
		$con->query($sql) or die("Error: ". $con->error);
	}
	header('location:main.php');
	exit();
}
elseif(isset($_POST["ay_title"]))
{
	$ay = $_POST["ay_title"];
	$sql = "SELECT * FROM titles WHERE title like '%$ay%'";
	$result = $con->query($sql) or die("Error: ". $con->error);
	if($result->num_rows == 0)
	{
		echo '<h1>Nothing Found!</h1>';
		echo '<form action="main.php" method="POST">
		<input type="submit" value="Back"><br>
		</form>';
		exit();
	}
	echo '<div align="left"><h1>Authors</h1></div>';
	while($row = $result->fetch_assoc())
	{
		$t = $row['title'];
		$a = $row['author'];
		$y = $row['year'];
		?><p><?php echo "The book ".$t." is written by ".$a." in the year ".$y.".<br>"; ?></p><?php
	}
	echo '<form action="main.php" method="POST">
	<input type="submit" value="Back"><br>
	</form>';
}
elseif(isset($_POST["li_publish"]))
{
	$ay = $_POST["li_publish"];
	$sql = "SELECT * FROM authors WHERE publisher = '$ay'";
	$result = $con->query($sql) or die("Error: ". $con->error);
	if($result->num_rows == 0)
	{
		echo '<h1>Nothing Found!</h1>';
		echo '<form action="main.php" method="POST">
		<input type="submit" value="Back"><br>
		</form>';
		exit();
	}
	echo '<div align="left"><h1>Books published by '.$ay.'</h1></div>';
	while($row = $result->fetch_assoc())
	{
		$a = $row['author'];
		$sql = "SELECT * FROM titles WHERE author = '$a'";
		$result1 = $con->query($sql) or die("Error: ". $con->error);
		while($row1 = $result1->fetch_assoc())
		{
			?><p><?php
			echo $row1['title']." written by ".$row1['author']." in the year ".$row1['year'];
			?></p><?php
		}
	}
	echo '<form action="main.php" method="POST">
	<input type="submit" value="Back"><br>
	</form>';
}
else
{
	header('location:main.php');
	exit();
}
?>
</body>
</html>