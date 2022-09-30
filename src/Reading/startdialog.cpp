#include <iostream>
#include "startdialog.h"

StartDialog::StartDialog() {
	size_set = false;
	position_set = false;
}

void StartDialog::exec() {

    char request;
	std::cout << "Введите ширину и высоту поля: " << '\n';

	size_set = true;
    while (!(std::cin >> start_width >> start_height) || start_width <= 0 || start_height <= 0)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка ввода, хотите повторить ввод? [y/n]";
        std::cin >> request;
        if (request == 'y')
        	std::cout << "Введите ширину и высоту поля: " << '\n';
    	else {
    		size_set = false;
    		break;
    	}
    }

    std::cout << "Введите координаты игрока: " << std::endl;

    position_set = true;
    while (!(std::cin >> player_position.x >> player_position.y) || player_position.x >= start_width || player_position.y >= start_height || player_position.x < 0 || player_position.y < 0)
    {
        std::cin.clear();
        while (std::cin.get() != '\n');
        std::cout << "Ошибка ввода, хотите повторить ввод? [y/n]";
        std::cin >> request;
        if (request == 'y')
        	std::cout << "Введите координаты игрока: " << std::endl;
    	else {
    		position_set = false;
    		break;
    	}
    }
}

bool StartDialog::isPositionSet() {
	return position_set;
}

Position StartDialog::getPlayerPosition() {
	if (position_set) return player_position;
	throw 1;
}

bool StartDialog::isFieldSizeSet() {
	return size_set;
} 

int StartDialog::getWidth() {
	if (size_set) return start_width;
	throw 1;
}

int StartDialog::getHeight() {
	if (size_set) return start_height;
	throw 1;

}
