/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 09:53:15 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 17:35:29 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurse.class.hpp"
#include <stdio.h>
#include <string>
//#include <stdlib.h>
#include "PlayerShip.class.hpp"

int	main( void ) {
	Ncurse	newWin;
	Ncurse	game((newWin.getNbRows() * 60) / 100,
			(((newWin.getNbColumns() * 80) / 100) * 60) / 100,
			(newWin.getNbRows() * 20) / 100,
			(newWin.getNbColumns() * 20) / 100);
	Ncurse	info(newWin.getNbRows(),
			(newWin.getNbColumns() * 20) / 100, 0,
			(newWin.getNbColumns() * 80) / 100);
	int		keyValue = 0;
	PlayerShip	player('>',
			(game.getNbColumns() * 4) / 100,
			game.getNbRows() / 2,
			game.getNbColumns());
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
		} else if (keyValue == KEY_UP && player.getPosY() > 0) {
			player++;
		} else if (keyValue == KEY_DOWN && player.getPosY() < (game.getNbRows() - 1)) {
			player--;
		} else if (keyValue == KEY_SPACE) {
			player.shoot();
		}
		game.clear();
		info.clear();
		str[0] = player.getType();
		game.print(str, player.getPosY(), player.getPosX());
		i = 0;
		if (player.getNbrShoots()) {
			str[0] = player.getSpecificShoot(i).getType();
			while (i < player.getNbrMaxShoots()) {
				if (player.getSpecificShoot(i).getFired()) {
					game.print(str, player.getSpecificShoot(i).getPosY(),
							player.getSpecificShoot(i).getPosX());
					player.getSpecificShoot(i)++;
					if (player.getSpecificShoot(i).getPosX() >= (game.getNbColumns() - 1)) {
						player.getSpecificShoot(i).setFired(false);
						player.setNbrShoots(player.getNbrShoots() - 1);
					}
				}
				i++;
			}
		}
		info.print((char*)"Score: ", 20, 0);
		info.print((char *)(std::to_string(player.getScore()).c_str()), 20, 8);
		info.print((char*)"Lives: ", 22, 0);
		info.print((char *)(std::to_string(player.getLives()).c_str()), 22, 8);
		game.refresh();
		info.refresh();
		napms(100);
	}
	return 0;
}
