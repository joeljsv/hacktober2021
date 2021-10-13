<?php 
$var=0;
$var2="<html>
            <head>
                <title>praveen</title>
            </head>

                <h1>HEADING</h1>
                <p>WELCOME TO ADULT ENGINEERING</p>

        </html>";
while($var<4){
    echo "<br>var is less than 5";
    echo "  ."."increased to ".$var;
    $var=$var+1;
}
if($var==4)
{
    echo "<br><br>var is 4 now.";
}
else{
    echo "<br><br>var is not 4 now.";
}

echo "<br><br><br>".$var2;


?>