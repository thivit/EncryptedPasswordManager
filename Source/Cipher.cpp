
#include "../Include/Cipher.hpp"

#include "../Include/Cipher.hpp"
#include <cctype>
#include <algorithm>

using namespace std;

string Cipher::vigenereEncrypt(string plaintext, string key) {
    string ciphertext = plaintext;

    bool numericKey = all_of(key.begin(), key.end(), ::isdigit);
    int shift = numericKey ? stoi(key) % 26 : 0;

    for (auto &ch : key) ch = toupper(ch);

    for (size_t i = 0; i < plaintext.size(); i++) {
        char ch = plaintext[i];
        if (isalpha(ch)) {
            bool lower = islower(ch);
            char base = lower ? 'a' : 'A';
            int k = numericKey ? shift : (key[i % key.size()] - 'A');
            ciphertext[i] = ((ch - base + k) % 26) + base;
        } else {
            ciphertext[i] = ch;
        }
    }

    return ciphertext;
}

string Cipher::vigenereDecrypt(string ciphertext, string key) {
    string plaintext = ciphertext;

    bool numericKey = all_of(key.begin(), key.end(), ::isdigit);
    int shift = numericKey ? stoi(key) % 26 : 0;

    for (auto &ch : key) ch = toupper(ch);

    for (size_t i = 0; i < ciphertext.size(); i++) {
        char ch = ciphertext[i];
        if (isalpha(ch)) {
            bool lower = islower(ch);
            char base = lower ? 'a' : 'A';
            int k = numericKey ? shift : (key[i % key.size()] - 'A');
            plaintext[i] = ((ch - base - k + 26) % 26) + base;
        } else {
            plaintext[i] = ch;
        }
    }

    return plaintext;
}

// #include "../Include/Cipher.hpp"

// string Cipher::encrypt(string plaintext, string key) {
//     string ciphertext = plaintext;
//     size_t keyLength = key.size();

//     for (size_t i = 0; i < plaintext.size(); i++) {
//         char p = (plaintext[i] - 'A');
//         char k = (key[i % keyLength] - 'A');
//         ciphertext[i] = (p + k) % 26 + 'A';
//     }

//     return ciphertext;
// }

// string Cipher::decrypt(string ciphertext, string key) {
//     string plaintext = ciphertext;
//     size_t keyLength = key.size();

//     for (size_t i = 0; i < ciphertext.size(); i++) {
//         char c = (ciphertext[i] - 'A');
//         char k = (key[i % keyLength] - 'A');
//         plaintext[i] = (c - k + 26) % 26 + 'A';
//     }

//     return plaintext;
// }
