<?php
session_start();
// Créer une connexion
$conn = new mysqli("localhost", "fandresena", "Azerty123!", "agenda");

// Vérifier la connexion
if ($conn->connect_error) {
  die("Échec de la connexion à la base de données : " . $conn->connect_error);
}
else{
    echo "ato";
}
$sql = "INSERT INTO ".$_SESSION["user"]." (date,event,description,proprietaire,date_de_creation) VALUES (?, ?, ?, ?, ?)";

// Préparer la requête
echo $sql;
$stmt = $conn->prepare($sql);
// Lier les valeurs aux paramètres
$stmt->bind_param("sssss", $_POST["dateEvent"], $_POST["Event"], $_POST["description"], $_POST["proprietaire"],$_POST["dateCreate"]);

$stmt->execute();

// Vérifier si l'insertion a réussi
if ($stmt->affected_rows > 0) {
  echo "Données insérées avec succès.";
  header("Location: http://www.agenda.mg/AjoutReu.php");
} else {
  header("Location: http://www.agenda.mg/AjoutEu.php");
}

// Fermer la requête préparée
$stmt->close();
$conn->close();

?>