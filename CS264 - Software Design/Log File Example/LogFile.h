#include <iostream>
#include <fstream>

class LogFile {
    private:
        LogFile();
        ~LogFile();
        LogFile(const LogFile &);
        LogFile & operator=(const LogFile &);
        std::ofstream logFile;
    public:
        static LogFile &getInstance();
        void write(const std::string &message);
};
