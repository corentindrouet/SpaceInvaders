/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 09:53:15 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/15 11:51:02 by cdrouet          ###   ########.fr       */
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
	int		nb_enemy = 100;
	EnemyShip		*enemy;
	int		j = 3;
	int		moduloPopEnnemy = 10;
	int		moduloPopBullets = 100;
	std::time_t	start = std::time(NULL);
	int		secondsDiff = 0;
	bool	cursor = true;

	Ncurse::init_colors(5, COLOR_WHITE, COLOR_WHITE);
	Ncurse::init_colors(0, COLOR_CYAN, COLOR_WHITE);
	Ncurse::init_colors(1, COLOR_BLUE, COLOR_WHITE);
	Ncurse::init_colors(2, COLOR_RED, COLOR_WHITE);
	Ncurse::init_colors(3, COLOR_GREEN, COLOR_WHITE);
	Ncurse::init_colors(4, COLOR_YELLOW, COLOR_WHITE);
	Ncurse::init_colors(22, COLOR_GREEN, COLOR_BLACK);
	Ncurse::init_colors(23, COLOR_RED, COLOR_BLACK);
	Ncurse::init_colors(24, COLOR_WHITE, COLOR_BLACK);
	Ncurse::init_colors(33, COLOR_YELLOW, COLOR_BLACK);
	while (true) {
		newWin.setBackgroundColor(24);
		newWin.print((char*)"Play", (newWin.getNbRows() / 2),
				(newWin.getNbColumns() / 2) - 2);
		newWin.print((char*)"Quit", (newWin.getNbRows() / 2) + 1,
				(newWin.getNbColumns() / 2) - 2);
		newWin.print((char*)">", (newWin.getNbRows() / 2) + ((cursor) ? 0 : 1),
				(newWin.getNbColumns() / 2) - 4);
		newWin.refresh();
		keyValue = newWin.waitForInput();
		newWin.clear();
		if (keyValue == 10 && cursor) {
			start = std::time(NULL);
			enemy = new EnemyShip[nb_enemy];
			str[1] = '\0';
			newWin.setBackgroundColor(5);
			game.setBackgroundColor(22);
			info.setBackgroundColor(33);
			game.refresh();
			newWin.clear();
			newWin.refresh();
			info.refresh();
			while (true) {
				if (((j - 3) % moduloPopBullets) == 0) {
					player.setNbBullets(player.getNbBullets() + 10);
					moduloPopBullets += 50;
				}
				keyValue = game.waitForInput();
				if (keyValue == KEY_ESC) {
					break;
				} else if (keyValue == KEY_UP && player.getPosY() > 0) {
					player++;
				} else if (keyValue == KEY_DOWN && player.getPosY() < (game.getNbRows() - 1)) {
					player--;
				} else if (keyValue == KEY_SPACE) {
					if (player.getNbBullets())
						player.shoot();
				}
				game.clear();
				info.clear();
				str[0] = player.getType();
				game.useColor(24);
				game.print(str, player.getPosY(), player.getPosX());
				cptenemy = 0;
				if (moduloPopEnnemy > 1 && (j % 100) == 0)
					moduloPopEnnemy--;
				if ((j % moduloPopEnnemy) == 0) {
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
				}
				cptenemy = 0;
				game.useColor(23);
				while (cptenemy < nb_enemy)
				{
					EnemyShip &enem = enemy[cptenemy];
					if (enem.activated ())
					{
						int	shoots = 0;
						if (player == enem)
						{
							int nblives = player.getLives ();
							enem.deactivate ();
							player.setLives(--nblives);
						}
						else if (enem.getPosX () <= 0)
							enem.deactivate ();
						else {
							str[0] = enem.getType();
							game.print(str, enem.getPosY(), enem.getPosX());
						}
						if ((j % 3) == 0)
							enem--;
						if ((j % 10) == 0)
							enem.shoot();
						str[0] = '-';
						while (shoots < enem.getNbrMaxShoots()) {
							if (enem.getSpecificShoot(shoots).getFired()) {
								if (enem.getSpecificShoot(shoots) == player) {
									int nblives = player.getLives ();
									enem.getSpecificShoot(shoots).setFired(false);
									player.setLives(--nblives);
								} else {
									game.print(str, enem.getSpecificShoot(shoots).getPosY(),
											enem.getSpecificShoot(shoots).getPosX());
									enem.getSpecificShoot(shoots)--;
								}
							}
							shoots++;
						}
					}
					cptenemy++;
				}
				i = 0;
				game.useColor(22);
				if (player.getNbrShoots()) {
					str[0] = player.getSpecificShoot(i).getType();
					while (i < player.getNbrMaxShoots()) {
						if (player.getSpecificShoot(i).getFired()) {
							cptenemy = 0;
							while (cptenemy < nb_enemy)
							{
								EnemyShip &enem = enemy[cptenemy];
								if ((enem.activated ()) && (player.getSpecificShoot(i) >= enem))
								{
									player.getSpecificShoot(i).setFired(false);
									enem.deactivate ();
									int score = player.getScore	();
									player.setScore	(++score);
									player.setNbrShoots(player.getNbrShoots() - 1);
									player.setNbBullets(player.getNbBullets() + 1);
								}
								cptenemy++;
							}
							if (player.getSpecificShoot(i).getFired())
							{
								game.print(str, player.getSpecificShoot(i).getPosY(),
										player.getSpecificShoot(i).getPosX());
								player.getSpecificShoot(i)++;
							}
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
				secondsDiff = difftime(std::time(NULL), start);
				info.print((char*)"Seconds: ", 24, 0);
				info.print((char *)(std::to_string(secondsDiff).c_str()), 24, 10);
				info.print((char*)"Bullets: ", 26, 0);
				info.print((char *)(std::to_string(player.getNbBullets()).c_str()), 26, 10);
				game.refresh();
				game.refresh();
				info.refresh();
				napms(50);
				if (player.getLives () == 0)
					break;
				j++;
			}
			game.clear();
			game.setBackgroundColor(5);
			game.refresh();
			info.clear();
			info.setBackgroundColor(5);
			info.refresh();
			delete [] enemy;
			player.reset((game.getNbColumns() * 4) / 100,
					game.getNbRows() / 2);
		} else if (keyValue == KEY_UP) {
			cursor = true;
		} else if (keyValue == KEY_DOWN) {
			cursor = false;
		} else if (keyValue == 10 && !cursor)
			break;

	}
	return 0;
}
