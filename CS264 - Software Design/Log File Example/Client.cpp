#include "LogFile.h"
#include "Client.h"

Client::Client(std::string n) {
    name = n;
    LogFile::getInstance().write(name + " has been created");
}

Client::~Client() {
    LogFile::getInstance().write(name + " has died");
}