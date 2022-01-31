#include <fstream>
#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <ios>
#include <limits>
#include <istream>
#include <iomanip>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>

#include "Console_color.h"
#include "main.h"

std::map<std::string, std::vector<int>> student_log;

std::string Password = "developer";

bool need_update = false;
int main(int argc, char *argv[])
{

    if (argc >= 2)
    {
        std::cout << "Console mode. Not implemented yet!" << std::endl;
        for (int i = 1; i < argc; i++)
        {
            std::cout << argv[i] << std::endl;
        }
    }
    else
    {
        std::cout << "Interactive mode" << std::endl;

        log_menu();
        std::cout << std::endl
                  << "Bye!" << std::endl;
    }
    return 0;
}

//namespace boost::serialization {
//
//    template<class Archive>
//    void serialize (Archive &ar, std::map<std::string, std::vector<int>> &st_log) {
//        ar & st_log;
//    }
//}

void save_data()
{
    std::ofstream ofs("student_log.txt");
    boost::archive::text_oarchive oa(ofs);
    oa << student_log;
    need_update = false;
}

bool load_archive_data()
{
    return true;
}

void load_data()
{
    std::ifstream ifs("student_log.txt");
    if (!ifs)
    {
        std::cout << "Database not found. Skip loading data." << std::endl;
        return;
    }
    else
    {
        boost::archive::text_iarchive ia(ifs);
        ia >> student_log;
    }
}

void flush_stream(std::istream &in)
{
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    in.clear();
}

void waiting_for_enter()
{
    std::cout << "Press [Enter] to continue . . .";
    flush_stream(std::cin);
    std::cin.get();
}

void clear_screen(const int &n = 50)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << std::endl;
    }
}

void show_menu()
{
    std::cout << std::endl
              << std::endl;
    std::cout << std::setw(30) << Color::Modifier(Color::FG_GREEN) << "* Main Menu *"
              << Color::Modifier(Color::FG_DEFAULT) << std::endl;
    std::cout << "1. Add a new Mark " << std::endl;
    std::cout << "2. Remove a Mark" << std::endl;
    std::cout << "3. Diary" << std::endl;
    std::cout << "4. Save Data" << std::endl;
    std::cout << "5. Quit" << std::endl;
    std::cout << Color::Modifier(Color::FG_BLUE) << "6. Create a backup" << Color::Modifier(Color::FG_DEFAULT) << std::endl;
    std::cout << Color::Modifier(Color::FG_RED) << "7. Clear all records" << Color::Modifier(Color::FG_DEFAULT)
              << std::endl;
}

int get_choice()
{
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

void add_mark()
{
    std::string subject_name;
    int mark;

    std::cout << std::endl;
    std::cout << "Enter subject name: ";
    std::cin >> subject_name;
    transform(subject_name.begin(), subject_name.end(), subject_name.begin(), ::toupper);

    std::cout << "Enter mark: ";
    std::cin >> mark;
    student_log[subject_name].push_back(mark);
    need_update = true;
}

bool remove_mark()
{
    std::string subject_name;
    int mark;

    std::cout << std::endl;
    std::cout << "Enter subject name: ";
    std::cin >> subject_name;
    transform(subject_name.begin(), subject_name.end(), subject_name.begin(), ::toupper);

    std::cout << "Enter mark: ";
    std::cin >> mark;

    if (student_log.find(subject_name) == student_log.end())
    {
        std::cout << "Subject not found." << std::endl;
        return false;
    }

    auto it = std::find(student_log[subject_name].begin(), student_log[subject_name].end(), mark);
    if (it == student_log[subject_name].end())
    {
        std::cout << "Mark not found." << std::endl;
        return false;
    }

    student_log[subject_name].erase(it);
    need_update = true;
    return true;
}

void diary()
{
    std::cout << "\t\t- Student  Diary: -" << std::endl;
    if (student_log.empty())
    {
        std::cout << "No marks yet!" << std::endl;
        return;
    }
    for (auto &[subject, mark] : student_log)
    {
        std::cout << subject << ": \t\t";
        for (auto &m : mark)
        {
            std::cout << m << " ";
        }
        std::cout << std::endl;
    }
    waiting_for_enter();
}

void clear_all_data(const std::string &file = "student_log.txt")
{
    std::cout << "Are you sure you want to clear all data? [y/n] ";
    char choice;
    std::cin >> choice;
    if (choice == 'y')
    {
        std::ofstream ofs(file);
        ofs.close();
        student_log.clear();
        std::cout << "All data cleared." << std::endl;
    }
    else
    {
        std::cout << "Data not cleared." << std::endl;
    }
}
bool backup_data()
{
    std::string file_name;
    std::cout << "Enter file name: ";
    std::cin >> file_name;
    std::ofstream ofs(file_name);
    if (!ofs)
    {
        std::cout << "File not found." << std::endl;
        return false;
    }
    boost::archive::text_oarchive oa(ofs);
    oa << student_log;
    return true;
}

void saving_on_exit()
{
    std::cout << "Do you want to save data? (y/n): ";
    char choice;
    std::cin >> choice;
    if (tolower(choice == 'y'))
    {
        save_data();

        std::cout << "Saving data..." << std::endl;
        save_data();
        std::cout << "Data saved." << std::endl;
    }
    else
    {
        std::cout << "Data not saved." << std::endl;
    }
}

bool execute_choice(int choice)
{
    bool result = true;

    switch (choice)
    {
    case 1:
        add_mark();
        break;
    case 2:
        remove_mark();
        break;
    case 3:
        diary();
        break;
    case 4:
        save_data(); //Saving data to file "student_log.txt"
        break;
    case 5:
        if (need_update)
            saving_on_exit();
        result = false;
        break;
    case 6:
        backup_data();
        break;
    case 7:
        clear_all_data();
        break;

    default:
        std::cout << "Invalid choice. Try again!" << std::endl;
        break;
    }
    return result;
}

void log_menu()
{
    load_data(); // Loading data from file student_log.txt

    do
    {
        show_menu();
    } while (execute_choice(get_choice()));
};

// 2 Modes : Console and Interactive
