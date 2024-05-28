<!DOCTYPE html>
<html>
    <head>
        <title>Cours PHP / MySQL</title>
        <meta charset="utf-8">
        <link rel="stylesheet" href="cours.css">
    </head>
    <body>
        <h1>Bases de données MySQL</h1>  
		<?php
		require_once 'db.php';

		$database = new database();
		$conn = $database->connection('localhost','root','123456','DAD');
		if($conn->connect_error){
			die('Erreur : ' .$conn->connect_error);
		}
		echo 'Connexion réussie'; 
		echo "<br>";
		
		if ( isset($_GET['Old']) AND !empty($_GET['Old']) && isset($_GET['News']) AND !empty($_GET['News']) )
		{
			$Old = $_GET['Old'];
			$New = $_GET['News'];
			
			$selectQuery="SELECT `ID_Type_Dechet`, `ID_Etat`, `Seuil` FROM Container WHERE ( RFID = '$Old')";
			$data=$database ->executerRequete($conn,$selectQuery);
			
			while ( $tab = mysqli_fetch_array($data) ){
				$ID_Type_Dechet = $tab['ID_Type_Dechet'];
				$ID_Etat = $tab['ID_Etat'];
				$Seuil = $tab['Seuil'];
			}
			echo "$ID_Type_Dechet<br/>$ID_Etat<br/>$Seuil";
			echo "<br>";
			echo $selectQuery;
			
			
			$updateQuery="UPDATE `Container` SET `ID_Type_Dechet`='$ID_Type_Dechet',`ID_Etat`='$ID_Etat',`Seuil`='$Seuil' WHERE ( RFID ='$New')";
			$data=$database ->executerRequete($conn,$updateQuery);
			echo "<br>";
			echo $updateQuery;
			
			$updateQuery="UPDATE `Container` SET `ID_Type_Dechet`='0',`ID_Etat`='0' ,`Seuil`='0' WHERE ( RFID ='$Old')";
			$data=$database ->executerRequete($conn,$updateQuery);
			echo "<br>";
			echo $updateQuery;

			mysqli_close($conn);
			
		}
		?>

    </body>
</html>
