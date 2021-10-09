<?php

if(isset($_POST['submit']))

{

$num=$_POST['num'];

$sum=0;

$temp=$num;

while($temp!=0)

{

$rem=$temp%10;

$sum=$sum+$rem*$rem*$rem;

$temp=$temp/10;

}

if($num==$sum)

{

echo "$num is an Armstrong number";

}

else

{

echo "$num is not an Armstrong number";

}

}

?>

<!DOCTYPE html>

<html>

<head>

<title>Armstrong Number</title>

</head>

<body>

<table>

<form name="armstrong" method="post">

<tr>

<td>Enter Number :</td>

<td><input type="text" name="num" required></td>

</tr>

<tr>

<td></td>

<td><input type="submit" value="Check" name="submit" /></td>

</tr>

</form>

</table>

</body>

</html>
