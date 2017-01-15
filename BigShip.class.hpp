/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigShip.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:44:07 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/15 16:06:10 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIG_SHIP_CLASS_HPP
# define BIG_SHIP_CLASS_HPP
# include "EnemyShip.class.hpp"
# include "Shoot.class.hpp"

class BigShip : public EnemyShip {

	public:
		BigShip( void );
		BigShip( BigShip const & copy );
		~BigShip( void );
		BigShip	&operator=( BigShip const & otherBigShip );
		BigShip	&operator--( int );
		char	**getPatern( void ) const;
		bool	operator==( Shoot const & shoot );
		bool	operator==( SpaceCraft const & ship );
		void		prepareShoot( void );
		void		shoot( void );
		void		activate( int posX, int posYmax );
		Shoot		&getSpecificShoot( void ) const;
		void		setLives( int lives );
		int 		getLives( void );
		bool		getPrepareShoot( void );

	private:
		char	**_patern;
		char	_lives;
		Shoot	_shoots;
		bool	_prepareShoot;

};

#endif
