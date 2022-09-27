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
$user = 'root';
$pass = '';
$con = new mysqli('localhost', $user, $pass);
if($con->connect_error)
{
	die("Connection Error: " . $conn->connect_error);
}
$sql = 'CREATE DATABASE IF NOT EXISTS publications';
if($con->query($sql) === False)
{
	die("Error: ". $con->error);
}
$con = new mysqli('localhost', $user, $pass, 'publications');
$sql = 'CREATE TABLE IF NOT EXISTS authors
		(No int NOT NULL AUTO_INCREMENT,
		author varchar(120) NOT NULL,
		 publisher varchar(30) NULL,
		 UNIQUE(author, publisher),
		 PRIMARY KEY (No))';
if ($con->query($sql) === FALSE)
{
 die("Error creating table: " . $con->error);
}
$sql = 'CREATE TABLE IF NOT EXISTS titles
		(No int NOT NULL AUTO_INCREMENT,
		title varchar(120) NOT NULL UNIQUE,
		 author varchar(120) NULL,
		 year smallint(6) NULL,
		 PRIMARY KEY (No))';
if ($con->query($sql) === FALSE)
{
 die("Error creating table: " . $con->error);
}
$sql = "SELECT * FROM authors";
$result = $con->query($sql) or die("Error: ". $con->error);
if (!$result) 
{
    die("Query to show fields from table failed");
}
?>
<div class='parent'>
<div class='child'>
<div align="center"><h1>Authors & Publishers</h1></div>
<table id="book">
<tr>
 <th>Author</th>
 <th>Publisher</th>
 <th>Delete Row</th>
 </tr>
<?php
if($result->num_rows > 0)
{
 while($row = $result->fetch_assoc())
 {
 ?>
 <tr>
 <td><?php echo $row['author']; ?></td>
 <td><?php echo $row['publisher']; ?></td>
 <td><a href="delete1.php?id=<?php echo $row['No']; ?>">Delete</a></td>
 </tr>
 <?php
 }
}
?>
<form action="function.php" method="POST"/>
<td><input type="text" name="author_a" required/></td>
<td><input type="text" name="publisher" required/></td>
<td><input type="submit" value="Add"/></td>
</form>
</table>
</div>
<div class='child'>
<?php
$sql = "SELECT * FROM titles";
$result = $con->query($sql) or die("Error: ". $con->error);
if (!$result) 
{
    die("Query to show fields from table failed");
}
?>
<div align="center"><h1>Book Titles</h1></div>
<table id="book">
<tr>
 <th>Title</th>
 <th>Author</th>
 <th>Year</th>
 <th>Delete Row</th>
 </tr>
<?php
if($result->num_rows > 0)
{
 while($row = $result->fetch_assoc())
 {
 ?>
 <tr>
 <td><?php echo $row['title']; ?></td>
 <td><?php echo $row['author']; ?></td>
 <td><?php echo $row['year']; ?></td>
 <td><a href="delete2.php?id=<?php echo $row['No']; ?>">Delete</a></td>
 </tr>
 <?php
 }
}
?>
<form action="function.php" method="POST">
<td><input type="text" name="title" required /></td>
<td><input type="text" name="author_t" required /></td>
<td><input type="number" name="year" required /></td>
<td><input type="submit" value="Add"/></td>
</form>
</table>
</div>
</div>
<div align="center" style="border: 2px solid black;">
<h1>Update the Year for a Book</h1>
<form action="function.php" method="POST">
<label for="old_title"><b>Title</b><input type="text" name="old_title" required><br>
<label for="upd_year"><b>Changed Year</b><input type="number" name="upd_year" required><br>
<input type="submit" value="Update">
<br><br>
</form>
</div>
<div align="center" style="border: 2px solid black;">
<h1>Find Author & Year of a book</h1>
<form action="function.php" method="POST">
<label for="ay_title"><b>Title</b><input type="text" name="ay_title" required><br>
<input type="submit" value="Find"><br>
</form>
<br><br>
</div>
<div align="center" style="border: 2px solid black;">
<h1>Book information from a publisher</h1>
<form action="function.php" method="POST">
<label for="li_publish"><b>Publisher</b><input type="text" name="li_publish" required><br>
<input type="submit" value="List"><br>
</form>
<br><br>
</div>
</body>
</html>