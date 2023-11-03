#include <iostream>

#include "help.h"

using namespace std;

void usage();

void usage() {
    cout << "USAGE: cgrep [regex] --FLAGS" << endl;
    cout << "Enter cgrep --help to see options" << endl;
}

bool validate(int argc) {
    if(argc < 2) { 
        cout << "Too few arguments" << endl;
        usage();
        return false;
    }

    if(argc > 6) {
        cout << "Too many arguments" << endl;
        usage();
        return false;
    }

    return true;
}