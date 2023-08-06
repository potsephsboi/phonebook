#include "../include/userInteract.hpp"
#include "../include/operations.hpp"


std::unordered_set<std::string> commands = {"del", "add", "find", "remAll"};


void initTool(){
    std::cout << "Welcome to phonebook tool.\n This tool can help you manipulate your contacts.\n You can add, delete, or searchfor a contact.\n";
    std::cout << "The commands are:\n find [entry to find (specify the name)]\n add [name to add]-[phone of specified name]\n remAll (clears all entries)\n del [entry name]\n-------\n";
}

void getInOut(){
    while (true){
        std::string cmdFull;
        std::getline(std::cin, cmdFull);
        

        if (cmdFull == "exit")
            break;
        
        else{
            std::string cmd;
            std::istringstream iss(cmdFull);
            iss >> cmd;

            if (commands.find(cmd) == commands.end())
                std::cout << "Invalid command. Try again.\n";
            
            if (cmd == "find") {
                std::string searchRes;
                std::string arg;
                iss >> arg;
                if(search(arg, searchRes))
                    std::cout << "Number corresponding to given name: " << searchRes << '\n';
                else
                    std::cout << "Given name not found.\n";
            } 
            else if (cmd == "add") {
                std::string temp;
                std::string arg1, arg2;
                iss >> arg1 >> arg2;
                if (arg2.size() > 10)
                    std::cout << "Phone length must be less or equal to 10\n";  
                else if (search(arg1, temp)){
                    std::cout << "Name already exists.\n";
                }
                else{
                    for (int i = 0; i < arg2.size(); ++i){
                        if (!std::isdigit(arg2[i])){
                            std::cout << "Phone must contain only numbers\n";
                            break;   
                        }
                        if (i == arg2.size()-1)
                            add(arg1, arg2);
                    }
                }
            } 
            else if (cmd == "del") {
                std::string temp;
                std::string arg1;
                iss >> arg1;
                if (search(arg1, temp)) {
                    remove(arg1);
                    std::cout << "Entry removed.\n";
                }
                else   
                    std::cout << "Entry to be removed not found.\n";
                
            }
            else if (cmd == "remAll") {
                eraseAll();
            }
        
            
        }
    }
}

