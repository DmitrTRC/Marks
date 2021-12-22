//
// Created by Dmitry Morozov on 22.12.2021.
//

#include "logbook.h"

int logbook_menu () {
    clear_screen ();
    std::cout << "Logbook Menu" << std::endl;
    std::cout << "1. Add Entry" << std::endl;
    std::cout << "2. View Entries" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "4. Generate JSON" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    return choice;
}

void clear_screen () {
    int ScreenRows = 50;
    std::cout << std::string (ScreenRows, '\n');
}

void logbook () {
    bool exit_flag = false;
    while (!exit_flag) {
        int choice = logbook_menu ();

        switch (choice) {
            case 1:
                std::cout << "Add a new entry" << std::endl;
                break;
            case 2:
                std::cout << "Search for an entry" << std::endl;

                break;
            case 3:
                std::cout << "Exiting" << std::endl;
                exit_flag = true;
                break;
            case 4:

                break;
            default:
                std::cout << "Invalid choice" << std::endl;
                break;
        }
    }
}

void logbook2 () {
    bool exit_flag = false; // Exit flag.  Do not use with while(true)
    while (!exit_flag) {
        int choice = logbook_menu ();
        if (choice == 1) {
            std::cout << "Add a new entry" << std::endl;
        } else if (choice == 2) {
            std::cout << "Search for an entry" << std::endl;
        } else if (choice == 3) {
            std::cout << "Exiting" << std::endl;
            exit_flag = true;
        } else {
            std::cout << "Invalid choice" << std::endl;
        }

    }
}
