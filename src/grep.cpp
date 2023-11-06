#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include "grep.h"
#include "help.h"

using namespace std;

/*  Grep.cpp: GPL-2.0
 *  Entry point for Grep processing
 *  Written by David Gordon
 *  Last Edited: November 06, 2023
 */
bool Grep::Process(int argc, string argv[]) {
    string output;
    switch (argc) {
    /* If only one arg was provided after 'cgrep'
       1      2
    (cgrep [regex]),
    we will search the current directory with the provided regex. */
    case 2:
        ProcessFile();
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

    return false;
}

void Grep::ProcessFile() {
    vector<string> lines = ReadLines("test.txt");
    vector<string> matched;

    for (string line : lines) {
        if(!MatchLine(line, "hi"))
            continue;
        matched.push_back(line);
    }

    WriteLines(matched, "out.txt");
}

void Grep::ProcessDir() {}

vector<string> Grep::ReadDirectory(string path) {}

vector<string> Grep::ReadLines(string path) {
    vector<string> lines;
    string line;
    ifstream input;
    input.open(path);

    if (!input.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    while (getline(input, line)) {
        lines.push_back(line);
    }

    return lines;
}

bool Grep::MatchLine(string line, string rgx) {
    regex pattern(rgx);
    return regex_search(line, pattern);
}

void Grep::WriteLines(vector<string> matched, string output) {
    ofstream file;
    file.open(output);
    for(string line : matched) {
        file << line + "\n";
    }
    file.close();
}