<?php
if(!isset($_SERVER['HTTP_REFERER']))
{
    header('location:main.php');
    exit;
}
$user = 'root';
$pass = '';
$con = new mysqli('localhost', $user, $pass, 'publications');
$id = $_GET['id'];
$sql = "DELETE FROM authors WHERE No = '".$id."'";
$con->query($sql) or die("Error: ". $con->error);
$con->query("ALTER TABLE authors AUTO_INCREMENT = 1") or die("Error: ". $con->error);
header('location:main.php');
exit();
?>