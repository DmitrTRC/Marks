#include <iostream>


void log_menu () {

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