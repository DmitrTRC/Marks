#include <iostream>


void log_menu () {
//TODO:  Arisha,  add your code here
//* Menu example:
//*  Logging menu
//* 1. Add Entry
//* 2. Delete Entry
//* 3. Print Entries
//* 4. Exit
//* Enter your choice:
//end


    std::cout << "Menu:" << std::endl;
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