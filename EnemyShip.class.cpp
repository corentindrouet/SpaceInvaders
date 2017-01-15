/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemySpaceCraft.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:30:12 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 17:05:47 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyShip.class.hpp"

EnemyShip::EnemyShip( void ) : SpaceCraft() {
	this->_activated = false;
	return;
}

EnemyShip::EnemyShip( EnemyShip const & copy ) {
	*this = copy;
	return;
}

EnemyShip::~EnemyShip( void ) {
	delete [] this->_shoots;
	return;
}

EnemyShip	&EnemyShip::operator=( EnemyShip const & otherEnemyShip ) {
	int		i;
	Shoot	*tmp;

	delete [] this->_shoots;
	i = 0;
	tmp = otherEnemyShip.getShoots();
	this->_nbrMaxShoots = otherEnemyShip.getNbrMaxShoots();
	this->_nbrShoots = otherEnemyShip.getNbrShoots();
	this->_shoots = new Shoot[this->_nbrMaxShoots];
	while (i < this->_nbrShoots) {
		this->_shoots[i] = tmp[i];
		i++;
	}
	return *this;
}

Shoot	*EnemyShip::getShoots( void ) const {
	return this->_shoots;
}

int		EnemyShip::getNbrShoots( void ) const {
	return this->_nbrShoots;
}

int		EnemyShip::getNbrMaxShoots( void ) const {
	return this->_nbrMaxShoots;
}

int		EnemyShip::getColor( void ) const {
	return this->_color;
}

void	EnemyShip::setColor( void ){
	this->_color = rand() % 3;
}

bool	EnemyShip::activated( void ) const {
	return this->_activated;
}

void	EnemyShip::activate( void ) {
	char  en[8] = {'!', '@', '#','$','%', '^','&', '*'};
	static bool init = false;

	if (!init)
	{
		srand ((unsigned int) time(NULL));
		init = true;
	}

	this->_activated = true;
	this->setColor ();
	this->_type = en[rand() % 7];
	this->_posY = rand () % 39;
	this->_posX = 100;
}

void	EnemyShip::deactivate( void ) {
	this->_activated = false;
}

void	EnemyShip::shoot( void ) {
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

EnemyShip	&EnemyShip::operator++( int ) {
	this->_posX++;
	return *this;
}

EnemyShip	&EnemyShip::operator--( int ) {
	this->_posX--;
	return *this;
}

Shoot	&EnemyShip::getSpecificShoot( int index ) const {
	return this->_shoots[index];
}
