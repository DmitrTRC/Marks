#include <iostream>


/** Entry point for Marks application
 *
 * @param argc Argument count
 * @param argv Argument values
 * @return 0 if successful
 */

int main (int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Interactive mode selected." << std::endl;
    } else {
        std::cout << "Console mode selected." << std::endl;
    }

    return 0;
}
