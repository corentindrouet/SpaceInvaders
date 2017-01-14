/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerSpaceCraft.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 12:48:42 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 16:13:00 by cdrouet          ###   ########.fr       */
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
		int			getNbrMaxShoots( void ) const;
		PlayerShip	&operator++( int );
		PlayerShip	&operator--( int );
		Shoot		&getSpecificShoot( int index ) const;

	private:
		Shoot	*_shoots;
		int		_nbrShoots;
		int		_nbrMaxShoots;
};

#endif
