<!DOCTYPE html>
<html>
<head>
<title></title>
</head>
<body>
<?php
session_start();
$_SESSION['user'] = 0;
header('location:index.php');
?>
</body>
</html>