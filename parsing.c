/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:44:34 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/03 16:46:14 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>

t_bool		parse_table_line(t_tab *table, int y, t_bool isx, int *counter)
{
	int		x;
	char	c;

	if (!(table->data[y] = (t_pawn*)malloc(sizeof(t_pawn) * table->width)))
		return (MESS);
	if (!ft_readtochar(' '))
		return (MESS);
	x = -1;
	while (++x < table->width && (c = ft_readchar()))
	{
		if (c == '.')
			table->data[y][x] = s_none;
		else if (c == 'O' || c == 'o')
			table->data[y][x] = (isx ? s_enemy : s_friend);
		else if (c == 'X' || c == 'x')
			table->data[y][x] = (isx ? s_friend : s_enemy);
		else
			return (MESS);
		if (c == 'o' || c == 'x')
			table->data[y][x] |= s_new;
		(*counter) += (table->data[y][x] & s_enemy ? 1 : 0);
	}
	if (ft_readchar() != '\n')
		return (MESS);
	return (true);
}

t_bool		parse_piece_line(t_tab *piece, int y)
{
	int		x;
	char	c;

	if (!(piece->data[y] = (t_pawn*)malloc(sizeof(t_pawn) * piece->width)))
		return (MESS);
	x = 0;
	while (x < piece->width)
	{
		c = ft_readchar();
		if (c == '.')
			piece->data[y][x] = s_none;
		else if (c == '*')
			piece->data[y][x] = s_friend;
		else
			return (MESS);
		x++;
	}
	if (!ft_readtochar('\n'))
		return (MESS);
	return (true);
}

t_bool		parse_header(t_tab *tab)
{
	if (!ft_readtochar(' '))
		return (MESS);
	if (!ft_readint(&(tab->height)))
		return (MESS);
	if (!ft_readtochar(' '))
		return (MESS);
	if (!ft_readint(&(tab->width)))
		return (MESS);
	if (tab->width <= 0 && tab->height <= 0)
		return (MESS);
	if (!ft_readtochar('\n'))
		return (MESS);
	tab->data = (t_pawn**)malloc(tab->height * sizeof(t_pawn*));
	if (tab->data == NULL)
		return (MESS);
	tab->meta = NULL;
	return (true);
}

t_bool		parse_tables(t_tab *table, t_tab *piece, t_bool isx, int *prev)
{
	int		y;
	int		count;

	count = 0;
	if (!parse_header(table))
		return (MESS);
	if (!ft_readtochar('\n'))
		return (MESS);
	y = -1;
	while (++y < table->height)
		if (!parse_table_line(table, y, isx, &count))
			return (MESS);
	if (count != *prev)
		if (!prepare_score(table))
			return (MESS);
	*prev = count;
	if (!parse_header(piece))
		return (MESS);
	y = -1;
	while (++y < piece->height)
		if (!parse_piece_line(piece, y))
			return (MESS);
	return (true);
}

t_bool		parse_intro(t_bool *isx)
{
	int		player;

	if (!ft_readtochar('p'))
		return (MESS);
	if (!ft_readint(&player))
		return (MESS);
	if (!ft_readtochar('\n'))
		return (MESS);
	if (player != 1 && player != 2)
		return (MESS);
	*isx = (player == 2);
	return (true);
}
