function check(hex) {
  return new Promise(function(resolve, reject) {
    for (i = 0; i < hex.length; i++) {
      if (r.search(hex.charAt(i)) == -1) {
        reject(false);
      }
    }
    resolve(true);
  });
}

function hex_to_ascii(str1)
 {
	var hex  = str1.toString();
	var str = '';
	for (var n = 0; n < hex.length; n += 2) {
		str += String.fromCharCode(parseInt(hex.substr(n, 2), 16));
	}
	return str;
 }

if (process.argv.length === 3) {
  hex = process.argv[2];
  r = "0987654321abcdef";
  check(hex).then(function(data) {
    console.log(Buffer(hex_to_ascii(hex),'base64').toString('ascii'));
  }, function(error) {
    console.log(hex + " is not hex")
  });

} else {
  console.log("Please enter one anigma string each time");
};
