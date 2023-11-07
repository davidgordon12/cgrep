#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <windows.h>
#include <locale>
#include <codecvt>

#include "grep.h"
#include "help.h"

using namespace std;
/*  Grep.cpp: GPL-2.0
 *  Entry point for Grep processing
 *  Written by David Gordon
 *  Last Edited: November 06, 2023
 */
void Grep::Process(int argc, string argv[]) {
    switch (argc) {
    /* If only 2 args were provided after 'cgrep'
       1      2       3
    (cgrep [regex] <input>),
    then we will print to stdout by default. */
    case 3:
        rgx = argv[1];
        input = argv[2];
        ProcessFile();
        break;

    /* If all 3 args were provided after 'cgrep'
       1      2       3        4
    (cgrep [regex] <input> <output>),
    then we will print to the output path provided,
    and stdout will be used as a fallback. */
    case 4:
        rgx = argv[1];
        input = argv[2];
        output = argv[3];
        ProcessFile();
        break;
    }
}

void Grep::ProcessFile() {
    vector<string> lines = ReadLines(input);
    vector<string> matched;

    for (string line : lines) {
        if (!MatchLine(line, rgx))
            continue;
        matched.push_back(line);
    }

    WriteLines(matched, output);
}

vector<string> Grep::ReadLines(string path) {
    vector<string> lines;
    string line;
    ifstream file;
    file.open(path);

    if (!file.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }

    while (getline(file, line)) {
        lines.push_back(line);
    }

    return lines;
}

bool Grep::MatchLine(string line, string rgx) {
    regex pattern(rgx);
    return regex_search(line, pattern);
}

void Grep::WriteLines(vector<string> matched, string output) {
    if (regex_search(output, regex("[.]"))) {
        ofstream file;
        file.open(output);

        if (!file.is_open()) {
            perror("Error open");
            exit(EXIT_FAILURE);
        }

        for (string line : matched) {
            file << line + "\n";
        }

        file.close();
        return;
    }

    for (string line : matched) {
        cout << line << endl;
    }

}