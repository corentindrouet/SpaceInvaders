/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ncurse.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 08:49:54 by cdrouet           #+#    #+#             */
/*   Updated: 2017/01/14 15:32:57 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NCURSE_CLASS_HPP
# define NCURSE_CLASS_HPP
# include <iostream>
# include <ncurses.h>
# define KEY_ESC 27
# define KEY_SPACE 32

class Ncurse {

	public:
		Ncurse( void );
		Ncurse( Ncurse const & copy );
		Ncurse( int rows, int columns, int firstRow, int firstColumn );
		~Ncurse( void );
		Ncurse	&operator=( Ncurse const & otherNcurse );
		int		getNbRows( void ) const;
		int		getNbColumns( void ) const;
		int		getFirstRow( void ) const;
		int		getFirstColumn( void ) const;
		void	print( char *c, int y, int x );
		void	clear( void );
		void	refresh( void );
		void	resize( int rows, int columns );
		int		waitForInput( void );
		void	useColor( int colorPairNumber );
		void	setBackgroundColor( int colorPairNumber ); 
		static void	init_colors( short num, short text, short back );

	private:
		int		_nbRows;
		int		_nbColumns;
		int		_firstRow;
		int		_firstColumn;
		WINDOW 	*_win;
};

#endif
