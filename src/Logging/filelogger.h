#ifndef FILELOGGER_H
#define FILELOGGER_H

#include "observer.h"
#include <fstream>

class FileLogger : public Observer
{
public:
    FileLogger();
    ~FileLogger();
    void notify(std::string message);

private:
    std::ofstream _output_file;
};

#endif
