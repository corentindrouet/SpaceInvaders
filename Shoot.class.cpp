/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 14:28:40 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/15 14:24:18 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Shoot.class.hpp"

Shoot::Shoot( void ) : _fired(false), _posX(0), _posY(0), _type('-') {
	return;
}

Shoot::Shoot( Shoot const & copy ) {
	*this = copy;
	return;
}

Shoot::~Shoot( void ) {
	return;
}

Shoot	&Shoot::operator=( Shoot const & otherShoot ) {
	this->_fired = otherShoot.getFired();
	this->_posX = otherShoot.getPosX();
	this->_posY = otherShoot.getPosY();
	this->_type = otherShoot.getType();
	return *this;
}

bool	Shoot::operator>=( SpaceCraft const & ship ) {
	return (this->_posX >= ship.getPosX() &&
			this->_posY == ship.getPosY());
}

bool	Shoot::operator==( SpaceCraft const & ship ) {
	return (this->_posX == ship.getPosX() &&
			this->_posY == ship.getPosY());
}

int		Shoot::getFired( void ) const {
	return this->_fired;
}

int		Shoot::getPosX( void ) const {
	return this->_posX;
}

int		Shoot::getPosY( void ) const {
	return this->_posY;
}

int		Shoot::getType( void ) const {
	return this->_type;
}

void	Shoot::setFired( int fire ) {
	this->_fired = fire;
	return;
}

void	Shoot::setPosX( int pos ) {
	this->_posX = pos;
	return;
}

void	Shoot::setPosY( int pos ) {
	this->_posY = pos;
	return;
}

void	Shoot::setType( char c ) {
	this->_type = c;
	return;
}

Shoot	&Shoot::operator++( int ) {
	this->_posX++;
	return *this;
}

Shoot	&Shoot::operator--( int ) {
	this->_posX--;
	return *this;
}
