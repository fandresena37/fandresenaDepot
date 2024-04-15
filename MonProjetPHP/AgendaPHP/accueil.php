<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>accueil</title>
<link href="accueilCSS1.css" rel="stylesheet"/>
</head>
<body>
	<header class="tete">
		<div class="agenda">
			<h1>AGENDA</h1>
			<p style="margin-left:40px">Bienvenue a vous <strong>
			<?php
			session_start();
			echo $_SESSION["user"];
			?>
			</strong></p>
		</div>
		<div class="btn-div">
			<button class="btn-auth">Deconnexion</button>
		</div>
	</header>
	<section class="accueil">
		<div class="bienv">
			<h2>BIENVENUE SUR L'AGENDA EN LIGNE</h2>
			<div class="div-btn">
			<a style="text-decoration:none" href="http://www.agenda.mg/AfficheEvent.php">
				<button class="btn">Voir les evenements</button>
			</a>
			<a style="text-decoration:none" href="http://www.agenda.mg/AfficheAgenda.php">
				<button class="btn">Ajouter un evenement</button>
			</a>	
			</div>
		</div>
		<div class="image">
			<img src="agenda-removebg-preview.png" class="img"/>
		</div>
	</section>
</body>
</html>