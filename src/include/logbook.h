//
// Created by Dmitry Morozov on 22.12.2021.
//

#ifndef MARKS_LOGBOOK_H
#define MARKS_LOGBOOK_H

#include <iostream>
#include "screen_util.h"
#include "mark.h"


//TODO: Change to class
class Logbook {
public:
    //Logbook ();

    //~Logbook ();

    static int showMenu ();

    void run ();

    void addMark ();

private:
    bool getChoice (int &, int, int);

     int _readChoice (int, int);

    bool _checkBounds (int, int, int);

};


#endif //MARKS_LOGBOOK_H
