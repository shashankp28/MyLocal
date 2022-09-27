<?php
session_start();
$user = 'root';
$pass = '';
$con = new mysqli('localhost', $user, $pass, 'shop');
$id = $_GET['id'];
$sql = "DELETE FROM cart".$_SESSION['user']." WHERE item = '".$id."'";
$con->query($sql) or die("Error: ". $con->error);
$con->query("ALTER TABLE cart".$_SESSION['user']." AUTO_INCREMENT = 1") or die("Error: ". $con->error);
header('location:cart.php');
exit();
?>