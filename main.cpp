/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 09:53:15 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 16:15:21 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurse.class.hpp"
#include <stdio.h>
#include <stdlib.h>
#include "PlayerShip.class.hpp"

int	main( void ) {
	Ncurse	newWin;
	Ncurse	game(newWin.getNbRows(),
			(newWin.getNbColumns() * 80) / 100, 0, 0);
	Ncurse	info(newWin.getNbRows(),
			(newWin.getNbColumns() * 20) / 100, 0,
			(newWin.getNbColumns() * 80) / 100);
	int		keyValue = 0;
	PlayerShip	player('>',
			(newWin.getNbColumns() * 4) / 100,
			newWin.getNbRows() / 2,
			newWin.getNbRows());
	char	str[2];
	int		i;

	str[1] = '\0';
	Ncurse::init_colors(1, COLOR_BLUE, COLOR_WHITE);
	Ncurse::init_colors(2, COLOR_RED, COLOR_WHITE);
	Ncurse::init_colors(3, COLOR_YELLOW, COLOR_BLACK);
	game.useColor(2);
	info.useColor(3);
	game.refresh();
	info.refresh();
	while (true) {
		keyValue = game.waitForInput();
		if (keyValue == KEY_ESC) {
			break;
		} else if (keyValue == KEY_UP) {
			player++;
		} else if (keyValue == KEY_DOWN) {
			player--;
		} else if (keyValue == KEY_SPACE) {
			player.shoot();
		}
		game.clear();
		info.clear();
		i = 0;
		while (i < player.getNbrShoots()) {
			player.getSpecificShoot(i)++;
			i++;
		}
		str[0] = player.getType();
		game.print(str, player.getPosY(), player.getPosX());
		i = 0;
		if (player.getNbrShoots()) {
			str[0] = player.getSpecificShoot(i).getType();
			while (i < player.getNbrShoots()) {
				game.print(str, player.getSpecificShoot(i).getPosY(),
						player.getSpecificShoot(i).getPosX());
				i++;
			}
		}
		game.refresh();
		info.refresh();
		napms(100);
	}
	return 0;
}
