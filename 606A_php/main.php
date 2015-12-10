<?php 

$handle = fopen("php://stdin", "r");
fscanf($handle, "%d %d %d", $a, $b, $c);
fscanf($handle, "%d %d %d", $x, $y, $z);

//echo $a . " " . $b . " " . $c . "\n";
//echo $x . " " . $y . " " . $z . "\n";

$d_a = ($x - $a);
$d_b = ($y - $b);
$d_c = ($z - $c);

$m_a = $d_a > 0 ? $d_a : 0;
$m_b = $d_b > 0 ? $d_b : 0;
$m_c = $d_c > 0 ? $d_c : 0;
$m = $m_a + $m_b + $m_c;

//echo $m_a . " " . $m_b . " " . $m_c . "\n";

$e_a = -$d_a > 0 ? floor(-$d_a / 2) : 0;
$e_b = -$d_b > 0 ? floor(-$d_b / 2) : 0;
$e_c = -$d_c > 0 ? floor(-$d_c / 2) : 0;

$e = $e_a + $e_b + $e_c;

//echo $e_a . " " . $e_b . " " . $e_c . "\n";

echo $e >= $m ? "Yes\n" : "No\n"

?>