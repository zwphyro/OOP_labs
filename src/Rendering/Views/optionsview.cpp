#include "optionsview.h"
#include "./../../Interface/Options/optionsparameters.h"
#include <ncurses.h>
#include <map>
#include <string>

OptionsView::OptionsView(const OptionsParameters *parameters) : _parameters(parameters)
{
    update();
}

OptionsView::~OptionsView()
{
}

void OptionsView::setParameters(const OptionsParameters *parameters)
{
    _parameters = parameters;
}

void OptionsView::update()
{
    clear();
    drawBorders();
    drawOptions();
    drawStates();
    selectOption(_parameters->getCurrentOption());
}

void OptionsView::drawBorders()
{
    for (int i = 1; i < 23; i++)
    {
        mvaddch(1, i, ACS_HLINE | COLOR_PAIR(6));
        mvaddch(5, i, ACS_HLINE | COLOR_PAIR(6));
        mvaddch(9, i, ACS_HLINE | COLOR_PAIR(6));
        mvaddch(21, i, ACS_HLINE | COLOR_PAIR(6));
        mvaddch(25, i, ACS_HLINE | COLOR_PAIR(6));
        mvaddch(43, i, ACS_HLINE | COLOR_PAIR(6));
        mvaddch(49, i, ACS_HLINE | COLOR_PAIR(6));
    }

    for (int i = 1; i < 50; i++)
    {
        mvaddch(i, 1, ACS_VLINE | COLOR_PAIR(6));
        mvaddch(i, 22, ACS_VLINE | COLOR_PAIR(6));
    }

    mvaddch(1, 1, ACS_ULCORNER | COLOR_PAIR(6));
    mvaddch(1, 22, ACS_URCORNER | COLOR_PAIR(6));
    mvaddch(5, 1, ACS_LTEE | COLOR_PAIR(6));
    mvaddch(5, 22, ACS_RTEE | COLOR_PAIR(6));
    mvaddch(9, 1, ACS_LTEE | COLOR_PAIR(6));
    mvaddch(9, 22, ACS_RTEE | COLOR_PAIR(6));
    mvaddch(21, 1, ACS_LTEE | COLOR_PAIR(6));
    mvaddch(21, 22, ACS_RTEE | COLOR_PAIR(6));
    mvaddch(25, 1, ACS_LTEE | COLOR_PAIR(6));
    mvaddch(25, 22, ACS_RTEE | COLOR_PAIR(6));
    mvaddch(43, 1, ACS_LTEE | COLOR_PAIR(6));
    mvaddch(43, 22, ACS_RTEE | COLOR_PAIR(6));
    mvaddch(49, 1, ACS_LLCORNER | COLOR_PAIR(6));
    mvaddch(49, 22, ACS_LRCORNER | COLOR_PAIR(6));
}

void OptionsView::drawOptions()
{
    attron(COLOR_PAIR(6) | A_BOLD);
    mvprintw(3, 3, "OPTIONS");
    mvprintw(7, 3, ">FIELD");
    mvprintw(23, 3, ">LOGGING");
    attroff(A_BOLD);
    mvprintw(12, 4, "GENERATOR");
    mvprintw(15, 4, "WIDTH");
    mvprintw(18, 4, "HEIGHT");
    mvprintw(28, 4, "CONSOLE");
    mvprintw(31, 4, "FILE");
    mvprintw(34, 4, "ENTITIES");
    mvprintw(37, 4, "GAME STATES");
    mvprintw(40, 4, "EXCEPTIONS");
    mvprintw(46, 4, "QUIT");
    attroff(COLOR_PAIR(6));
}

void OptionsView::drawStates()
{
    attron(COLOR_PAIR(6));
    mvprintw(12, 16, "<   >");
    if (_parameters->getFieldGenerator(0) == Generator::MAZE)
        mvprintw(12, 17, "MZE");
    else
        mvprintw(12, 17, "EXP");
    mvprintw(15, 16, "<   >");
    mvprintw(15, 17, "%d", _parameters->getFieldWidth());
    mvprintw(18, 16, "<   >");
    mvprintw(18, 17, "%d", _parameters->getFieldHeight());
    mvprintw(28, 16, "<   >");
    if (_parameters->getConsoleLogState())
        mvprintw(28, 17, " ON");
    else
        mvprintw(28, 17, "OFF");
    mvprintw(31, 16, "<   >");
    if (_parameters->getFileLogState())
        mvprintw(31, 17, " ON");
    else
        mvprintw(31, 17, "OFF");
    mvprintw(34, 16, "<   >");
    if (_parameters->getEntitiesLogLevelState())
        mvprintw(34, 17, " ON");
    else
        mvprintw(34, 17, "OFF");
    mvprintw(37, 16, "<   >");
    if (_parameters->getGameStatesLogLevelState())
        mvprintw(37, 17, " ON");
    else
        mvprintw(37, 17, "OFF");
    mvprintw(40, 16, "<   >");
    if (_parameters->getExceptionsLogLevelState())
        mvprintw(40, 17, " ON");
    else
        mvprintw(40, 17, "OFF");
    attroff(COLOR_PAIR(6));
}

void OptionsView::selectOption(int option)
{
    int start_height;
    std::map<const int, int> heights{
        {OptionsParameters::GENERATOR, 11},
        {OptionsParameters::WIDTH, 14},
        {OptionsParameters::HEIGHT, 17},
        {OptionsParameters::CONSOLE, 27},
        {OptionsParameters::FILE, 30},
        {OptionsParameters::ENTITIES, 33},
        {OptionsParameters::GAME_STATES, 36},
        {OptionsParameters::EXCEPTIONS, 39},
        {OptionsParameters::QUIT, 45}};
    start_height = heights[option];

    for (int i = 3; i < 16; i++)
    {
        for (int j = start_height; j < start_height + 3; j++)
        {
            mvaddch(j, i, ' ' | COLOR_PAIR(1));
            mvaddch(j, 3, ACS_VLINE | COLOR_PAIR(1));
            mvaddch(j, 15, ACS_VLINE | COLOR_PAIR(1));
        }
        mvaddch(start_height, i, ACS_HLINE | COLOR_PAIR(1));
        mvaddch(start_height + 2, i, ACS_HLINE | COLOR_PAIR(1));
    }

    mvaddch(start_height, 3, ACS_ULCORNER | COLOR_PAIR(1));
    mvaddch(start_height, 15, ACS_URCORNER | COLOR_PAIR(1));
    mvaddch(start_height + 2, 3, ACS_LLCORNER | COLOR_PAIR(1));
    mvaddch(start_height + 2, 15, ACS_LRCORNER | COLOR_PAIR(1));

    attron(COLOR_PAIR(1) | A_BOLD);

    std::map<const int, std::string> options{
        {OptionsParameters::GENERATOR, "GENERATOR"},
        {OptionsParameters::WIDTH, "WIDTH"},
        {OptionsParameters::HEIGHT, "HEIGHT"},
        {OptionsParameters::CONSOLE, "CONSOLE"},
        {OptionsParameters::FILE, "FILE"},
        {OptionsParameters::ENTITIES, "ENTITIES"},
        {OptionsParameters::GAME_STATES, "GAME STATES"},
        {OptionsParameters::EXCEPTIONS, "EXCEPTIONS"},
        {OptionsParameters::QUIT, "QUIT"}};

    mvprintw(start_height + 1, 4, options[option].c_str());
    attroff(COLOR_PAIR(1) | A_BOLD);
}
