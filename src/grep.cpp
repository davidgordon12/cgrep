#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "grep.h"
#include "help.h"

using namespace std;

bool Grep::Process(int argc, string argv[]) {
    switch (argc) {
    /* If only one arg was provided after 'cgrep'
       1      2
    (cgrep [regex]),
    we will search the current directory with the provided regex. */
    case 2:
        ProcessDir();
        break;

    /* If only 2 args were provided after 'cgrep'
       1      2       3
    (cgrep [regex] <input>),
    then we will print to stdout by default. */
    case 3:
        ProcessFile();
        break;

    /* If all 3 args were provided after 'cgrep'
       1      2       3        4
    (cgrep [regex] <input> <output>),
    then we will print to the output path provided,
    and stdout will be used as a fallback. */
    case 4:
        ProcessFile();
        break;
    }

    string output;

    return false;
}

void Grep::ProcessDir() {

}

void Grep::ProcessFile() {

}

vector<string> Grep::ReadDirectory(string path) {}

vector<string> Grep::ReadLines(string path) {
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

bool Grep::MatchLine(string line, string regex) {}

void Grep::WriteLines(string path) {}