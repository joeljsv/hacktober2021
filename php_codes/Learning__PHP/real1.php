<?php
if(isset($_GET["name"]))//   HERE INSTEAD OF GET USE POST FOR SECURITY
{
    $var=$_GET["name"];
}
else{
    $var="------ENTER YOUR NAME TO DISPLAY HERE-----<br>";
}
                          
//can use while,if,ifelse,else
$responsive="<html>
                <head>
                    <title>Forms</title>
                </head>
                <body>
                    <h1> $var </h1>
                    <form action='http://localhost/phpinvisualcode/real1.php' method='GET'>
                            <input type='text' name='name'></input><br>
                            <input type='submit' value='Submit'>
                    </form>
                </body>
             </html>";



echo $var;
echo $responsive;

?>