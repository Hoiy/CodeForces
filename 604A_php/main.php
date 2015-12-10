<?php 

$handle = fopen("php://stdin", "r");
$m = array_fill(0, 5, 0);
$w = array_fill(0, 5, 0);
$x = array(500, 1000, 1500, 2000, 2500);
fscanf($handle, "%d %d %d %d %d", $m[0], $m[1], $m[2], $m[3],$m[4]);
fscanf($handle, "%d %d %d %d %d", $w[0], $w[1], $w[2], $w[3],$w[4]);
fscanf($handle, "%d %d", $hs, $hu);
fclose($handle);

$score = 0;
for($i = 0; $i < 5; ++$i) {
	$score += max($x[$i] * 3 / 10, (250 - $m[$i]) * $x[$i] / 250 - 50 * $w[$i]);
}
$score += $hs * 100;
$score -= $hu * 50;

echo $score, "\n";

?>