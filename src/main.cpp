#include <iostream>

#include "grep.h"
#include "help.h"

const int MAX_ARGS = 4;

int main(int argc, char *argv[]) {
    using namespace std;
    if (!validate(argc))
        return -1;

    //    1     2       3      4
    // cgrep [regex] <file> <output>
    string args[MAX_ARGS];
    for (int i = 0; i < argc; ++i) {
        args[i] = argv[i];
    }

    Grep grep;
    grep.Process(argc, args);
}