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
$sql = "SELECT * FROM product";
$result = $con->query($sql) or die("Error: ". $con->error);
?>
<h1>Shop</h1>
<table>
<tr>
 <th>Item</th>
 <th>Cost</th>
 <th>Add to cart</th>
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
 <td><a href="addcart.php?id=<?php echo $row['item']; ?>">Add</a></td>
 </tr>
 <?php
 }
}
?>
<form action="cart.php" method="POST">
<input type="submit" value="Cart"><br>
</form>
<form action="logout.php" method="POST">
<input type="submit" value="Logout"><br>
</form>
</body>
</html>