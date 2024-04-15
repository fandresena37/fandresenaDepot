<?php
    $day = $_GET["jour"];
    $month = $_GET["mois"];
    $year = $_GET["annee"];
    if((int)$day<10){
        $date = "0".$day."/".$month."/".$year;
    }
    else{
        $date = "".$day."/".$month."/".$year;
    }
    session_start();
    $_SESSION["date"] = $date;

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="loginCSS.css" rel="stylesheet"/>
    <title>Ajout</title>
</head>
<body>
    <form action="http://www.agenda.mg/AjoutDB.php" method="post" class="form1">
		<div class="div-form">
			<h2>AJOUT D'EVENEMENT</h2>
			<div class="input2">date de l'evenement</div>
			<input type="text" name="dateEvent" placeholder="jj/mm/aa" class="input1" value=<?php session_start();echo $_SESSION["date"]?> readOnly>
			<div class="input2">l'evenement</div>
			<input type="text" name="Event" placeholder="l'evenement" class="input1" required>
			<div class="input2">description</div>
			<input type="text" name="description" placeholder="description de l'evenement" class="input1" required>
			<div class="input2">proprietaire</div>
			<input type="text" name="proprietaire" placeholder="proprietaire" class="input1" value=<?php session_start();echo $_SESSION["user"]?> readOnly>
			<div class="input2">date de creation</div>
			<input type="text" name="dateCreate" placeholder="date de creation" class="input1" required>
			<input type="submit" class="sub" value="Ajouter"/>
		</div>
	</form>	
</body>
</html>