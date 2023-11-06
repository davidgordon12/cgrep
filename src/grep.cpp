#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "grep.h"
#include "help.h"

using namespace std;

bool Grep::process(int argc, string argv[]) {
    switch (argc) { //  1      2
    /* If only one arg was provided after 'cgrep' (cgrep [regex]),
    we will search the current directory with the provided regex. */
    case 2:
        break; //  1      2           3
    /* If only 2 args were provided after 'cgrep' (cgrep [regex] <file ||
    directory>), then we will print to stdout by default. */
    case 3:
        break; //  1      2           3               4
    /* If all 3 args were provided after 'cgrep' (cgrep [regex] <file ||
    directory> <output>), then we will print to the output path provided, and
    stdout will be used as a fallback.  */
    case 4:
        break;
    }

    string output;

    return false;
}

vector<string> ReadDirectory(string path) {}

vector<string> ReadLines(string path) {
    string line;
    ifstream input;
    input.open("test.txt");

    if (!input.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    while (getline(input, line)) {
        cout << line << endl;
    }
}

bool MatchLine(string line, string regex) {}

void WriteLines(string path) {}