<html>
<head>
	<title>SUPER PAGINA</title>
</head>
<body>
<?php
include "/phpqrcode/qrlib.php";

echo '<img src="http://juegosvestirfamososcantantes.com/wp-content/uploads/2010/04/brad-pitt-foto.jpg" alt="YO, EL FACHERO">';

// how to build raw content - QRCode with simple Business Card (VCard)
$tempDir = "./tempfiles/";
// here our data
$name = 'Fernando';
$phone = '(011)4666-2598';
$email = 'supermail@gmail.com';
// we building raw data
$codeContents = 'BEGIN:VCARD'."\n";
$codeContents .= 'FN:'.$name."\n";
$codeContents .= 'TEL;WORK;VOICE:'.$phone."\n";
$codeContents .= 'EMAIL:'.$email."\n";
$codeContents .= 'END:VCARD';
// generating
QRcode::png($codeContents, $tempDir.'025.png');
// displaying
//echo '<img src="'.$tempDir.'025.png'>
echo '<img src="'.$tempDir.'025.png"/>';

?>
</body>
</html>