#include <string>
#include <fstream>
#include <sstream>
#include <map>

extern std::map<std::string, std::string> entries;


bool search(std::string& name, std::string& result);
void add(std::string& name, std::string& phone);
void remove(const std::string& name);
void eraseAll();
void sortEntries();