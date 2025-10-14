#ifndef CIPHER_HPP
#define CIPHER_HPP
#include <string>

using namespace std;

class Cipher {
    public:
    static string vigenereEncrypt(string plaintext, string key);
    static string vigenereDecrypt(string ciphertext, string key);

    static string caesarEncrypt(string plaintext, string shift);
    static string caesarDecrypt(string ciphertext, string shift);

    static string railFenceEncrypt(string plaintext, string noOfRails);
    static string railFenceDecrypt(string ciphertext, string noOfRails);
};

#endif
