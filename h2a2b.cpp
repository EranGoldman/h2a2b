#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

static std::string base64_decode(const std::string &in) {

    std::string out;

    std::vector<int> T(256,-1);
    for (int i=0; i<64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;

    int val=0, valb=-8;
    for (char c : in) {
        if (T[c] == -1) break;
        val = (val<<6) + T[c];
        valb += 6;
        if (valb>=0) {
            out.push_back(char((val>>valb)&0xFF));
            valb-=8;
        }
    }
    return out;
}

int main(int argc, char *argv[])
{
  if (argc == 2) {
    std::string hex = argv[1];
    std::size_t found = hex.find_first_not_of("0987654321abcdef ");
    int len = hex.length();
    std::string newString;

    if (found!=std::string::npos)
    {
      std::cout << hex <<  " is not hex\n";
    }
    else {
      for(int i=0; i< len; i+=2)
      {
          std::string byte = hex.substr(i,2);
          char chr = (char) (int)strtol(byte.c_str(), NULL, 16);
          newString.push_back(chr);
      }
      std::cout << base64_decode(newString) << " \n";
    }
  }else{
    std::cout << "Please enter anigma string";
  }
}
