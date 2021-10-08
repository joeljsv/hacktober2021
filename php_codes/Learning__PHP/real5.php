<?php

$mysqli=new mysqli("localhost","root","root","person");
            // $pra=$mysqli->query("select Name from employee");
            // showdb($pra);
            // function showdb($pra){
            //     while($row=$pra->fetch_array())
            //     {
            //         echo $row['Name']." ";
            //     }
            // }

$result=$mysqli->query("select Name,salary from employee,customer");
$result_count=$mysqli->field_count;

$html="
        <html>
                <head></head>
                <body>
                    <table>
                        <tr>
                            <td><b>NAME</b></td>
                            <td><b>SALARY</b></td>
                        </tr>";
    while($row=$result->fetch_array()){
        $html."<tr>";
        for($i=0;$i<$result_count;$i++){
            $html."<td>".$row[$i]."</td>";
        }
        $html."</tr>";
    }

    $html."</table>
            </body>

        </html>";

        echo $html;
     



?>