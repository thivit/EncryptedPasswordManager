#include "../Include/Cipher.hpp"

string Cipher::vigenereEncrypt(string plaintext, string key) {
    string ciphertext = plaintext;
    size_t keyLength = key.size();

    for (size_t i = 0; i < plaintext.size(); i++) {
        char p = (plaintext[i] - 'A');
        char k = (key[i % keyLength] - 'A');
        if (plaintext[i] != ' '){
            ciphertext[i] = (p + k) % 26 + 'A';
        }
    }

    return ciphertext;
}

string Cipher::vigenereDecrypt(string ciphertext, string key) {
    string plaintext = ciphertext;
    size_t keyLength = key.size();

    for (size_t i = 0; i < ciphertext.size(); i++) {
        char c = (ciphertext[i] - 'A');
        char k = (key[i % keyLength] - 'A');
        if (ciphertext[i] != ' '){
            plaintext[i] = (c - k + 26) % 26 + 'A';
        }
    }

    return plaintext;
}

string Cipher::caesarEncrypt(string plaintext, string shift){
    string ciphertext = plaintext;
    int shiftInt = stoi(shift);

    for (size_t i = 0; i < plaintext.size(); i++) {
        char c = plaintext[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            ciphertext[i] = (c - base + shiftInt) % 26 + base;
        } else {
            ciphertext[i] = c;
        }
    }

    return ciphertext;
}

string Cipher::caesarDecrypt(string ciphertext, string shift){
    string plaintext = ciphertext;
    int shiftInt = stoi(shift);

    for (size_t i = 0; i < plaintext.size(); i++) {
        char c = ciphertext[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            ciphertext[i] = (c - base - shiftInt) % 26 + base;
        } else {
            ciphertext[i] = c;
        }
    }

    return plaintext;
}

string Cipher::railFenceEncrypt(string plaintext, string noOfRails) {
    int noOfRailsInt = stoi(noOfRails);
    if (noOfRails < 2) return plaintext;

    string ciphertext = "";
    int cycle = 2 * (noOfRailsInt - 1);
    int len = plaintext.size();

    for (int rail = 0; rail < noOfRailsInt; rail++) {
        for (int i = rail; i < len; i += cycle) {
            ciphertext += plaintext[i];
            int diag = i + cycle - 2 * rail;
            if (rail != 0 && rail != noOfRailsInt - 1 && diag < len)
                ciphertext += plaintext[diag];
        }
    }

    return ciphertext;
}

string Cipher::railFenceDecrypt(string ciphertext, string noOfRails) {
    int noOfRailsInt = stoi(noOfRails);
    if (noOfRails < 2) return ciphertext;

    string plaintext(ciphertext.size(), ' ');
    int cycle = 2 * (noOfRailsInt - 1);
    int len = ciphertext.size();
    int idx = 0;

    for (int rail = 0; rail < noOfRailsInt; rail++) {
        for (int i = rail; i < len; i += cycle) {
            plaintext[i] = ciphertext[idx++];
            int diag = i + cycle - 2 * rail;
            if (rail != 0 && rail != noOfRailsInt - 1 && diag < len)
                plaintext[diag] = ciphertext[idx++];
        }
    }

    return plaintext;
}


// #include "../Include/Cipher.hpp"

// #include "../Include/Cipher.hpp"
// #include <cctype>
// #include <algorithm>

// using namespace std;

// string Cipher::vigenereEncrypt(string plaintext, string key) {
//     string ciphertext = plaintext;

//     bool numericKey = all_of(key.begin(), key.end(), ::isdigit);
//     int shift = numericKey ? stoi(key) % 26 : 0;

//     for (auto &ch : key) ch = toupper(ch);

//     for (size_t i = 0; i < plaintext.size(); i++) {
//         char ch = plaintext[i];
//         if (isalpha(ch)) {
//             bool lower = islower(ch);
//             char base = lower ? 'a' : 'A';
//             int k = numericKey ? shift : (key[i % key.size()] - 'A');
//             ciphertext[i] = ((ch - base + k) % 26) + base;
//         } else {
//             ciphertext[i] = ch;
//         }
//     }

//     return ciphertext;
// }

// string Cipher::vigenereDecrypt(string ciphertext, string key) {
//     string plaintext = ciphertext;

//     bool numericKey = all_of(key.begin(), key.end(), ::isdigit);
//     int shift = numericKey ? stoi(key) % 26 : 0;

//     for (auto &ch : key) ch = toupper(ch);

//     for (size_t i = 0; i < ciphertext.size(); i++) {
//         char ch = ciphertext[i];
//         if (isalpha(ch)) {
//             bool lower = islower(ch);
//             char base = lower ? 'a' : 'A';
//             int k = numericKey ? shift : (key[i % key.size()] - 'A');
//             plaintext[i] = ((ch - base - k + 26) % 26) + base;
//         } else {
//             plaintext[i] = ch;
//         }
//     }

//     return plaintext;
// }






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
