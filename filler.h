/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 02:06:12 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/05 02:06:13 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H

# include <limits.h>
# include <libft.h>
# include <unistd.h>
# include <stdio.h>

typedef enum		e_pawn
{
	s_none = 0,
	s_friend = 1,
	s_enemy = 2,
	s_pawn = 3,
	s_new = 4,
	s_fail = 8,
	s_captured = 16,
}					t_pawn;

typedef struct		s_p
{
	int				x;
	int				y;
}					t_p;

typedef struct		s_influence
{
	int				score;
	int				rad;
}					t_influence;

typedef struct		s_move
{
	t_p				pos;
	int				score;
}					t_move;

typedef struct		s_sqr
{
	t_p				pos;
	int				rad;
}					t_sqr;

typedef struct		s_tab
{
	int				width;
	int				height;
	t_pawn			**data;
	t_influence		**meta;
}					t_tab;

typedef struct		s_overlap
{
	t_pawn			table;
	t_pawn			piece;
	t_pawn			final;
	char			score;
}					t_overlap;

# define FAIL_OV	(t_overlap){s_fail, s_fail, s_fail, 0}
# define NUL_OV		(t_overlap){s_none, s_none, s_none, 0}
# define NUL_TAB	(t_tab){0, 0, NULL, NULL}
# define NUL_POS	(t_p){0, 0}
# define NUL_SQR	(t_sqr){0, 0}
# define TO_SQR(p)	(t_sqr){p, 0}

void				free_tabs(t_tab table, t_tab piece);
t_bool				message(const char *func, const char *file, int line);
# define MESS   	message(__func__, __FILE__, __LINE__)

t_bool				parse_tables(t_tab *ta, t_tab *pi, t_bool isx, int *p);
t_bool				parse_intro(t_bool *isx);

t_bool				is_legal(t_tab table, t_tab piece, t_p move, int *score);
t_overlap			check_overlap(t_tab table, t_tab piece, t_p move, t_p p);

int					simple_distance_to_piece(t_tab piece, t_p move, t_p pos);
t_influence			distance_to_piece(t_tab piece, t_p move, t_p pos);

t_influence			get_influence(t_tab table, t_tab piece, t_p move, t_sqr s);
int					get_score(t_tab table, t_tab piece, t_p move);
t_bool				prepare_score(t_tab *table);

#endif
