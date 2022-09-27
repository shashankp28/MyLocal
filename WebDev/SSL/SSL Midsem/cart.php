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
$sql = "SELECT * FROM cart".$_SESSION['user'];
$result = $con->query($sql) or die("Error: ". $con->error);
?>
<h1>Cart</h1>
<table>
<tr>
 <th>Item</th>
 <th>Cost</th>
 <th>Delete</th>
 </tr>
<?php
if($result->num_rows > 0)
{
 while($row = $result->fetch_assoc())
 {
 ?>
 <tr>
 <td><?php echo $row['item']; ?></td>
 <td><?php echo $row['cost']; ?></td>
 <td><a href="deletecart.php?id=<?php echo $row['item']; ?>">Delete</a></td>
 </tr>
 <?php
 }
}
?>
<form action="shop.php" method="POST">
<input type="submit" value="Shop"><br>
</form>
<form action="order.php" method="POST">
<input type="submit" value="Order"><br>
</form>
<form action="logout.php" method="POST">
<input type="submit" value="Logout"><br>
</form>
</body>
</html>