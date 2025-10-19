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
    static bool writeToFile (string filename, string line);  
    static vector<string> readFromFile (string filename); 
    
    // credential functions
    static bool saveCredential (string filename, Credential cred);
    static bool deleteCredential (string filename, string service);
    static bool updateCredential (string filename, string service, Credential newCredy);
    static Credential findCredential (string filename, string service, bool& found);
    static vector<string> listServices (string filename);
    static vector<Credential> loadCredentials (string filename);
};

#endif