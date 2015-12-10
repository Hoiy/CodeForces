<?php 

fscanf(STDIN, "%d %d\n", $n, $k);
//echo "n: $n, k: $k\n";

$s = array_fill(0, $n, 0);
$str = fgets(STDIN);
//echo $str;

$s = explode(" ", $str);
foreach($s as $key => $value) {
	$s[$key] = intval($value);
}

$mins = 0;
$b = array_fill(0, $k, 0);
for($i = 0; $i < $k && $i < $n; ++$i) {
	$b[$i] += $s[$n-$i-1];
	if($b[$i] > $mins) {
		$mins = $b[$i];
		//echo $b[$i], "oo\n";
	}
}
$idx = $k-1;
for($i = $k; $i < $n; ++$i) {
	$b[$idx] += $s[$n-$i-1];
	if($b[$idx] > $mins) {
		$mins = $b[$idx];
		//echo $b[$idx], "hi\n";
	}
	$idx--;
}

echo $mins, "\n";

?>