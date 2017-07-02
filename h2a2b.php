<?php
function hex2str($hex) {
    $str = '';
    for($i=0;$i<strlen($hex);$i+=2) $str .= chr(hexdec(substr($hex,$i,2)));
    return $str;
}

print("\n");
if (count($argv) == 2){
    $hex = $argv[1];
    if (ctype_xdigit($hex)){
      print(base64_decode(hex2str($hex)));
    }else{
      print($hex . " is not hex");
  }}else{
    print("Please enter anigma string");
}
print("\n");
