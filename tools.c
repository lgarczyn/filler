/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 16:44:28 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/03 16:46:24 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_bool			message(const char *func, const char *file, int line)
{
	ft_putstr_fd("failure in file {", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd("} in {", 2);
	ft_putstr_fd(func, 2);
	ft_putstr_fd("} at {", 2);
	ft_putnbr_fd(line, 2);
	ft_putstr_fd("}\n", 2);
	return (false);
}

void			free_tab(t_tab tab)
{
	int			i;

	i = 0;
	while (i < tab.height)
		free(tab.data[i++]);
	free(tab.data);
	if (tab.meta)
	{
		i = 0;
		while (i < tab.height)
			free(tab.meta[i++]);
		free(tab.meta);
	}
}

void			free_tabs(t_tab table, t_tab piece)
{
	free_tab(table);
	free_tab(piece);
}
