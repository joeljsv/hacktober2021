<?php
$z='abc';
$db=new mysqli("localhost","root","root","person");
$db->query("insert into customer values('$z',200)");
?>