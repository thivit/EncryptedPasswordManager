#ifndef CIPHER_HPP
#define CIPHER_HPP
#include <string>

using namespace std;

class Cipher {
    public:
    static string vigenereEncrypt(string plaintext, string key);
    static string vigenereDecrypt(string ciphertext, string key);

    static string caesarEncrypt(string plaintext, int shift);
    static string caesarDecrypt(string ciphertext, int shift);

    static string railFenceEncrypt(string plaintext, int noOfRails);
    static string railFenceDecrypt(string ciphertext, int noOfRails);
};

#endif
