#include "filelogger.h"
#include "logmessage.h"
#include "logpermissions.h"

FileLogger::FileLogger(std::string log_file_name)
{
    _output_file.open(log_file_name);
}

FileLogger::~FileLogger()
{
    _output_file << std::flush;
    _output_file.close();
}

void FileLogger::notify(LogMessage message)
{
    if (!_permissions)
        return;
    if (_state && _permissions->getPermission(message.getLogLevel()))
        _output_file << message;
}
