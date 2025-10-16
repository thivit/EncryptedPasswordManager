#include "Cipher.cpp"

#include <iostream>

using namespace std;

int main() {
    string plaintext, key, ciphertext, decrypted;

    // ===== CAESAR CIPHER =====
    plaintext = "HELLO WORLD";
    int caesarShift = 3;

    ciphertext = Cipher::caesarEncrypt(plaintext, caesarShift);
    decrypted = Cipher::caesarDecrypt(ciphertext, caesarShift);

    cout << "CAESAR CIPHER\n";
    cout << "Plaintext:  " << plaintext << endl;
    cout << "Encrypted:  " << ciphertext << endl;
    cout << "Decrypted:  " << decrypted << "\n\n";

    // ===== VIGENERE CIPHER =====
    plaintext = "HELLO WORLD";
    key = "KEY";

    ciphertext = Cipher::vigenereEncrypt(plaintext, key);
    decrypted = Cipher::vigenereDecrypt(ciphertext, key);

    cout << "VIGENERE CIPHER\n";
    cout << "Plaintext:  " << plaintext << endl;
    cout << "Key:        " << key << endl;
    cout << "Encrypted:  " << ciphertext << endl;
    cout << "Decrypted:  " << decrypted << "\n\n";

    // ===== RAIL FENCE CIPHER =====
    plaintext = "HELLO WORLD";
    int rails = 4;

    ciphertext = Cipher::railFenceEncrypt(plaintext, rails);
    decrypted = Cipher::railFenceDecrypt(ciphertext, rails);

    cout << "RAIL FENCE CIPHER\n";
    cout << "Plaintext:  " << plaintext << endl;
    cout << "Rails:      " << rails << endl;
    cout << "Encrypted:  " << ciphertext << endl;
    cout << "Decrypted:  " << decrypted << endl;

    return 0;
}
