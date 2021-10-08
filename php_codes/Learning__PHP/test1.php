<?php 

$db=new mysqli("localhost","root","root","person");

$r=$db->query("select salary,Name from customer");
// $rr=$db->query("select Name from customer");

// while($row=$rr->fetch_array()){
//     echo $row['Name']."<br> ";
// }
// $r_count=$db->field_count;
// echo $r_count;

$html=" <html>
            <head>
                <title>Praveen</title>
            </head>
            <body>
                <table>
                        <tr>
                            <td><b>NAME |</b.</td>
                            <td><b>SALARY</b></td>
                        </tr>";
                        while($row=$r->fetch_array())
                        {
                           $html."<tr>";
                                $html.="<td>". $row['Name']."</td>";
                                $html.="<td>".$row['salary']."</td>";
                            $html.="</tr>";
                        }
         $html.="</table>
            </body>
        </html>";


echo $html;
?>
