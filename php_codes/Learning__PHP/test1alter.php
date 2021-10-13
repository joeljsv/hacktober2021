<?php 

$db=new mysqli("localhost","root","root","person");

$r=$db->query("select Name,salary from customer");
$r_count=$db->field_count;
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
                                for($i=0;$i<$r_count;$i++)
                                    {
                                        $html.="<td>". $row[$i]."</td>";
                                    }
                            $html.="</tr>";
                        }
         $html.="</table>
            </body>
        </html>";


echo $html;
?>
