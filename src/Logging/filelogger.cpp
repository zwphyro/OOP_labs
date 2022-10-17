#include "filelogger.h"

#define LOG_FILE_NAME "logs.txt"

FileLogger::FileLogger()
{
    _output_file.open(LOG_FILE_NAME);
}

FileLogger::~FileLogger()
{
    _output_file.close();
}

void FileLogger::notify(std::string message)
{
    _output_file << message << '\n';
}
