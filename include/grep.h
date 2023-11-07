/*  Grep.h: GPL-2.0
 *  Entry point for Grep processing
 *  Written by David Gordon
 *  Last Edited: November 06, 2023
 */
#ifndef _GREP_H
#define _GREP_H

#include <vector>

class Grep {
private:
    std::string rgx;
    std::string input;
    std::string output;

public:
    void Process(int argc, std::string argv[]);

private:
    void ProcessFile();
    void WriteLines(const std::vector<std::string> matched, std::string output);
    bool MatchLine(std::string line, std::string rgx);
    std::vector<std::string> ReadLines(std::string path);
    std::vector<std::string> ReadDirectory(std::string path);
};

#endif