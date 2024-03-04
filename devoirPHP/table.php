<!DOCTYPE html>
<html>
    <head>
        <title>table</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" href="tables.css"/>
    </head>
    <body class="bodyTab">
        <h2 style="font-family: Arial, Helvetica, sans-serif;margin-top:30px;">TABLES DE MULTIPLICATIONS</h2>
        <?php
        $nb = NULL;
        $nb = $_POST["nb"];
        if($nb==NULL){
            $nb = $_GET["nb"];
        }
        // echo $nb;
        if($nb==1){
        $A = $_POST["A"];
        $B = $_POST["B"];
        $result = array();
        $b = array();
        $a = array();
        $len = $B;
        for($i=0 ;$i<=$len;$i++){
            $a[$i] = $A;
            $b[$i] = $i;
            $result[$i] = $a[$i]*$b[$i];
        }
        mampiseho($a,$b,$result,$len);
        }
        elseif($nb==2){
            $index = $_POST["i"];
            $amod = $_POST["a"];
            $bmod = $_POST["b"];
            $len = $_POST["len"];
            $a = array();
            $b = array();
            $result = array();
            for($i=0;$i<=$len;$i++){
                $a[$i] = $_POST["a$i"];
                $b[$i] = $_POST["b$i"];
                $result[$i] = $a[$i]*$b[$i];
            }
            $a[$index] = $amod;
            $b[$index] = $bmod;
            $result[$index] = $amod*$bmod;
            mampiseho($a,$b,$result,$len);
        }
        elseif($nb==3){
            // echo "ao";
            $len = $_GET["len"];
            $a = array();
            $b = array();
            $result = array();
            $index = $_GET["i"];
            for($j=0;$j<=$len;$j++){
                $a[$j] = $_GET["a$j"];
                $b[$j] = $_GET["b$j"];
                $result[$j] = $a[$j]*$b[$j];
                // echo "$a[$j] et $b[$j] et $j ";
            }
            $len--;
            unset($a[$index]);
            unset($b[$index]);
            unset($result[$index]);
            $a = array_values($a);
            $b = array_values($b);
            $result = array_values($result);
            // for($j=0;$j<=$len;$j++){
            //     echo "<p>$index et $a[$j] et $b[$j] et $j</p>";
            // }
            mampiseho($a,$b,$result,$len);
        }
        function mampiseho($a,$b,$result,$len){
            echo "<table class=\"tableau\">";
            echo "<tr class=\"tete\"><td><div class=\"td\">A</div></td><td><div class=\"td\">B</div></td><td><div class=\"td\">A*B</div></td><td><div class=\"action\">Action</div></td>";
            for($i=0;$i<=$len;$i++){
            if($i%2 == 0){
                $class = "paire";
            }
            else{
                $class = "impaire";
            }
            echo "<tr class=\"$class\"><td><div class=\"td\">$a[$i]</div></td><td><div class=\"td\">$b[$i]</div></td><td><div class=\"td\">$result[$i]</div></td>
            <td><div class= \"action\">";
            echo "<form class=\"form\" action=\"http://www.iptables.mg/form.php\" method=\"post\">";
                echo "<input name=\"amod\" value=\"$a[$i]\" style=\"display:none;\"/>";
                echo "<input name=\"bmod\" value=\"$b[$i]\" style=\"display:none;\"/>";
                echo "<input name=\"i\" value=\"$i\" style=\"display:none;\"/>";
                echo "<input name=\"len\" value=\"$len\" style=\"display:none;\"/>";
                for($j=0;$j<=$len;$j++){
                echo "<input name=\"a$j\" value=\"$a[$j]\"style=\"display:none;\"/>";
                echo "<input name=\"b$j\" value=\"$b[$j]\"style=\"display:none;\"/>";
                }
                echo "<button class=\"modif\">modifier</button>
            </form>";
            $ch = "http://www.iptables.mg/table.php?nb=3&i=$i&len=$len";
            for($j=0;$j<=$len;$j++){
                $ch=$ch."&a$j=$a[$j]&b$j=$b[$j]";
            }
            echo "<a href=$ch class=\"lien\">supprimer</a>";
            echo "</div></td>
            </tr>";
        }
        echo "</table>";
        }
        ?>
    </body>

</html>