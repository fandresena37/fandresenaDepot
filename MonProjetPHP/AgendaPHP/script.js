/**
 * 
 */
function changerMois(){
	let mois = document.getElementById("span").innerText;
	let p = document.getElementById("mois");
	let div = document.querySelector("#div");
	document.getElementById("annee").removeChild(document.getElementById("btn-annee"));
	div.removeChild(p);
	div.innerHTML=`<p>mois:<select id=\"sel\" onchange=\"changementMois()\">
					<option value=\"Janvier\">Janvier</option>
					<option value=\"Fevrier\">Fevrier</option>
					<option value=\"Mars\">Mars</option>
					<option value=\"Avril\">Avril</option>
					<option value=\"Mai\">Mai</option>
					<option value=\"Juin\">Jui</option>
					<option value=\"Juillet\">Juillet</option>
					<option value=\"Aôut\">Aôut</option>
					<option value=\"Septembre\">Septembre</option>
					<option value=\"Octobre\">Octobre</option>
					<option value=\"Novembre\">Novembre</option>
					<option value=\"Decembre\">Decembre</option>
					</select>`;
	document.getElementById("sel").value=mois
	document.getElementById("sel").style="height:35px;width:200px;font-size:25px;color:gray;background-color:white";
	
/*	console.log("ato");*/
}
function changerAnnee(){
	let annee = document.getElementById("span-annee").innerText;
	document.getElementById("mois").removeChild(document.getElementById("btn-mois"));
	let div = document.getElementById("id1");
	div.removeChild(document.getElementById("annee"));
	let child = "annee:<select id=\"sel\" onchange=\"changementAnnee()\">";
	for (let i=2000;i<2051;i++){
		let str = "<option value="+i+">"+i+"</option>";
		child+=str;
	}
	div.innerHTML=child+"</select>";
	console.log(annee);
	document.getElementById("sel").value=annee
	document.getElementById("sel").style="height:35px;width:200px;font-size:25px;color:gray;background-color:white";
		
	//let p = */
}
function changementMois(){
	let select = document.querySelector("select");
	let nb = getNbMois(select.value);
	let annee = parseInt(document.getElementById("span-annee").innerText);
	location.href="http://www.agenda.mg/AfficheAgenda.php?mois="+nb+"&annee="+annee+"";
	
}
function changementAnnee(){
	let select = document.querySelector("select");
	let mois = document.getElementById("span").innerText;
	let nb = getNbMois(mois);
	let annee = parseInt(select.value);
	location.href="http://www.agenda.mg/AfficheAgenda.php?mois="+nb+"&annee="+annee+"";
}
function getNbMois(Strmois){
	let nb;
	if(Strmois == "Janvier"){
	 	nb = "01";	
	}
	if(Strmois == "Fevrier"){
	 	nb = "02";	
	}
	if(Strmois == "Mars"){
	 	nb = "03";	
	}
	if(Strmois == "Avril"){
	 	nb = "04";	
	}
	if(Strmois == "Mai"){
	 	nb = "05";	
	}
	
	if(Strmois == "Juin"){
	 	nb = "06";	
	}
	if(Strmois == "Juillet"){
	 	nb = "07";	
	}
	if(Strmois == "Aôut"){
	 	nb = "08";	
	}
	if(Strmois == "Septembre"){
	 	nb = "09";	
	}
	if(Strmois == "Octobre"){
	 	nb = "10";	
	}
	if(Strmois == "Novembre"){
	 	nb = "11";	
	}
	if(Strmois == "Decembre"){
	 	nb = "12";	
	}
	return nb;
}