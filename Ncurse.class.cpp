/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 08:59:17 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 15:45:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurse.class.hpp"

Ncurse::Ncurse( void ) {
	initscr();
	start_color();
	cbreak();
	noecho();
	curs_set(0);
	timeout(500);
	this->_win = newwin(0, 0, 0, 0);
	keypad(this->_win, TRUE);
	getmaxyx(this->_win, this->_nbRows, this->_nbColumns);
	this->_firstRow = 0;
	this->_firstColumn = 0;
	return;
}

Ncurse::Ncurse( Ncurse const & copy ) {
	*this = copy;
	return;
}

Ncurse::Ncurse( int rows, int columns, int firstRow, int firstColumn ) {
	initscr();
	cbreak();
	timeout(500);
	start_color();
	this->_win = newwin(rows, columns, firstRow, firstColumn);
	nodelay(this->_win, true);
	keypad(this->_win, TRUE);
	this->_nbColumns = columns;
	this->_nbRows = rows;
	this->_firstRow = firstRow;
	this->_firstColumn = firstColumn;
	return;
}

Ncurse::~Ncurse( void ) {
	delwin(this->_win);
	endwin();
	return;
}

Ncurse	&Ncurse::operator=( Ncurse const & otherNcurse ) {
	delwin(this->_win);
	this->_nbRows = otherNcurse.getNbRows();
	this->_nbColumns = otherNcurse.getNbColumns();
	this->_firstRow = otherNcurse.getFirstRow();
	this->_firstColumn = otherNcurse.getFirstColumn();
	this->_win = newwin(this->_nbRows, this->_nbColumns, this->_firstRow,
			this->_firstColumn);
	return *this;
}

int		Ncurse::getNbRows( void ) const {
	return this->_nbRows;
}

int		Ncurse::getNbColumns( void ) const {
	return this->_nbColumns;
}

int		Ncurse::getFirstRow( void ) const {
	return this->_firstRow;
}

int		Ncurse::getFirstColumn( void ) const {
	return this->_firstColumn;
}

void	Ncurse::print( char *c , int y, int x) {
	mvwprintw(this->_win, y, x, c);
	return;
}

void	Ncurse::clear( void ) {
	werase(this->_win);
	return;
}

void	Ncurse::refresh( void ) {
	wrefresh(this->_win);
	return;
}

void	Ncurse::resize( int rows, int columns ) {
	wresize(this->_win, rows, columns);
	return;
}

void	Ncurse::init_colors( short num, short text, short back ) {
	init_pair(num, text, back);
	return;
}

int		Ncurse::waitForInput( void ) {
	return wgetch(this->_win);
}


void	Ncurse::useColor( int colorPairNumber ) {
	attrset(COLOR_PAIR(colorPairNumber));
	return;
}

void	Ncurse::setBackgroundColor( int colorPairNumber ) {
	wbkgd(this->_win, COLOR_PAIR(colorPairNumber));
	return;
}
