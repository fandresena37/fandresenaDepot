<!DOCTYPE html>
<html>
    <head>
        <title>modifications</title>
        <meta charset="utf-8"/>
        <link rel="stylesheet" href="tables.css"/>
    </head>
    <body>
        <?php
            $amod = $_POST["amod"];
            $bmod = $_POST["bmod"];
            $i = $_POST["i"];
            $len = $_POST["len"];
            $a = array();
            $b = array();
            for($j=0;$j<=$len;$j++){
                $a[$j] = $_POST["a$j"];
                $b[$j] = $_POST["b$j"];
            }
            echo "<div class=\"calc\">";
            echo "<form action=\"http://www.iptables.mg/table.php\" method=\"post\">";
                echo "<h2 style=\"font-family: Arial, Helvetica, sans-serif;\">MODIFICATIONS</h2>";
                echo "<input type=\"number\" name=\"a\" value=\"$amod\" class=\"number\" placeholder=\"entrez A\"/>";
                echo "<input type=\"number\" name=\"b\" value=\"$bmod\" class=\"number\" placeholder=\"entrez B\"/>";
                echo "<input name=\"i\" value=\"$i\" style=\"display:none;\"/>";
                echo "<input name=\"nb\" value=\"2\" style=\"display:none;\"/>";
                echo "<input name=\"len\" value=\"$len\" style=\"display:none;\"/>";
                for($j=0;$j<=$len;$j++){
                    echo "<input name=\"a$j\" value=\"$a[$j]\"style=\"display:none;\"/>";
                    echo "<input name=\"b$j\" value=\"$b[$j]\"style=\"display:none;\"/>";
                    }
                echo "<button class=\"sub\">valider</button>";
            echo "</form>";
            echo "</div>";
        ?>
    </body>
</html>        