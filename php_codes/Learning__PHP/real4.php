<?php

if(isset($_POST["lessons"])){
    $var=$_POST["lessons"];
    $n=$_POST["name"];
}
else{
    $var=array("a","b","c","d");
}



$var1="<html>
            </head></head>
            <body>
                <h1>Type Here</h1>
                <form action='http://localhost/phpinvisualcode/real4.php' method='POST'>
                    <p>YOUR NAME:</p>
                <input type='text' name='name'></input><br/>
                <b>What lessons do you want to learn?</b><br>
                <select name='lessons[]' size='4' multiple>
                    <option value='mysql'>My Sql</option>
                    <option value='web'>WEB</option>
                    <option value='android'>Android</option>
                    <option value='java'>JAVA</option>
                </select>
                <input type='submit' value='Submit'>
                </form>
            </body>
       </html>";
echo $n." Selected these subjects <br>";
       foreach($var as $id){
        echo $id;
        echo "<br>";
    }
    
echo $var1;




?>