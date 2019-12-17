/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:09:35 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/29 10:19:14 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(long int n)
{
	int			dgts;
	int			min;
	long int	n2;
	char		*p;

	dgts = n >= 0 ? ft_dgts(n) : ft_dgts(n) + 1;
	if (!(p = malloc(dgts + 1)))
		return (0);
	min = n >= 0 ? 0 : 1;
	p[0] = '-';
	p[dgts] = 0;
	n2 = n;
	n2 *= n >= 0 ? 1 : -1;
	while (--dgts >= min)
	{
		p[dgts] = n2 % 10 + 48;
		n2 /= 10;
	}
	return (p);
}
