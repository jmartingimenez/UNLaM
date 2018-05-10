<?php
define('DB_SERVER', 'localhost');
define('DB_SERVER_USERNAME', 'your_username');
define('DB_SERVER_PASSWORD', 'your_password');
define('DB_DATABASE', 'your_database');

$con = mysql_connect(DB_SERVER, DB_SERVER_USERNAME, DB_SERVER_PASSWORD);
mysql_select_db(DB_DATABASE, $con);

?>