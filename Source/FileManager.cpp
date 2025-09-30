#include "../Include/FileManager.hpp"
#include "../Include/Cipher.hpp"

#include <fstream>     
#include <sstream>      
#include <iostream>     

// general functions
bool                FileManager::writeToFile        (string filename, string line)
{
    ofstream file(filename, ios::app);
    if (!file.is_open())
        return false;
    
    file << line << "\n";

    return true;
}
vector<string>      FileManager::readFromFile       (string filename)
{
    vector<string> lines;
    string line;

    ifstream file(filename);
    while (getline(file, line))
        lines.push_back(line);

    return lines;
}

// credential functions
bool                FileManager::saveCredential     (string filename, Credential cred, string key)
{
    ofstream file(filename, ios::app);
    if (!file.is_open())
        return false;

    string encryptedUsername = Cipher::encrypt(cred.username, key);
    string encryptedPassword = Cipher::encrypt(cred.password, key);
    
    file << cred.service << "," << encryptedUsername << "," << encryptedPassword << "\n";

    return true;
}
vector<Credential>  FileManager::loadCredentials    (string filename, string key)
{
    vector<Credential> creds;
    string line;

    ifstream file(filename);
    while (getline(file, line)) 
    {
        stringstream ss(line);
        string service;
        string username;
        string password;
        
        if (getline(ss, service, ',') && 
            getline(ss, username, ',' ) && 
            getline(ss, password, ',')) {
                string decryptedUsername = Cipher::decrypt(username, key);
                string decryptedPassword = Cipher::decrypt(password, key);
                creds.push_back({service, decryptedUsername, decryptedPassword});
            }
    }

    return creds;
}
bool                FileManager::deleteCredential   (string filename, string service)
{
    ifstream file(filename);
    if (!file.is_open())
        return false;

    vector<string> lines;
    string line;
    bool found = false;

    while (getline(file,line)) {
        if (line.rfind(service + ",", 0) != 0)
            lines.push_back(line);
        else
            found = true;
    }

    file.close();

    ofstream outFile(filename, ios::trunc);
    for (string l : lines)
        outFile << l << "\n";

     return found;
}
bool                FileManager::updateCredential   (string filename, string service, Credential newCred, string key)
{
    ifstream file(filename);
    if (!file.is_open())
        return false;

    vector<string> lines;
    string line;
    bool updated = false;

    while (getline(file, line))
    {
        if (line.rfind(service + ",", 0) == 0)
        {
            string encryptedUsername = Cipher::encrypt(newCred.username, key);
            string encryptedPassword = Cipher::encrypt(newCred.password, key);
            stringstream ss;
            ss << newCred.service << "," << encryptedUsername << "," << encryptedPassword;
            lines.push_back(ss.str());
            updated = true;
        }
        else
        {
            lines.push_back(line);
        }
    }

    file.close();

    if (!updated)
        return false;

    ofstream outFile(filename, ios::trunc);
    if (!outFile.is_open())
        return false;

    for (string l : lines)
        outFile << l << "\n";

    return true;
}
Credential          FileManager::findCredential     (string filename, string service, bool& found, string key)
{
    ifstream file(filename);
    
    Credential cred;
    found = false;

    if (!file.is_open())
        return cred;

    string line;

    while (getline(file, line))
    {
        if (line.rfind(service + ",", 0) == 0)
        {
            stringstream ss(line);
            string service;
            string username;
            string password;

            if (getline(ss, service, ',') &&
                getline(ss, username, ',') &&
                getline(ss, password, ','))
                {
                    cred.service = service;
                    cred.username = Cipher::decrypt(username, key);
                    cred.password = Cipher::decrypt(password, key);
                    found = true;
                    break;
                }
        }
    }

    return cred;
}
vector<string>      FileManager::listServices       (string filename)
{
    ifstream file(filename);
    
    vector<string> services;

    if (!file.is_open())
        return services;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);
        string service;
        if (getline(ss, service, ','))
            services.push_back(service);
    }

    return services;
}