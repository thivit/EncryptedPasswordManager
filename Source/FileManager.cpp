#include "../Include/FileManager.hpp"

#include <fstream>     
#include <sstream>      
#include <iostream>     

static bool writeToFile(string filename, string line)
{
    ofstream file(filename, ios::app);
    if (!file.is_open())
        return false;
    
    file << line << "\n";

    return true;
}

static vector<string> readFromFile(string filename)
{
    vector<string> lines;
    string line;

    ifstream file(filename);
    while (getline(file, line))
        lines.push_back(line);

    return lines;
}

static bool saveCredential(string filename, Credential cred)
{
    ofstream file(filename, ios::app);
    if (!file.is_open())
        return false;
    
    file << cred.service << "," << cred.username << "," << cred.password << "/n";

    return true;
}

static vector<Credential> loadCredentials(string filename)
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
                creds.push_back({service, username, password});
            }
    }

    return creds;
}

static bool deleteCredential(string filename, string service)
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
    for (string line : lines)
        outFile << line << "/n";

     return found;
}

