#include <iostream>

#include "grep.h"
#include "help.h"

const int MAX_ARGS = 6;

int main(int argc, char* argv[]) {
    using namespace std;
    if(!validate(argc)) return -1;
    cout << "validated" << endl;

    //    1     2           3            4         5         6
    // cgrep [regex] [--o || --help] <option> <directory> <output>
    string args[MAX_ARGS];
    for(int i = 1; i < argc; ++i) {
        args[i] = argv[i];
    }

    // do some validation here
    bool result = process(argc, args);

    if(!result) {
        usage();
    }
}