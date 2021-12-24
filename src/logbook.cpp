//
// Created by Dmitry Morozov on 22.12.2021.
//
#include <iomanip>
#include "logbook.h"
#include "screen_util.h"


int Logbook::showMenu () {
    clearScreen (10);
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

void Logbook::run () {
    bool exit_flag = false;
    while (!exit_flag) {
        int choice = showMenu ();

        switch (choice) {
            case 1:
                std::cout << "Add a new entry for logbook." << std::endl;
                addMark ();
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

void Logbook::addMark () {
    std::cout << "Select subject for mark: " << std::endl;

    for (auto &[index, subject]: Mark::getSubjects ()) {
        std::cout << std::setw (2) << std::right << index << ". " << std::setw (40) << subject << std::right
                  << std::endl;
    }

    std::cout << "Enter your choice or press ENTER to cancel in range  0 - " << subjectMap.size () - 1 << ": ";
    int choice;
    std::cin >> choice;
    while (static_cast <char> (choice) != 'q') {
        if (choice < 0 || choice >= subjectMap.size ()) {
            std::cout << "Invalid choice" << std::endl;
        }
    }
}

