/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerSpaceCraft.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:30:12 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 16:15:47 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlayerShip.class.hpp"

PlayerShip::PlayerShip( void ) : SpaceCraft() {
	return;
}

PlayerShip::PlayerShip( char c, int posX, int posY, int nbrMaxShoot ) :
SpaceCraft(c, posX, posY) {
	this->_nbrShoots = 0;
	this->_nbrMaxShoots = nbrMaxShoot;
	this->_shoots = new Shoot[nbrMaxShoot];
	return;
}

PlayerShip::PlayerShip( PlayerShip const & copy ) {
	*this = copy;
	return;
}

PlayerShip::~PlayerShip( void ) {
	delete [] this->_shoots;
	return;
}

PlayerShip	&PlayerShip::operator=( PlayerShip const & otherPlayerShip ) {
	int		i;
	Shoot	*tmp;

	delete [] this->_shoots;
	i = 0;
	tmp = otherPlayerShip.getShoots();
	this->_nbrMaxShoots = otherPlayerShip.getNbrMaxShoots();
	this->_nbrShoots = otherPlayerShip.getNbrShoots();
	this->_shoots = new Shoot[this->_nbrMaxShoots];
	while (i < this->_nbrShoots) {
		this->_shoots[i] = tmp[i];
		i++;
	}
	return *this;
}

Shoot	*PlayerShip::getShoots( void ) const {
	return this->_shoots;
}

int		PlayerShip::getNbrShoots( void ) const {
	return this->_nbrShoots;
}

int		PlayerShip::getNbrMaxShoots( void ) const {
	return this->_nbrMaxShoots;
}

void	PlayerShip::shoot( void ) {
	int		i;

	i = 0;
	while (i < this->_nbrMaxShoots) {
		if (!this->_shoots[i].getFired()) {
			break;
		}
		i++;
	}
	this->_shoots[i].setFired(true);
	this->_shoots[i].setPosX(this->_posX + 1);
	this->_shoots[i].setPosY(this->_posY);
	this->_nbrShoots++;
}

PlayerShip	&PlayerShip::operator++( int ) {
	this->_posY--;
	return *this;
}

PlayerShip	&PlayerShip::operator--( int ) {
	this->_posY++;
	return *this;
}

Shoot	&PlayerShip::getSpecificShoot( int index ) const {
	return this->_shoots[index];
}
