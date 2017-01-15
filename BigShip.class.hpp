/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BigShip.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 13:44:07 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/15 14:48:57 by cdrouet          ###   ########.fr       */
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
		void		shoot( void );
		void		activate( int posX, int posYmax );
		Shoot		&getSpecificShoot( void ) const;
		void		setLives( int lives );

	private:
		char	_patern[5][7];
		char	_lives;
		Shoot	_shoots;
		bool	_activated;

};

#endif
