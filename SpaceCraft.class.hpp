/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceCraft.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:37:45 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/15 14:08:29 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACECRAFT_HPP
# define SPACECRAFT_HPP
# include <iostream>

class SpaceCraft {

	public:
		SpaceCraft( SpaceCraft const & copy );
		SpaceCraft( char c, int x, int y );
		~SpaceCraft( void );
		SpaceCraft	&operator=( SpaceCraft const & otherSpaceCraft );
		bool		operator==( SpaceCraft const & otherSpaceCraft );
		int			getPosX( void ) const;
		int			getPosY( void ) const;
		char		getType( void ) const;

	protected:
		SpaceCraft( void );
		char	_type;
		int		_posX;
		int		_posY;
};

#endif
