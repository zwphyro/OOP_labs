#include <iostream>
#include "startdialog.h"

void StartDialog::printFieldSizeRequest()
{
	std::cout << "Enter field width and height: ";
}

std::pair<int, int> StartDialog::getFieldSize()
{
	printFieldSizeRequest();
	int width, height;
	if (!(std::cin >> width >> height) || width <= 1 || height <= 1)
		return std::make_pair(5, 5);
	return std::make_pair(width, height);
}
