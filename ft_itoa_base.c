/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 09:34:07 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/29 10:38:22 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa_base(long int n, char *base)
{
	int		len;
	int		min;
	int		dgts;
	char	*nbr_base;

	if (!base)
		return (0);
	len = ft_strlen(base);
	dgts = n >= 0 ? ft_dgts_base(n, len) : ft_dgts_base(n, len) + 1;
	if (!(nbr_base = malloc(dgts + 1)))
		return (0);
	nbr_base[0] = '-';
	nbr_base[dgts] = 0;
	min = n >= 0 ? 0 : 1;
	n *= n >= 0 ? 1 : -1;
	while (--dgts >= min)
	{
		nbr_base[dgts] = base[n % len];
		n /= len;
	}
	return (nbr_base);
}
