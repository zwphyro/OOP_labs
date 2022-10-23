#include "menuview.h"
#include "./../../Interface/Menu/menuparameters.h"
#include <ncurses.h>
#include <map>
#include <string>

MenuView::MenuView(const MenuParameters *parameters) : _model_parameters(parameters)
{
    update();
}

MenuView::~MenuView()
{
}

void MenuView::setParameters(const MenuParameters *parameters)
{
    _model_parameters = parameters;
}

void MenuView::update()
{
    clear();
    drawBorder();
    drawOptions();
    selectOption(_model_parameters->getCurrentOption());
}

void MenuView::drawBorder()
{
    for (int i = 1; i < 14; i++)
    {
        mvaddch(1, i, ACS_HLINE | COLOR_PAIR(6));
        mvaddch(5, i, ACS_HLINE | COLOR_PAIR(6));
        mvaddch(20, i, ACS_HLINE | COLOR_PAIR(6));
    }

    for (int i = 1; i < 21; i++)
    {
        mvaddch(i, 1, ACS_VLINE | COLOR_PAIR(6));
        mvaddch(i, 13, ACS_VLINE | COLOR_PAIR(6));
    }

    mvaddch(1, 1, ACS_ULCORNER | COLOR_PAIR(6));
    mvaddch(1, 13, ACS_URCORNER | COLOR_PAIR(6));
    mvaddch(5, 1, ACS_LTEE | COLOR_PAIR(6));
    mvaddch(5, 13, ACS_RTEE | COLOR_PAIR(6));
    mvaddch(20, 1, ACS_LLCORNER | COLOR_PAIR(6));
    mvaddch(20, 13, ACS_LRCORNER | COLOR_PAIR(6));
}

void MenuView::drawOptions()
{
    attron(COLOR_PAIR(6) | A_BOLD);
    mvprintw(3, 3, "MENU");
    attroff(A_BOLD);
    mvprintw(8, 4, "PLAY");
    mvprintw(11, 4, "LOAD");
    mvprintw(14, 4, "OPTIONS");
    mvprintw(17, 4, "QUIT");
    attroff(COLOR_PAIR(6));
}

void MenuView::selectOption(int option)
{
    int start_height = 7 + 3 * option;
    for (int i = 3; i < 12; i++)
    {
        for (int j = start_height; j < start_height + 3; j++)
        {
            mvaddch(j, i, ' ' | COLOR_PAIR(1));
            mvaddch(j, 3, ACS_VLINE | COLOR_PAIR(1));
            mvaddch(j, 11, ACS_VLINE | COLOR_PAIR(1));
        }
        mvaddch(start_height, i, ACS_HLINE | COLOR_PAIR(1));
        mvaddch(start_height + 2, i, ACS_HLINE | COLOR_PAIR(1));
    }

    mvaddch(start_height, 3, ACS_ULCORNER | COLOR_PAIR(1));
    mvaddch(start_height, 11, ACS_URCORNER | COLOR_PAIR(1));
    mvaddch(start_height + 2, 3, ACS_LLCORNER | COLOR_PAIR(1));
    mvaddch(start_height + 2, 11, ACS_LRCORNER | COLOR_PAIR(1));

    attron(COLOR_PAIR(1) | A_BOLD);

    std::map<const int, std::string> options{
        {MenuParameters::START, "START"},
        {MenuParameters::LOAD, "LOAD"},
        {MenuParameters::OPTIONS, "OPTIONS"},
        {MenuParameters::QUIT, "QUIT"}};

    mvprintw(start_height + 1, 4, options[option].c_str());
    attroff(COLOR_PAIR(1) | A_BOLD);
}
