#include "LogFile.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

LogFile::LogFile() {
    logFile.open("log.txt");
}

LogFile::~LogFile() {
    logFile.close();
}

LogFile & LogFile::getInstance() {
    static LogFile instance;
    return instance;
}

void LogFile::write(const std::string &message) {
    logFile << message << '\n';
    // logFile.write("\n", 1);
}