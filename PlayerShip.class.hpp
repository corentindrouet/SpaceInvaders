/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerSpaceCraft.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:48:42 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 17:35:07 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_SPACE_CRAFT_HPP
# define PLAYER_SPACE_CRAFT_HPP
# include "Shoot.class.hpp"

class PlayerShip : public SpaceCraft {

	public:
		PlayerShip( void );
		PlayerShip( char c, int posX, int posY, int nbrMaxShoot );
		PlayerShip( PlayerShip const & copy );
		~PlayerShip( void );
		PlayerShip	&operator=( PlayerShip const & otherPlayerShip );
		void		shoot( void );
		Shoot		*getShoots( void ) const;
		int			getNbrShoots( void ) const;
		void		setNbrShoots( int nbrShoots );
		int			getNbrMaxShoots( void ) const;
		PlayerShip	&operator++( int );
		PlayerShip	&operator--( int );
		Shoot		&getSpecificShoot( int index ) const;
		int			getScore( void ) const;
		int			getLives( void ) const;
		void		setScore( int newScore );
		void		setLives( int newLive );

	private:
		Shoot	*_shoots;
		int		_nbrShoots;
		int		_nbrMaxShoots;
		int		_score;
		int		_lives;
};

#endif
