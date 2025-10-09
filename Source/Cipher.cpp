#include "../Include/Cipher.hpp"

#include "../Include/Cipher.hpp"

string Cipher::encrypt(string plaintext, string key) {
    string ciphertext = plaintext;
    size_t keyLength = key.size();

    for (size_t i = 0; i < plaintext.size(); i++) {
        char p = (plaintext[i] - 'A');
        char k = (key[i % keyLength] - 'A');
        ciphertext[i] = (p + k) % 26 + 'A';
    }

    return ciphertext;
}

string Cipher::decrypt(string ciphertext, string key) {
    string plaintext = ciphertext;
    size_t keyLength = key.size();

    for (size_t i = 0; i < ciphertext.size(); i++) {
        char c = (ciphertext[i] - 'A');
        char k = (key[i % keyLength] - 'A');
        plaintext[i] = (c - k + 26) % 26 + 'A';
    }

    return plaintext;
}
