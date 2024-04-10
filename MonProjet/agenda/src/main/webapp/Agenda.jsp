<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Agenda</title>
</head>
<body>
	<%
	Calendar calendar = Calendar.getInstance();
	int mois = calendar.get(Calendar.MONTH); // mois commence à 0
	int annee = calendar.get(Calendar.YEAR);
	calendar.set(Calendar.MONTH,mois);
	calendar.set(Calendar.YEAR, annee);// mois commence à 0

	int nbJours = calendar.getActualMaximum(Calendar.DAY_OF_MONTH);

	for (int i = 0; i < nbJours; i++) {
	  calendar.set(Calendar.DAY_OF_MONTH, i + 1);
	  out.println("<p>"+calendar.getTime()+"</p>");
	  // Traitez la date ici (par exemple, affichage, ajout à une liste, etc.)
	%>
</body>
</html>