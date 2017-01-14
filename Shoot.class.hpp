/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shoot.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 13:14:36 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 15:39:38 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOOT_CLASS_HPP
# define SHOOT_CLASS_HPP
# include "SpaceCraft.class.hpp"

class Shoot {

	public:
		Shoot( void );
		Shoot( Shoot const & copy );
		~Shoot( void );
		Shoot	&operator=( Shoot const & otherShoot );
		bool	operator==( SpaceCraft const & ship );
		int		getFired( void ) const;
		int		getPosX( void ) const;
		int		getPosY( void ) const;
		int		getType( void ) const;
		void	setFired( int fire );
		void	setPosX( int pos );
		void	setPosY( int pos );
		Shoot	&operator++( int );

	private:
		int		_fired;
		int		_posX;
		int		_posY;
		char	_type;
};

#endif
