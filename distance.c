/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 18:30:41 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/06 18:30:43 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				dist(t_p a, t_p b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (MAX(ABS(a.x), ABS(a.y)));
}

t_influence		distance_to_piece(t_tab piece, t_p move, t_p pos)
{
	t_p			it;
	t_influence	distance;
	t_influence	best_distance;

	best_distance.rad = INT_MAX;
	best_distance.score = 0;
	distance.score = 1;
	it.y = -1;
	while (++it.y < piece.height)
	{
		it.x = -1;
		while (++it.x < piece.width)
			if (piece.data[it.y][it.x])
			{
				distance.rad = dist(pos, (t_p){move.x + it.x, move.y + it.y});
				if (best_distance.rad > distance.rad)
					best_distance = distance;
				else if (best_distance.rad == distance.rad)
					best_distance.score++;
			}
	}
	return (best_distance);
}

int				simple_distance_to_piece(t_tab piece, t_p move, t_p pos)
{
	int			dist_tl;
	int			dist_tr;
	int			dist_bl;
	int			dist_br;

	dist_tl = dist(move, pos);
	dist_tr = dist((t_p){move.x, move.y + piece.height}, pos);
	dist_bl = dist((t_p){move.x, move.y + piece.height}, pos);
	dist_br = dist((t_p){move.x + piece.width, move.y + piece.height}, pos);
	return (MIN(MIN(dist_br, dist_bl), MIN(dist_tr, dist_tl)));
}
