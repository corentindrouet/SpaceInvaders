/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 09:53:15 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 11:37:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurse.class.hpp"
#include <stdio.h>

int	main( void ) {
	Ncurse	newWin;
	Ncurse	game(newWin.getNbRows(),
			(newWin.getNbColumns() * 80) / 100, 0, 0);
	Ncurse	info(newWin.getNbRows(),
			(newWin.getNbColumns() * 20) / 100, 0,
			(newWin.getNbColumns() * 80) / 100);
	int		keyValue = 0;

	Ncurse::init_colors(1, COLOR_BLUE, COLOR_WHITE);
	Ncurse::init_colors(2, COLOR_RED, COLOR_WHITE);
	Ncurse::init_colors(3, COLOR_YELLOW, COLOR_BLACK);
	game.print((char*)"Hello World", 10, 5);
	info.print((char*)"Here are informations", 5, 5);
	game.useColor(2);
	info.useColor(3);
	game.refresh();
	info.refresh();
	while (true) {
//		game.erase();
//		info.erase();
		keyValue = game.waitForInput();
		if (keyValue == KEY_ESC) {
			break;
		}
		game.refresh();
		info.refresh();
	}
	return 0;
}
