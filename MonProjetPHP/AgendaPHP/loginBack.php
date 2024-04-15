<?php
    $user = $_POST["user"];
    $pass = $_POST["pass"];
    $userDB = null;
    $passDB = null;
    $conn = mysqli_connect("localhost", "fandresena", "Azerty123!", "agenda");
    if($conn){
        $sql = "SELECT * FROM login";
        $result = mysqli_query($conn, $sql);
        while($row = mysqli_fetch_assoc($result)){
            if(strcmp($user,$row["user"])==0 && strcmp($pass,$row["password"])==0){
                header("Location: http://www.agenda.mg/accueil.php");
                session_start();
                $_SESSION["user"] = $user;
            }
            }
        }
?>