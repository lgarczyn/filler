/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:44:31 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/03 16:46:17 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdlib.h>
#include <time.h>

void		display(t_p pos)
{
	char	buffer[100];

	ft_buf(buffer, 100, 1);
	ft_putnbr_buf(pos.y);
	ft_putchar_buf(' ');
	ft_putnbr_buf(pos.x);
	ft_putchar_buf('\n');
	ft_flush_buf();
}

t_bool		filler(t_bool isx, int *enemy_count)
{
	t_tab	table;
	t_tab	piece;
	t_move	move;
	t_move	best;

	if (!parse_tables(&table, &piece, isx, enemy_count))
		return (false);
	best = (t_move){(t_p){0, 0}, INT_MIN + 1};
	move.pos.y = -piece.height + 1;
	while (move.pos.y < table.height)
	{
		move.pos.x = -piece.width + 1;
		while (move.pos.x < table.width)
		{
			move.score = get_score(table, piece, move.pos);
			if (best.score < move.score ||
				(best.score == move.score && rand() % 1024 >= 600))
				best = move;
			move.pos.x++;
		}
		move.pos.y++;
	}
	display(best.pos);
	free_tabs(table, piece);
	return (true);
}

int			main(void)
{
	t_bool	isx;
	int		enemy_count;

	enemy_count = 0;
	srand(clock());
	if (!parse_intro(&isx))
		return (1);
	while (1)
		if (!filler(isx, &enemy_count))
			return (1);
}
