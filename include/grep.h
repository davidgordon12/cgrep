#ifndef _GREP_H
#define _GREP_H

#include <vector>
#include <string>
#include <regex>

void WriteLines(std::string path);
bool MatchLine(std::string line, std::string regex);
std::vector<std::string> ReadLines(std::string path);
std::vector<std::string> ReadDirectory(std::string path);

#endif