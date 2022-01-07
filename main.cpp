#include <iostream>

#include <iostream>
#include <string>


void show_menu () {
    std::cout << "1. Add a new student" << std::endl;
    std::cout << "2. Remove a student" << std::endl;
    std::cout << "3. List all students" << std::endl;
    std::cout << "4. Quit" << std::endl;
}

int get_choice () {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

bool execute_choice (int choice) {
    bool result = true;

    switch (choice) {
        case 1:
            std::cout << "Add a new student" << std::endl;
            break;
        case 2:
            std::cout << "Remove a student" << std::endl;
            break;
        case 3:
            std::cout << "List all students" << std::endl;
            break;
        case 4:
            std::cout << "Quit" << std::endl;
            result = false;
            break;

        default:
            std::cout << "Invalid choice" << std::endl;
            break;

    }
    return result;
}

//bool execute_choice_2 (int choice) {
//    bool result = true;
//
//    if (choice == 1) {
//        std::cout << "Add a new student" << std::endl;
//    } else if (choice == 2) {
//        std::cout << "Remove a student" << std::endl;
//    } else if (choice == 3) {
//        std::cout << "List all students" << std::endl;
//    } else if (choice == 4) {
//        std::cout << "Quit" << std::endl;
//        result = false;
//    } else {
//        std::cout << "Invalid choice" << std::endl;
//    }
//    return result;
//}

void log_menu () {

    do {
        show_menu ();
    } while (execute_choice (get_choice ()));
};

//TODO: 1) Read switch() statement from the previous exercise
//TODO: 2) Make Mark project menu.
//TODO: 3) *Try to write tests.

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
        std::cout << std::endl << "Bye!" << std::endl;
    }
    return 0;
}
