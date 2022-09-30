#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include "./../Field/position.h" 

class StartDialog {
	int start_height;
	int start_width;
	bool size_set;

	Position player_position;
	bool position_set;

public:
	StartDialog();

	void exec();

	bool isPositionSet();
	Position getPlayerPosition();

	bool isFieldSizeSet();
	int getWidth();
	int getHeight();

};

#endif
