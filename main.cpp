#include <iostream>

#include <iostream>
#include <string>


std::string log_menu () {
//* Menu example:
//*  Logging menu
//* 1. Add Entry
//* 2. Delete Entry
//* 3. Print Entries
//* 4. Exit
//* Enter your choice:

std::cout << "Menu:" << std::endl;
std::cout << "Marks" << std::endl;
std::cout << "Add Marks" << std::endl;
std::cout << "Delete Marks" << std::endl;
std::cout << "Exit" << std::endl;
std::cout << "Enter your choice: " << std::endl;
std::string choice;
std::cin >>choice;
return choice;
};

   


// 2 Modes : Console and Interactive
int main (int argc, char *argv[]) {
    if (argc >= 2) {
        std::cout << "Console mode" << std::endl;
        for (int i = 1; i < argc; i++) {
            std::cout << argv[i] << std::endl;
        }
    } else {
        std::cout << "Interactive mode" << std::endl;
        log_menu ();
    }
    return 0;
}
