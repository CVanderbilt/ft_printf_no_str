/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 18:45:57 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/17 18:01:23 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printnchr_fd(const char *str, int n, int fd)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(str[i], fd);
		//printf("%c", str[i]);
		i++;
	}
}
