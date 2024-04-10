<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Insert title here</title>
</head>
<style>
*{
	margin:0;
	padding:0;
	box-sizing: border-box;
	font-family: 'Open Sans',sans-serif;
}
body{
	height: 100vh;
	width: 100vw;
	background: linear-gradient(to right,blue,aqua);
	display:flex;
	justify-content:center;
	align-items:center;
}
.div{
	height:50%;
	width:40%;
	border-radius:10px;
	background-color:white;
	box-shadow:0px 0px 3px gray;
	display:flex;
	flex-direction:column;
	justify-content:center;
	align-items:center;
}
p{
	font-size:20px;
	color:gray;
}
a{
	height:40px;
	width:150px;
	text-decoration:none;
}
button{
	height:100%;
	width:100%;
	background-color:red;
	margin-top:30px;
	border-radius:20px;
	border:none;
}
h1{
	color:red;
	margin-bottom:30px;
}
</style>
<body>
	<div class="div">
	<h1>ECHEC</h1>
	<p>Ajout de l'evenement a echouer</p>
	<a href="http://localhost:8080/agenda/accueilJSP.jsp" ><button>Accueil</button></a>
	</div>	
</body>