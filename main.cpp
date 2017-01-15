/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 09:53:15 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 18:56:03 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurse.class.hpp"
#include <stdio.h>
#include <string>
//#include <stdlib.h>
#include "PlayerShip.class.hpp"
#include "EnemyShip.class.hpp"

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
	int		cptenemy;
	int		nb_enemy = 30;
	EnemyShip		*enemy;

	enemy = new EnemyShip[nb_enemy];
	str[1] = '\0';
	Ncurse::init_colors(0, COLOR_CYAN, COLOR_WHITE);
	Ncurse::init_colors(1, COLOR_BLUE, COLOR_WHITE);
	Ncurse::init_colors(2, COLOR_RED, COLOR_WHITE);
	Ncurse::init_colors(3, COLOR_GREEN, COLOR_WHITE);
	Ncurse::init_colors(4, COLOR_YELLOW, COLOR_WHITE);
	Ncurse::init_colors(22, COLOR_RED, COLOR_CYAN);
	Ncurse::init_colors(33, COLOR_YELLOW, COLOR_BLACK);
	game.setBackgroundColor(22);
	info.setBackgroundColor(33);
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
		game.useColor(3);
		game.print(str, player.getPosY(), player.getPosX());
		cptenemy = 0;
		while (cptenemy < nb_enemy)
		{
			EnemyShip &enem = enemy[cptenemy];
			if (!enem.activated ())
			{
				enem.activate ();
				break;
			}
			cptenemy++;
		}
		cptenemy = 0;
		while (cptenemy < nb_enemy)
		{
			EnemyShip &enem = enemy[cptenemy];
			if (enem.activated ())
			{
				if (player == enem)
				{
					int nblives = player.getLives ();
					enem.deactivate ();
					player.setLives(--nblives);
				}
				else if (enem.getPosX () <= 0)
					enem.deactivate ();
				else
				{
					enem--;
					str[0] = enem.getType();
					game.useColor(enem.getColor());
					game.print(str, enem.getPosY(), enem.getPosX());
				}
					
			}
			cptenemy++;
		}
		i = 0;
		if (player.getNbrShoots()) {
			str[0] = player.getSpecificShoot(i).getType();
			while (i < player.getNbrMaxShoots()) {
				if (player.getSpecificShoot(i).getFired()) {
					cptenemy = 0;
					while (cptenemy < nb_enemy)
					{
						EnemyShip &enem = enemy[cptenemy];
						if ((enem.activated ()) && (player.getSpecificShoot(i) == enem))
						{
							player.getSpecificShoot(i).setFired(false);
							enem.deactivate ();
							int score = player.getScore	();
							player.setScore	(++score);
							player.setNbrShoots(player.getNbrShoots() - 1);
						}
							
						cptenemy++;
					}
					if (player.getSpecificShoot(i).getFired())
					{
							
							game.print(str, player.getSpecificShoot(i).getPosY(),
								player.getSpecificShoot(i).getPosX());
					}
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
		if (player.getLives () == 0)
			break;
	}
	return 0;
}
