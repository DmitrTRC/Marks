//
// Created by Dmitry Morozov on 22.12.2021.
//
#include <iomanip>
#include <cstdio>
#include "logbook.h"
#include "screen_util.h"


int Logbook::showMenu () {
    clearScreen (10);
    std::cout << "Logbook Menu" << std::endl;
    std::cout << "1. Add new Mark" << std::endl;
    std::cout << "2. View journal" << std::endl;
    std::cout << "3. Edit Mark" << std::endl;
    std::cout << "4. Generate report" << std::endl;
    std::cout << "5. Exit" << std::endl;

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


    int choice;
    getChoice (choice, 0, Mark::getSubjects ().size () - 1);

}

//TODO: Rewrite this function
bool Logbook::getChoice (int &choice_, int min, int max) {
    auto result = false;
    int choice_result (0);
    do {
        //std::cout << std::endl << "Enter your choice ( or 'q' to exit ) and press ENTER in range  " << min << " - " << max << ": ";
        puts ("Enter your choice ( or 'q' to exit ) and press ENTER in range  : ");
        choice_result = _readChoice (min, max);
        if (choice_result == -2) return result;
        if (choice_result == -1) {
            std::cout << "Invalid choice" << std::endl;
            continue;
        }
    } while (choice_result != -1);

}

int Logbook::_readChoice (int min, int max) {
    int choice = -1;
    std::string input;
    char letter;
    do {
        std::cin >> letter;

        if (letter == 'q') {
            //TODO: Replace to const
            choice = -2;
            break;
        }
        if (isdigit (letter) && _checkBounds ((letter), min, max)) {
            input += letter;
            choice = std::stoi (input);
        } else {
            putchar ('\b');
        }
    } while (letter != '\n');

    return choice;
}

bool Logbook::_checkBounds (int n, int min, int max) {
    return n >= min && n <= max;
}


