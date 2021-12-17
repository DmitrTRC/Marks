#include <iostream>
#include <json/json.h>


/** Entry point for Marks application
 *
 * @param argc Argument count
 * @param argv Argument values
 * @return 0 if successful
 */
void logbook ();

int logbook_menu ();

void clear_screen ();

int jsonWrite (){

        Json::Value root;
        Json::Value data;
        constexpr bool shouldUseOldWay = false;
        root["action"] = "run";
        data["number"] = 1;
        root["data"] = data;

        if (shouldUseOldWay) {
            Json::FastWriter writer;
            const std::string json_file = writer.write(root);
            std::cout << json_file << std::endl;
        } else {
            Json::StreamWriterBuilder builder;
            const std::string json_file = Json::writeString(builder, root);
            std::cout << json_file << std::endl;
        }
        return EXIT_SUCCESS;

}

int main (int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Interactive mode selected." << std::endl;
        logbook ();
    } else {
        std::cout << "Console mode selected." << std::endl;
    }

    return 0;
}

void clear_screen () {
    int ScreenRows = 50;
    std::cout << std::string (ScreenRows, '\n');
}

int logbook_menu () {
    clear_screen ();
    std::cout << "Logbook Menu" << std::endl;
    std::cout << "1. Add Entry" << std::endl;
    std::cout << "2. View Entries" << std::endl;
    std::cout << "3. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    return choice;
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

