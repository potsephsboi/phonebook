#include "../include/operations.hpp"


std::map<std::string, std::string> entries;

bool search(std::string& findName, std::string& result){
    std::ifstream inFile;
    inFile.open("../entries.txt");

    std::string line;
    while (std::getline(inFile, line)){
        std::string name;
        std::istringstream iss(line);
        iss >> name;
        if (name == findName){
            iss >> result;
            inFile.close();
            return true;
            
        }
    }

    inFile.close();
    return false;
}

void add(std::string& name, std::string& phone){
    entries[name] = phone;
    sortEntries();
}


void eraseAll(){
    entries.clear();
    std::ofstream outFile;
    outFile.open("../entries.txt", std::ios::trunc);
    outFile.close();
}

void remove(const std::string& remName){
    entries.erase(remName);
    sortEntries();
}

void sortEntries(){
    std::ofstream outFile;
    outFile.open("../entries.txt", std::ios::trunc);
    outFile.close();

    outFile.open("../entries.txt", std::ios::app);

    for (const auto& pair : entries){
        outFile << pair.first << " " << pair.second << '\n';

    }

    outFile.close();

}