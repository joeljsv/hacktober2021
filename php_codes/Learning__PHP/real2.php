<?php 

$a=array("abc","pk","akfkjs","praveen");

print_r($a);
echo "<br>";
array_push($a,"last");
print_r($a);
echo "<br>";
array_pop($a);
print_r($a);
echo "<br>".$a[0];
echo "<br>";
printf("ok");
echo "<br>";
foreach($a as $d){
    echo $d;
    echo "<br>";
}

for($i=0;$i<5;$i++){
    printf("praveen");
}







?>