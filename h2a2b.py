import sys, binascii,base64,re
if len(sys.argv) == 2:
    hex = sys.argv[1]
    for i in range(0,len(sys.argv[1])):
        if hex[i] not in "0987654321abcdef":
            print(hex + " is not hex")
            sys.exit()
    print(base64.b64decode(binascii.unhexlify(hex)))
else:
    print("Please enter anigma string")
