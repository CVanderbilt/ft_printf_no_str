/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:31:04 by eherrero          #+#    #+#             */
/*   Updated: 2019/11/21 18:23:05 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contains(char const *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_aux(int *i, int *start, int *control)
{
	*i = 0;
	*start = 0;
	*control = 1;
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		control;

	if (!s1)
		return (0);
	ft_aux(&i, &start, &control);
	while (s1[i])
	{
		if (control && ft_contains(set, s1[i]))
			start++;
		else
			control = 0;
		i++;
	}
	if (control == 1)
		return (ft_substr(s1, 0, 0));
	i--;
	while (ft_contains(set, s1[i]))
		i--;
	return (ft_substr(s1, start, i - start + 1));
}
