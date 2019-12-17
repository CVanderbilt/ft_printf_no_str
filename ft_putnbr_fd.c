/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:16:57 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/21 18:14:42 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rec(long int n, int fd)
{
	if (n > 10)
		ft_rec(n / 10, fd);
	n = n % 10 + 48;
	ft_putchar_fd((char)n, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long int nbr;

	nbr = (long int)n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
	}
	ft_rec(nbr, fd);
}
