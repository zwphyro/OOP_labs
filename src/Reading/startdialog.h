#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <utility>

class StartDialog
{
public:
	void printFieldSizeRequest();
	std::pair<int, int> getFieldSize();
};

#endif
