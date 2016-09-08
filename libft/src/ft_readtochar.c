/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readtochar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:20:49 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/03 17:20:50 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_readtochar(char c)
{
	while (ft_getchar() != c)
	{
		if (ft_getchar() == '\0')
			return (false);
		else
			ft_readchar();
	}
	ft_readchar();
	return (true);
}
