/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   influence.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 22:04:30 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/06 22:04:34 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				get_infl_pos(t_tab table, t_tab piece, t_p move, t_p pos)
{
	t_pawn		result;

	if (pos.x >= 0 && pos.y >= 0)
		if (pos.x < table.width && pos.y < table.height)
		{
			result = table.data[pos.y][pos.x];
			if (result & s_friend)
				return (1);
			if (result & s_enemy)
				return (-1);
		}
	pos.x -= move.x;
	pos.y -= move.y;
	if (pos.x >= 0 && pos.y >= 0)
		if (pos.x < piece.width && pos.y < piece.height)
		{
			result = piece.data[pos.y][pos.x];
			if (result & s_friend)
				return (1);
		}
	return (0);
}

int				get_infl_sqr(t_tab table, t_tab piece, t_p move, t_sqr sqr)
{
	int			infl;
	t_p			pos;

	if (sqr.rad == 0)
		return (get_infl_pos(table, piece, move, sqr.pos));
	pos.x = sqr.pos.x - sqr.rad;
	pos.y = sqr.pos.y - sqr.rad;
	infl = 0;
	while (pos.x < sqr.pos.x + sqr.rad)
		infl += get_infl_pos(table, piece, move, (t_p){pos.x++, pos.y});
	while (pos.y < sqr.pos.y + sqr.rad)
		infl += get_infl_pos(table, piece, move, (t_p){pos.x, pos.y++});
	while (pos.x > sqr.pos.x - sqr.rad)
		infl += get_infl_pos(table, piece, move, (t_p){pos.x--, pos.y});
	while (pos.y > sqr.pos.y - sqr.rad)
		infl += get_infl_pos(table, piece, move, (t_p){pos.x, pos.y--});
	return (infl);
}

t_influence		get_influence(t_tab table, t_tab piece, t_p move, t_sqr sqr)
{
	int			maxrad;
	int			rad;
	int			infl;

	maxrad = MAX(table.width, table.height);
	rad = sqr.rad;
	while (rad < maxrad)
	{
		infl = get_infl_sqr(table, piece, move, (t_sqr){sqr.pos, rad});
		if (infl < 0)
			return ((t_influence){-1, rad});
		if (infl > 0)
			return ((t_influence){1, rad});
		rad++;
	}
	return ((t_influence){0, rad});
}
