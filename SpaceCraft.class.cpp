/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceCraft.class.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:49:06 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 15:32:57 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceCraft.class.hpp"

SpaceCraft::SpaceCraft( void ) {
	return;
}

SpaceCraft::SpaceCraft( SpaceCraft const & copy ) {
	*this = copy;
	return;
}

SpaceCraft::SpaceCraft( char c, int x, int y ) : _type(c), _posX(x), _posY(y) {
	return;
}

SpaceCraft	&SpaceCraft::operator=( SpaceCraft const & otherSpaceCraft ) {
	this->_posX = otherSpaceCraft.getPosX();
	this->_posY = otherSpaceCraft.getPosY();
	this->_type = otherSpaceCraft.getType();
	return *this;
}

SpaceCraft::~SpaceCraft( void ) {
	return;
}

int		SpaceCraft::getPosX( void ) const {
	return this->_posX;
}

int		SpaceCraft::getPosY( void ) const {
	return this->_posY;
}

char	SpaceCraft::getType( void ) const {
	return this->_type;
}

bool	SpaceCraft::operator==( SpaceCraft const & otherSpaceCraft ) {
	return (this->_posX == otherSpaceCraft.getPosX() &&
			this->_posY == otherSpaceCraft.getPosY());
}
