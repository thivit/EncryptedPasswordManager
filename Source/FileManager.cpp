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

}

// load credentials from file
static vector<Credential> loadCredentials(string filename) {

}

// delete credential
static bool deleteCredential(string filename, string service) {

}

