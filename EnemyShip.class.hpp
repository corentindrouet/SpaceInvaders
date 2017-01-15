/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemySpaceCraft.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:48:42 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/15 16:19:57 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_SPACE_CRAFT_HPP
# define ENEMY_SPACE_CRAFT_HPP
# include "Shoot.class.hpp"

class EnemyShip : public SpaceCraft {

	public:

		EnemyShip( void );
		EnemyShip( EnemyShip const & copy );
		~EnemyShip( void );
		EnemyShip	&operator=( EnemyShip const & otherEnemyShip );
		EnemyShip	&operator==( Shoot const & shoot );
		void		shoot( void );
		Shoot		*getShoots( void ) const;
		int			getNbrShoots( void ) const;
		int			getNbrMaxShoots( void ) const;
		bool		activated( void ) const;
		int			getColor( void ) const;
		void		setColor( void );
		void		activate( int posX, int posYmax );
		void		deactivate( void );
		EnemyShip	&operator++( int );
		EnemyShip	&operator--( int );
		Shoot		&getSpecificShoot( int index ) const;

	protected:
		bool	_activated;
		int		_nbrShoots;

	private:
		Shoot	*_shoots;
		int		_nbrMaxShoots;
		int     _color;
};

#endif
