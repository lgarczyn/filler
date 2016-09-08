/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/03 17:21:03 by lgarczyn          #+#    #+#             */
/*   Updated: 2016/09/03 17:21:07 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool			ft_readint(int *target)
{
	char	c;

	c = ft_getchar();
	if (c < '0' || c > '9')
		return (false);
	*target = c - '0';
	ft_readchar();
	while (ft_getchar() >= '0' && ft_getchar() <= '9')
	{
		*target = *target * 10 + ft_getchar() - '0';
		ft_readchar();
	}
	return (true);
}
