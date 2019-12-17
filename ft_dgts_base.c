/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dgts_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 10:28:49 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/29 11:19:47 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_dgts_base(long int n, int base_size)
{
	int div;
    int i;

	if (base_size <= 1)
		return (0);
    div = 1;
    i = 0;
    n = n < 0 ? n * -1 : n;
    if (n < base_size)
        return (1);
    while (n > 0)
    {
        n /= base_size;
        i++;
    }
    return (i);
}
