/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemySpaceCraft.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:48:42 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 17:04:40 by jblancha         ###   ########.fr       */
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
		void		activate(void);
		void		deactivate(void);
		EnemyShip	&operator++( int );
		EnemyShip	&operator--( int );
		Shoot		&getSpecificShoot( int index ) const;

	private:
		Shoot	*_shoots;
		int		_nbrShoots;
		int		_nbrMaxShoots;
		bool	_activated;
		int     _color;
};

#endif
