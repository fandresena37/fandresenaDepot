<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.io.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>accueil</title>
<link href="http://localhost:8080/agenda/accueilCSS1.css" rel="stylesheet"/>
</head>
<body>
	<header class="tete">
		<div class="agenda">
			<h1>AGENDA</h1>
			<p style="margin-left:40px">Bienvenue a vous <strong>
			<% 
			 String filePath = "login.txt";
			String line = "text";
			try{
			FileReader fr = new FileReader(filePath);
			 BufferedReader br = new BufferedReader(fr);
			// Stocker le contenu du fichier dans une variable String
			line = br.readLine();
			out.println(line);
			br.close();
			fr.close();
			}
			catch(Exception e){
				line = "erreur";
			}
			%>
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
			<a style="text-decoration:none" href="http://localhost:8080/agenda/AfficheEvent?name=<%=line%>">
				<button class="btn">Voir les evenements</button>
			</a>
			<a style="text-decoration:none" href="http://localhost:8080/agenda/genereAgenda">
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