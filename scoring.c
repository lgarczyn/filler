/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scoring.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:44:37 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/03 16:46:09 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				get_score_pos(t_tab table, t_tab piece, t_p move, t_p pos)
{
	t_influence	dist;
	t_influence	dist_piece;
	t_sqr		sqr;

	if (table.data[pos.y][pos.x] & s_captured)
		return (1);
	dist = table.meta[pos.y][pos.x];
	if (dist.rad == 0)
		return (-1);
	dist_piece.rad = simple_distance_to_piece(piece, move, pos);
	if (dist.rad < dist_piece.rad)
		return (-1);
	dist_piece = distance_to_piece(piece, move, pos);
	if (dist.rad > dist_piece.rad)
		return (1);
	if (dist.rad < dist_piece.rad)
		return (-1);
	if (dist.score > dist_piece.score)
		return (-1);
	if (dist.score < dist_piece.score)
		return (1);
	sqr = (t_sqr){pos, dist.rad};
	dist.score = get_influence(table, piece, move, sqr).score;
	return (CLAMP(dist.score, -1, 1));
}

int				get_score(t_tab table, t_tab piece, t_p move)
{
	t_p			pos;
	int			influence;
	int			value;

	if (!is_legal(table, piece, move, &value))
		return (INT_MIN);
	if (table.meta == NULL)
		return (value);
	influence = 0;
	pos.y = 0;
	while (pos.y < table.height)
	{
		pos.x = 0;
		while (pos.x < table.width)
		{
			influence += get_score_pos(table, piece, move, pos);
			pos.x++;
		}
		pos.y++;
	}
	return ((influence * 10) + value);
}

t_bool			prepare_score(t_tab *table)
{
	t_p			pos;
	t_influence	influence;

	table->meta = malloc(table->height * sizeof(t_influence*));
	if (table->meta == NULL)
		return (MESS);
	pos.y = 0;
	while (pos.y < table->height)
	{
		table->meta[pos.y] = malloc(table->width * sizeof(t_influence));
		if (table->meta[pos.y] == NULL)
			return (MESS);
		pos.x = 0;
		while (pos.x < table->width)
		{
			influence = get_influence(*table, NUL_TAB, NUL_POS, TO_SQR(pos));
			if (influence.score > 0)
				table->data[pos.y][pos.x] |= s_captured;
			influence.score = ABS(influence.score);
			table->meta[pos.y][pos.x] = influence;
			pos.x++;
		}
		pos.y++;
	}
	return (true);
}
