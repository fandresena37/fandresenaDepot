<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="./AffichageAge.css" rel="stylesheet"/>
    <script src="./script.js"></script>
    <title>Agenda</title>
</head>
<body>
<header>
<?php
    session_start();
    $month = null;
    $year = null;
    if ($_GET["mois"]){
        $month = $_GET["mois"];
        $year = $_GET["annee"];
    }
    else{
        $month = date('m');
        $year = date('Y');
    }
    $_SESSION["mois"] = $month;
    $_SESSION["annee"] = $year;
?>    
    <div id="div">
        <p id="mois">mois:<span id="span"><?php session_start();echo getMois($_SESSION["mois"]);?></span><button id="btn-mois" onclick="changerMois()">changer</button>
        </p>
    </div>
    <div id="id1">
        <p id="annee"><button id="btn-annee"onclick="changerAnnee()">changer</button>annee:<span id="span-annee"><?php session_start();echo $_SESSION["annee"]?></span></p>
    </div>
    </header>   
<section style="height:88%;width:100%;display:flex;justify-content:center;align-items:center;background: linear-gradient(to right,blue,aqua);"> 
    <section class="section">
        <section class="sec-agend">
            <?php
            session_start();
            $month = $_SESSION["mois"];
            $year = $_SESSION["annee"];

            $lastDayOfMonth = date('Y-m-t', mktime(0, 0, 0, $month, 1, $year));
            $last = new DateTime($lastDayOfMonth);
            $nbLast = (int)$last->format('d');
            for ($i=1;$i<=$nbLast;$i++){
                if ($i<10){
                    $day = "".$year."-".$month."-0".$i;
                }
                else{
                    $day = "".$year."-".$month."-".$i;
                }
                $date = new DateTime($day);
                echo "<a class=\"lienAjout\" href=\"http://www.agenda.mg/Ajout.php?annee=".$year."&mois=".$month."&jour=".$i."\" >";
                echo "<section class=\"jour\">";
                echo "<div class=\"day\">";
                echo "<h2>".getJourSemaine($date->format('l'))."</h2>";
                echo "</div>";
                echo "<div class=\"day-nb\">";
                echo "<p>".$i."</p>";
                echo "</div>";
                echo "</section>";
                echo "</a>";
            }
             // Output: 2024-04-30
            // p.println("<html>"
            // 				+ "<head>"
            // 				+ "<meta charset=\"UTF-8\">"
            // 				+ "<title>affichage</title>"
            // 				+ "<link href=\"AffichageAge.css\" rel=\"stylesheet\"/>"
            // 				+ "<script src=\"http://localhost:8080/agenda/script.js\"></script>"
            // 				+ "</head>");
            // 		p.println("<body>");
            // 		p.println("<header>"
            // 				+ "<div id=\"div\"><p id=\"mois\">mois:<span id=\"span\">"+getMois(mois+1)+"</span><button id=\"btn-mois\"onclick=\"changerMois()\">changer</button></p>"
            // 				+ "</div><div id=\"id1\"><p id=\"annee\"><button id=\"btn-annee\"onclick=\"changerAnnee()\">changer</button>annee:<span id=\"span-annee\">"+annee+"</span></p></div>"
            // 				+ "</header>"
            // 				+ "<section style=\"height:88%;width:100%;display:flex;justify-content:center;align-items:center;background: linear-gradient(to right,blue,aqua);\">"
            // 				+ "<section class=\"section\">");
            // 		p.println("<section class=\"sec-agend\">");
            // 		for (int i = 0; i < nbJours; i++) {
            // 			calendar.set(annee, mois, i+1);
            // 			p.println("<a id=\"ajout"+i+"\" class=\"lienAjout\" href=\"http://localhost:8080/agenda/Ajout.jsp?annee="+annee+"&mois="+(mois+1)+"&jour="+(i+1)+"\"/>"
            // 					+ "<section class=\"jour\">"
            // 					+ "<div class=\"day\">"
            // 					+ "<h2>"+getJourSemaine(calendar.get(Calendar.DAY_OF_WEEK))+"</h2>"
            // 					+ "</div>"
            // 					+ "<div class=\"day-nb\">"
            // 					+ "<p>"+(i+1)+"</p>"
            // 					+ "</div>"
            // 					+ "</section></a>");
            // 		}
            // 		p.println("</section></section></section></body>"
            //				+ "</html>");



            function getJourSemaine($jourSemaine) {
                switch ($jourSemaine) {
                    case "Sunday":
                        return "dimanche";
                    case "Monday":
                        return "lundi";
                    case "Tuesday":
                        return "mardi";
                    case "Wednesday":
                        return "mercredi";
                    case "Thursday":
                        return "jeudi";
                    case "Friday":
                        return "vendredi";
                    case "Saturday":
                        return "samedi";
                }
            }
            function getMois($jourSemaine) {
                switch ($jourSemaine) {
                    case "01":
                        return "Janvier";
                    case "02":
                        return "Fevrier";
                    case "03":
                        return "Mars";
                    case "04":
                        return "Avril";
                    case "05":
                        return "Mai";
                    case "06":
                        return "Juin";
                    case "07":
                        return "Juillet";
                    case "08":
                        return "Aôut";
                    case "09":
                        return "Septembre";
                    case "10":
                        return "Octobre";
                    case "11":
                        return "Novembre";
                    case "12":
                        return "Decembre";
                    default:
                        return "jour inconnu";
                    }
                }   
            ?>
        </section>
    </section>
</section>
</body>
</html>


