<?php 

$handle = fopen("php://stdin", "r");
fscanf($handle, "%d %d %d %d", $x, $y, $x0, $y0);
$cmd = trim(fgets($handle));
fclose($handle);
//echo $cmd, "\n";
//echo strlen($command), "\n";

$visited = array_fill(1, $x, array_fill(1, $y, false));
$t = $x * $y;

$visited[$x0][$y0] = true;
//echo $x0, " ", $y0, "\n";
echo "1 ";
$t--;

for($i = 0; $i < strlen($cmd); $i++) {
	//echo $cmd[$i], "\n";
	switch($cmd[$i]) {
		case "U":
			$x0 = ($x0 > 1) ? $x0 - 1 : $x0;
			break;
		case"D":
			$x0 = ($x0 < $x ) ? $x0 + 1 : $x0;
			break;
		case"L":
			$y0 = ($y0 > 1) ? $y0 - 1 : $y0;
			break;
		case "R":
			$y0 = ($y0 < $y ) ? $y0 + 1 : $y0;
			break;
	}
	//echo $x0, " ", $y0, "\n";
	if($i == strlen($cmd) - 1) { // last step
		echo $t, "\n";
	} else {
		if($visited[$x0][$y0]) {
			echo "0 ";
		} else {
			echo "1 ";
			$t --;
		}
	}
	$visited[$x0][$y0] = true;
}
?>