#include "screeninitializer.h"
#include <ncurses.h>

ScreenInitializer::ScreenInitializer()
{
    initscr();
    noecho();
    raw();
    keypad(stdscr, true);
    leaveok(stdscr, true);
    curs_set(0);
    ESCDELAY = 0;
    timeout(15);

    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_GREEN);
    init_pair(3, COLOR_BLACK, COLOR_BLUE);
    init_pair(4, COLOR_BLACK, COLOR_RED);
    init_pair(5, COLOR_BLACK, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
    init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(8, COLOR_BLUE, COLOR_BLACK);
    init_pair(9, COLOR_BLACK, COLOR_MAGENTA);
}

ScreenInitializer::~ScreenInitializer()
{
    leaveok(stdscr, false);
    curs_set(1);
    cbreak();
    echo();
    endwin();
}
