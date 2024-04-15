<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="./afficheCSS.css" rel="stylesheet"/>
    <title>affichage</title>
</head>
<body>
<html>
    <table class="table-affiche">
    <tr>
        <td class="entete">Date de l'evenement</td>
        <td class="entete">Evenement</td>
        <td class="entete">Desciption</td>
        <td class="entete">Proprietaire</td>
        <td class="entete">Date d'ajout</td>
    </tr>
    <?php
    session_start();
    $user = $_SESSION["user"];
    $conn = mysqli_connect("localhost", "fandresena", "Azerty123!", "agenda");
     if($conn){
         $sql = "SELECT * FROM ".$user;
         $result = mysqli_query($conn, $sql);
         while($row = mysqli_fetch_assoc($result)){
            echo "<tr>";
            echo "<td>".$row["date"]."</td>";
            echo "<td>".$row["event"]."</td>";
            echo "<td>".$row["description"]."</td>";
            echo "<td>".$row["proprietaire"]."</td>";
            echo "<td>".$row["date_de_creation"]."</td>";
            echo "</tr>";    
            }
        }
    ?>
    </table>
</body>
</html>