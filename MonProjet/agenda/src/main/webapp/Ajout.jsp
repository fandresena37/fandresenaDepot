<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import="java.io.*" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Ajout d'evenement</title>
<link href="loginCSS.css" rel="stylesheet"/>
</head>
<body>
	<% 
		String jour = request.getParameter("jour");
		String mois = request.getParameter("mois");
		String annee = request.getParameter("annee");
		if(Integer.parseInt(jour)<10){
			jour="0"+jour;
		}
		if(Integer.parseInt(mois)<10){
			mois="0"+mois;
		}
		String date = jour+"/"+mois+"/"+annee;
		String filePath = "login.txt";
			String line = "text";
			try{
			FileReader fr = new FileReader(filePath);
			 BufferedReader br = new BufferedReader(fr);
			// Stocker le contenu du fichier dans une variable String
			line = br.readLine();
			br.close();
			fr.close();
			}
			catch(Exception e){
				line = "erreur";
			}
	%>
	<form action="http://localhost:8080/agenda/AjoutDB" method="post" class="form1"/>
		<div class="div-form">
			<h2 style="margin-top:20px">AJOUT D'EVENEMENT</h2>
			<div class="input2">date de l'evenement</div>
			<input type="text" name="dateEvent" placeholder="jj/mm/aa" class="input1" value="<%=date%>" readOnly>
			<div class="input2">l'evenement</div>
			<input type="text" name="Event" placeholder="l'evenement" class="input1" required>
			<div class="input2">description</div>
			<input type="text" name="description" placeholder="description de l'evenement" class="input1" required>
			<div class="input2">proprietaire</div>
			<input type="text" name="proprietaire" placeholder="proprietaire" class="input1" value="<%=line %>" readOnly>
			<div class="input2">date de creation</div>
			<input type="text" name="dateCreate" placeholder="date de creation" class="input1" required>
			<input type="submit" class="sub" value="Ajouter" style="margin-bottom:30px"/>
		</div>
	</form>	
</body>
</html>