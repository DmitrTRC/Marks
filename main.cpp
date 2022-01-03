#include <iostream>

#include <iostream>
#include <string>


// int log_menu();
std::string log_menu () {

//TODO: Implement menu numeration
    std::cout << "Menu:" << std::endl;
    std::cout << "Show Marks log " << std::endl;
    std::cout << "Add Marks" << std::endl;
    std::cout << "Delete Marks" << std::endl;
    std::cout << "Exit" << std::endl;
    std::cout << "Enter your choice: " << std::endl;
    std::string choice;
    std::cin >> choice;
    return choice;
// Checked : Ok : 5
};

//TODO: Implement menu dispatcher
//  void dispatch_menu_choice (int choice) {
//  int choice = log_menu();
//if ( choice  == 1) {
//   std::cout << "Marks : List" << std::endl;
//}
//  }




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
