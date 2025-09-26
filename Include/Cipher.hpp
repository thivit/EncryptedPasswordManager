#ifndef CIPHER_HPP
#define CIPHER_HPP
#include <string>

using namespace std;

class Cipher {
    public:
    static string encrypt(string plaintext, string key);

    static string decrypt(string ciphertext, string key);
};

#endif
