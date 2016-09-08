/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 22:02:15 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/06 22:02:16 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			display_charcolor_buf(t_overlap ov, int influence)
{
	if (ov.final & s_friend)
		ft_putstr_buf(ov.final & s_new ? TBG_RED "o" : TBG_RED "O");
	else if (ov.final & s_enemy)
		ft_putstr_buf(ov.final & s_new ? TBG_BLUE "x" : TBG_BLUE "X");
	else if (ov.score > 0 && influence)
		ft_putstr_buf(influence > 0 ? TBG_RED "." : TBG_BLUE ".");
	else if (ov.score > 0)
		ft_putstr_buf(T_NONE ".");
	else if (influence)
		ft_putstr_buf(influence > 0 ? TBG_RED " " : TBG_BLUE " ");
	else
		ft_putstr_buf(T_NONE " ");
}

void			display_char_buf(t_overlap ov)
{
	if (ov.final & s_friend)
		ft_putstr_buf(ov.final & s_new ? "o" : "O");
	else if (ov.final & s_enemy)
		ft_putstr_buf(ov.final & s_new ? "x" : "X");
	else if (ov.score > 0)
		ft_putstr_buf(".");
	else
		ft_putstr_buf(" ");
}

void			display_score(t_tab table, t_tab piece, t_p move)
{
	t_p			pos;
	int			influence;
	int			previous;
	t_overlap	ov;

	ft_putchar_buf('\n');
	pos.y = -1;
	while (++pos.y < table.height)
	{
		previous = 0;
		pos.x = -1;
		while (++pos.x < table.width)
		{
			ov = check_overlap(table, piece, move, pos);
			influence = get_influence(table, piece, move, TO_SQR(pos)).score;
			if (SIGN(influence) == SIGN(previous))
				display_char_buf(ov);
			else
				display_charcolor_buf(ov, influence);
			previous = influence;
		}
		ft_putstr_buf(T_NONE "\n");
	}
	ft_flush_buf();
}

t_bool			skip_header(void)
{
	int			i;

	i = 0;
	while (i++ < 7)
		if (!ft_readtochar('\n'))
			return (false);
	if (ft_getchar() != 'P')
	{
		if (!ft_readtochar('\n'))
			return (false);
		if (!ft_readtochar('\n'))
			return (false);
	}
	return (true);
}

int				main(void)
{
	t_tab		table;
	t_tab		piece;
	char		buffer[100000];
	int			count;

	count = 0;
	ft_buf(buffer, 100000, 1);
	if (skip_header())
		while (1)
		{
			if (!parse_tables(&table, &piece, false, &count))
				break ;
			display_score(table, NUL_TAB, NUL_POS);
			free_tabs(table, piece);
			if (!ft_readtochar(']'))
				break ;
			if (!ft_readtochar('P'))
				break ;
			if (ft_getchar() == 'i')
				if (!ft_readtochar(']') || !ft_readchar())
					break ;
		}
	return (0);
}
