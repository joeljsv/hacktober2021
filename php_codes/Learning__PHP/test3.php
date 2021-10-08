<?php 

$db=new mysqli("localhost","root","root","person");

$r=$db->query("select Name,salary from customer");

while($row=$r->fetch_array())
{
    echo $row[1]." <br>";//1 means salary
    echo $row[0]."<br>";
   
}
