/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceCraft.class.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:37:45 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 11:50:47 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACECRAFT_HPP
# define SPACECRAFT_HPP
# include <iostream>

class SpaceCraft {

	public:
		SpaceCraft( void );
		SpaceCraft( SpaceCraft const & copy );
		SpaceCraft( char c );
		~SpaceCraft( void );
		SpaceCraft	&operator=( SpaceCraft const & otherSpaceCraft );
		int			getPosX( void );
		int			getPosY( void );
		int			getType( void );

	protected:
		int		posX;
		int		posY;
		char	type;
};

#endif
