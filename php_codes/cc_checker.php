<?php
require_once 'braintreesdk/lib/Braintree.php';

$gateway = new Braintree\Gateway([
    'environment' => 'production', // braintree production keys
    'merchantId' => '',
    'publicKey' => '',
    'privateKey' => ''
]);

//best option list(), you only need change the delimeter.
list($num, $month, $year, $sec) = explode("|", $_GET['lista'], 4);

//random amount min = 0.xx, max = 5;
$amount = mt_rand(1*10, 5*10)/10;
$data = json_decode($requests::get('https://randomuser.me/api/'));

$result = $gateway->transaction()->sale([
    'amount' => $amount,
    'creditCard' => [
        'number' => $num,
        'expirationDate' => "$month/$year",
        'cvv' => $sec,
    ],
    'customer' => [
        'firstName' => $data->results[0]->name->first,
        'lastName' => $data->results[0]->name->last
    ],
    'options' => [
      'submitForSettlement' => true
    ],
    'billing' => [
        'postalCode' => $data->results[0]->location->postcode
    ]
]);

$msg = array(
    'approved' => $result->success, 
    'responsecode' => $result->transaction->networkResponseCode, 
    'responsetext' => $result->transaction->networkResponseText, 
    'cvv' => $result->transaction->cvvResponseCode, 
    'reject' => $result->transaction->gatewayRejectionReason, 
    'amount' => amount, 
    'processorcode' => $result->transaction->processorResponseCode, 
    'processortext' => $result->transaction->processorResponseText
);

header("Content-type: application/json; charset=utf-8");
echo json_encode($msg);

?>
 