#include <iostream>

#include "help.h"

using namespace std;

void usage() {
    cout << "USAGE: cgrep [regex] <input> <output>" << endl;
    cout << "Enter cgrep --help to see options" << endl;
}

bool validate(int argc) {
    if (argc < 3) {
        cout << "Too few arguments" << endl;
        usage();
        return false;
    }

    if (argc > 4) {
        cout << "Too many arguments" << endl;
        usage();
        return false;
    }

    return true;
}