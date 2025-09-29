#include "../Include/FileManager.hpp"

#include <fstream>      // reading / writing files
#include <sstream>      // spiliting strings
#include <iostream>     // debugging / printing messages

// write a single line to file
static bool writeToFile(string filename, string line) {
    // append mode (open file for writing)
    ofstream file(filename, ios::app);
    // check if file failed to open
    if (!file.is_open())
        return false;
    // write line to file
    file << line << "\n";
    return true;
}

// read all lines from file
static vector<string> readFromFile(string filename) {
    // create container to store lines
    vector<string> lines;
    // open file for reading
    ifstream file(filename);
    // temp variable to hold current line
    string line;
    // store file line by line into container
    while (getline(file, line))
        lines.push_back(line);
    return lines;
}

// save credential to file
static bool saveCredential(string filename, Credential cred) {
    // append mode (open file for writing)
    ofstream file(filename, ios::app);
    // check if file failed to open
    if (!file.is_open())
        return false;
    // write comma seperated line
    file << cred.service << "," << cred.username << "," << cred.password << "/n";
    return true;
}

// load credentials from file
static vector<Credential> loadCredentials(string filename) {
    // create container to store credentials
    vector<Credential> creds;
    // open file for reading
    ifstream file(filename);
    // temp variable to hold current line
    string line;
    // read file line by line
    while (getline(file, line)) {
        stringstream ss(line);
        string service;
        string username;
        string password;
        // ensure all three parts are found before reading
        if (getline(ss, service, ',') && 
            getline(ss, username, ',' ) && 
            getline(ss, password, ',')) {
                creds.push_back({service, username, password});
            }
    }
    return creds;
}

// delete credential
static bool deleteCredential(string filename, string service) {
    // open file for reading
    ifstream file(filename);
    // check if file failed to open
    if (!file.is_open())
        return false;

    vector<string> lines;
    string line;
    bool found = false;

    while (getline(file,line)) {
        // check if line does not start with the matchig service
        if (line.rfind(service + ",", 0) != 0) {
            // keep everything except matching entries
            lines.push_back(line);
        } else {
            found = true;
        }
    }
    file.close();

    // rewrite file with kept entries (truncate mode clears files contents)
    ofstream outFile(filename, ios::trunc);
    for (string line : lines)
    {
        outFile << line << "/n";
    }

     return found;
}

