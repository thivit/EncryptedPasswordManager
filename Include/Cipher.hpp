#ifndef CIPHER_HPP
#define CIPHER_HPP
#include <string>

using namespace std;

class Cipher {
    public:
    static string vigenereEncrypt(string plaintext, string key);

    static string vigenereDecrypt(string ciphertext, string key);
};

#endif
