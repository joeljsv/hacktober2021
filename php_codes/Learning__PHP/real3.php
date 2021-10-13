<?php

$var=array(
    array("ok",1,2),
    array("pp",3,4),
    array("poli",7,8)
);
foreach($var as $r){
    print_r($r);
    echo "<br>";
}


echo "<br> <br><br><br>";
echo $var[2][0];

echo "<br> <br><br><br>";

foreach($var as $r)
{
    foreach($r as $value){
        echo $value." ";
    }
    echo "<br>";
}



?>