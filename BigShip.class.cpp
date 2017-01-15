/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigShip.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:49:48 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/15 16:20:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BigShip.class.hpp"

BigShip::BigShip( void ) {
	int	i = 0;
	this->_patern = new char*[5];
	while (i < 5) {
		this->_patern[i] = new char[8];
		i++;
	}
	std::memcpy(this->_patern[0], "   /[|\0", 7);
	std::memcpy(this->_patern[1], " /---[\0", 7);
	std::memcpy(this->_patern[2], "== 3 |\0", 7);
	std::memcpy(this->_patern[3], " \\---[\0", 7);
	std::memcpy(this->_patern[4], "   \\[|\0", 7);
	this->_activated = false;
	this->_shoots.setFired(false);
	this->_prepareShoot = 0;
	this->_lives = 3;
	this->_nbrShoots = 0;
}

BigShip::BigShip( BigShip const & copy ) {
	*this = copy;
	return;
}

BigShip::~BigShip( void ) {
	int	i = 0;

	while(i < 5) {
		delete [] this->_patern[i];
		i++;
	}
	delete [] this->_patern;
	return;
}

BigShip	&BigShip::operator=( BigShip const & otherBigShip ) {
	std::memcpy(this->_patern[0], otherBigShip.getPatern()[0], 7);
	std::memcpy(this->_patern[1], otherBigShip.getPatern()[1], 7);
	std::memcpy(this->_patern[2], otherBigShip.getPatern()[2], 7);
	std::memcpy(this->_patern[3], otherBigShip.getPatern()[3], 7);
	std::memcpy(this->_patern[4], otherBigShip.getPatern()[4], 7);
	return *this;
}

char	**BigShip::getPatern( void ) const {
	return (char**)this->_patern;
}

BigShip	&BigShip::operator--( int ) {
	this->_posX--;
	return *this;
}

bool	BigShip::operator==( Shoot const & shoot ) {
	return ((shoot.getPosY() == this->_posY &&
		 		shoot.getPosX() >= (this->_posX + 3)) ||
			(shoot.getPosY() == (this->_posY + 1) &&
		 		shoot.getPosX() >= (this->_posX + 1)) ||
			(shoot.getPosY() == (this->_posY + 2) &&
		 		shoot.getPosX() >= (this->_posX)) ||
			(shoot.getPosY() == (this->_posY + 3) &&
		 		shoot.getPosX() >= (this->_posX + 1)) ||
			(shoot.getPosY() == (this->_posY + 4) &&
		 		shoot.getPosX() >= (this->_posX + 3)));
}

bool	BigShip::operator==( SpaceCraft const & ship ) {
	return ((ship.getPosY() == this->_posY &&
		 		ship.getPosX() >= (this->_posX + 3)) ||
			(ship.getPosY() == (this->_posY + 1) &&
		 		ship.getPosX() >= (this->_posX + 1)) ||
			(ship.getPosY() == (this->_posY + 2) &&
		 		ship.getPosX() >= (this->_posX)) ||
			(ship.getPosY() == (this->_posY + 3) &&
		 		ship.getPosX() >= (this->_posX + 1)) ||
			(ship.getPosY() == (this->_posY + 4) &&
		 		ship.getPosX() >= (this->_posX + 3)));
}

void	BigShip::setLives( int lives ) {
	this->_lives = lives;
	this->_patern[2][3] = '0' + this->_lives;
	return;
}

void	BigShip::activate( int posX, int posYmax ) {
	this->_activated = true;
	this->_posX = posX;
	this->_posY = std::rand() % (posYmax - 4);
	this->_lives = 3;
	this->_patern[2][3] = '0' + this->_lives;
	return;
}

int 		BigShip::getLives( void ) {
	return this->_lives;
}

void		BigShip::prepareShoot( void ) {
	this->_prepareShoot = true;
	return;
}

void		BigShip::shoot( void ) {
	this->_prepareShoot = false;
	return;
}

bool 		BigShip::getPrepareShoot( void ) {
	return this->_prepareShoot;
}
