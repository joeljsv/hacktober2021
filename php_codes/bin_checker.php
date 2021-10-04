<?php

$url = "https://lookup.binlist.net/";

$bin = readline("Input your credit card first 6 digits : ");
$data = file_get_contents($url.$bin);
$data = json_decode($data);

$text = "
CARD BIN : ".$bin."
CARD BRAND : ".$data->scheme."
CARD BANK : ".$data->bank->name."
CARD COUNTRY: ".$data->country->alpha2."
CARD CURRENCY: ".$data->country->currency."\n";

echo $text;