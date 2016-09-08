/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:43:42 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/03 16:46:06 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				calc_bounds(t_tab tab, int x, int y)
{
	if (x >= 1 && x < tab.width - 1 &&
		y >= 1 && y < tab.height - 1)
		return (1);
	if (x >= 0 && x < tab.width &&
		y >= 0 && y < tab.height)
		return (2);
	return (0);
}

int				check_bounds(t_tab tab, int x, int y)
{
	if (x >= 0 && x < tab.width &&
		y >= 0 && y < tab.height)
		return (true);
	return (false);
}

t_overlap		check_overlap(t_tab table, t_tab piece, t_p move, t_p p)
{
	t_overlap	ov;
	int			bounds;

	ov = NUL_OV;
	if (check_bounds(piece, p.x - move.x, p.y - move.y))
		ov.piece = piece.data[p.y - move.y][p.x - move.x];
	bounds = calc_bounds(table, p.x, p.y);
	if (bounds)
		ov.table = table.data[p.y][p.x];
	else if (ov.piece != s_none)
		return (FAIL_OV);
	if (bounds == 2)
		ov.score += 2;
	if (check_bounds(table, p.x - 1, p.y) && table.data[p.y][p.x - 1] & s_pawn)
		ov.score++;
	if (check_bounds(table, p.x + 1, p.y) && table.data[p.y][p.x + 1] & s_pawn)
		ov.score++;
	if (check_bounds(table, p.x, p.y - 1) && table.data[p.y - 1][p.x] & s_pawn)
		ov.score++;
	if (check_bounds(table, p.x, p.y + 1) && table.data[p.y + 1][p.x] & s_pawn)
		ov.score++;
	ov.final = ov.table | ov.piece;
	return (ov);
}

t_bool			is_legal(t_tab table, t_tab piece, t_p move, int *score)
{
	t_p			pos;
	int			ovcount;
	t_overlap	ov;

	ovcount = 0;
	*score = 0;
	pos.y = move.y - 1;
	while (++pos.y < move.y + piece.height)
	{
		pos.x = move.x - 1;
		while (++pos.x < move.x + piece.width)
		{
			ov = check_overlap(table, piece, move, pos);
			if (ov.piece & s_fail ||
				(ov.piece & s_friend && ov.table & s_enemy))
				return (false);
			if (ov.piece & ov.table & s_friend && ovcount > 0)
				return (false);
			if (ov.piece & ov.table & s_friend)
				ovcount++;
			if ((ov.piece & s_friend))
				(*score) += ov.score;
		}
	}
	return (ovcount == 1);
}
