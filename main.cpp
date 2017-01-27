/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 09:53:15 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/15 16:39:33 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ncurse.class.hpp"
#include <ctime>
#include "PlayerShip.class.hpp"
#include "EnemyShip.class.hpp"
#include "BigShip.class.hpp"
#include <sstream>
namespace std {
	template<typename T>
		std::string to_string(const T &n) {
			std::ostringstream s;
			s << n;
			return s.str();
		}
}

char	*strRepeat( char c, int size ) {
	char	*str = new char[size + 1];
	int		i = 0;

	while (i < size) {
		str[i] = c;
		i++;
	}
	str[size] = '\0';
	return str;
}

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
	Shoot	*backGround;
	BigShip	*boss;
	int		actualJ[5] = {0, 0, 0, 0, 0};


	init_color(COLOR_CYAN, 212, 212, 212);
	Ncurse::init_colors(5, COLOR_WHITE, COLOR_WHITE);
	Ncurse::init_colors(0, COLOR_CYAN, COLOR_BLACK);
	Ncurse::init_colors(1, COLOR_BLUE, COLOR_BLACK);
	Ncurse::init_colors(2, COLOR_RED, COLOR_BLACK);
	Ncurse::init_colors(3, COLOR_GREEN, COLOR_BLACK);
	Ncurse::init_colors(4, COLOR_YELLOW, COLOR_BLACK);
	Ncurse::init_colors(22, COLOR_GREEN, COLOR_BLACK);
	Ncurse::init_colors(23, COLOR_RED, COLOR_BLACK);
	Ncurse::init_colors(24, COLOR_WHITE, COLOR_BLACK);
	Ncurse::init_colors(25, COLOR_CYAN, COLOR_BLACK);
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
			backGround = new Shoot[10];
			boss = new BigShip[5];
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
				game.useColor(25);
				if (((j - 3) % 30) == 0) {
					i = 0;
					while (i < 10) {
						if (!backGround[i].getFired()) {
							backGround[i].setFired(true);
							backGround[i].setPosX(game.getNbColumns() - 1);
							backGround[i].setPosY(std::rand() % game.getNbRows());
							backGround[i].setType('0');
							break;
						}
						i++;
					}
				}
				i = 0;
				while (i < 10) {
					if (backGround[i].getFired() && backGround[i].getPosX() <= 0)
						backGround[i].setFired(false);
					if (backGround[i].getFired()){
						str[0] = backGround[i].getType();
						game.print(str, backGround[i].getPosY(), backGround[i].getPosX());
						backGround[i]--;
					}
					i++;
				}
				cptenemy = 0;
				if (moduloPopEnnemy > 1 && (j % 100) == 0)
					moduloPopEnnemy--;
				if ((j % moduloPopEnnemy) == 0) {
					while (cptenemy < nb_enemy)
					{
						EnemyShip &enem = enemy[cptenemy];
						if (!enem.activated ())
						{
							enem.activate (game.getNbColumns() - 1, game.getNbRows());
							break;
						}
						cptenemy++;
					}
				}
				cptenemy = 0;
				while (cptenemy < nb_enemy)
				{
					EnemyShip &enem = enemy[cptenemy];
					game.useColor(enem.getColor());
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
						if ((std::rand() % 100) == 5)
							enem.shoot();
						str[0] = '-';
						while (shoots < enem.getNbrMaxShoots()) {
							if (enem.getSpecificShoot(shoots).getFired()) {
								if (enem.getSpecificShoot(shoots) == player) {
									int nblives = player.getLives ();
									enem.getSpecificShoot(shoots).setFired(false);
									player.setLives(--nblives);
								} else if (enem.getSpecificShoot(shoots).getPosX() <= 0) {
									enem.getSpecificShoot(shoots).setFired(false);
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
				if ((j % 100) == 0) {
					i = 0;
					while (i < 5) {
						if (!boss[i].activated()) {
							boss[i].activate(game.getNbColumns() - 6, game.getNbRows());
							break;
						}
						i++;
					}
				}
				i = 0;
				while (i < 5) {
					game.useColor(24);
					if (boss[i].activated()) {
						if (boss[i] == player) {
							boss[i].deactivate();
							player.setLives(0);
						} else if (boss[i].getPosX() < -5)
							boss[i].deactivate();
						else {
							game.print(boss[i].getPatern()[0], boss[i].getPosY(), boss[i].getPosX());
							game.print(boss[i].getPatern()[1], boss[i].getPosY() + 1, boss[i].getPosX());
							game.print(boss[i].getPatern()[2], boss[i].getPosY() + 2, boss[i].getPosX());
							game.print(boss[i].getPatern()[3], boss[i].getPosY() + 3, boss[i].getPosX());
							game.print(boss[i].getPatern()[4], boss[i].getPosY() + 4, boss[i].getPosX());
						}
						if ((j % 5) == 0) {
							boss[i]--;
						}
						if (!boss[i].getPrepareShoot() && (std::rand() % 100) == 5) {
							actualJ[i] = 0;
							boss[i].prepareShoot();
						} else if (boss[i].getPrepareShoot())
							actualJ[i]++;
						if (boss[i].getPrepareShoot() && actualJ[i] < 100) {
							char	*tmp = strRepeat('-', boss[i].getPosX());
							game.useColor(25);
							game.print(tmp, boss[i].getPosY() + 2, 0);
							delete [] tmp;
						} else if (boss[i].getPrepareShoot() && actualJ[i] >= 100 && actualJ[i] <= 150) {
							char	*tmp = strRepeat('-', boss[i].getPosX());
							if (actualJ[i] == 150)
								boss[i].shoot();
							game.print(tmp, boss[i].getPosY() + 2, 0);
							if (player.getPosY() == (boss[i].getPosY() + 2)) {
								player.setLives(0);
							}
							delete [] tmp;
						}
					}
					i++;
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
							cptenemy = 0;
							while (cptenemy < 5)
							{
								BigShip &bossI = boss[cptenemy];
								if ((bossI.activated()) && (bossI == player.getSpecificShoot(i)))
								{
									player.getSpecificShoot(i).setFired(false);
									if (bossI.getLives() == 1) {
										int score = player.getScore	();
										bossI.deactivate();
										player.setScore	(score + 10);
										player.setNbrShoots(player.getNbrShoots() - 1);
										player.setNbBullets(player.getNbBullets() + 1);
									} else {
										bossI.setLives( bossI.getLives() - 1);
									}
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
				str[0] = player.getType();
				game.useColor(24);
				game.print(str, player.getPosY(), player.getPosX());
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
			delete [] backGround;
			delete [] boss;
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
