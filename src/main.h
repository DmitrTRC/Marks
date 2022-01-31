#pragma once   // Include this header only once

#include <fstream>
#include <iostream>

void save_data ();
bool load_archive_data();
void load_data ();
void flush_stream (std::istream & );
void waiting_for_enter ();
void clear_screen (const int &);
void show_menu ();
int get_choice ();
void add_mark ();
bool remove_mark ();
void diary ();
void clear_all_data (const std::string &);
bool backup_data ();
void saving_on_exit ();
bool execute_choice (int);
void log_menu ();
