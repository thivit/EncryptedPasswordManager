#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include <vector>
using namespace std;

struct Credential {
    string service;
    string username;
    string password;
};

class FileManager {
public:
    // write a single line to file
    static bool writeToFile(string filename, string line);

    // read all lines from file
    static vector<string> readFromFile(string filename);

    // save credential to file
    static bool saveCredential(string filename, Credential cred);

    // load credentials from file
    static vector<Credential> loadCredentials(string filename);

    // delete credential
    static bool deleteCredential(string filename, string service);
};

#endif