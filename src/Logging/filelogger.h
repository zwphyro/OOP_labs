#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "observer.h"
#include <fstream>

#define LOG_FILE_NAME "logs.txt"

class FileLogger : public Observer
{
public:
    FileLogger(std::string log_file_name = LOG_FILE_NAME);
    ~FileLogger();
    void notify(LogMessage message);

private:
    std::ofstream _output_file;
};

#endif
