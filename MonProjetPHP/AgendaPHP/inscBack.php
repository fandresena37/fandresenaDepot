<?php
$conn = new mysqli("localhost", "fandresena", "Azerty123!", "agenda");

// Vérifier la connexion
if ($conn->connect_error) {
  die("Échec de la connexion à la base de données : " . $conn->connect_error);
}
else{
    echo "ato";
}
$sql = "INSERT INTO login (user,password) VALUES (?, ?)";

// Préparer la requête
echo $sql;
$stmt = $conn->prepare($sql);
// Lier les valeurs aux paramètres
$stmt->bind_param("ss", $_POST["user"], $_POST["pass"]);

$stmt->execute();

// Vérifier si l'insertion a réussi
if ($stmt->affected_rows > 0) {
  header("Location: http://www.agenda.mg/index.html");
} else {
  header("Location: http://www.agenda.mg/inscription.html");
}

// Fermer la requête préparée
$stmt->close();
$conn->close();
?>