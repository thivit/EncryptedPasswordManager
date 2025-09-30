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
    // utility / general functions
    static bool writeToFile(string filename, string line);  
    static vector<string> readFromFile(string filename); 
    
    // credential functions
    static bool saveCredential(string filename, Credential cred);
    static vector<Credential> loadCredentials(string filename);
    static bool deleteCredential(string filename, string service);
};

#endif