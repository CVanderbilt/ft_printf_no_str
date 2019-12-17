/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:44:24 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/16 17:26:35 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_data(t_data *data)
{
	printf("char: >%c<\n", data->str[data->pos]);
	printf("actual_type->%c\n", data->actual_type);
	printf("pos->%d\n", data->pos);
	printf("width->%d\n", data->width);
	printf("precision->%d\n", data->precision);
	printf("minus_flag->%d\n", data->minus_flag);
	printf("zero_flag->%d\n", data->zero_flag);
	printf("str->%s\n", data->str);
	printf("out->%s\n", data->out);
	printf("set_flags->%s\n", data->set_flags);
	printf("set_types->%s\n", data->set_types);
}

int		ft_print_chr(t_data *data)
{
	char	*tab;
	int		size;
	int		pos_chr;

	size = data->width > 0 ? data->width : 1;
	tab = malloc(size);
	if (!tab)
		return (0);
	ft_memset(tab, ' ', size);
	pos_chr = data->minus_flag ? size : 0;
	tab[pos_chr] = va_arg(g_args, unsigned int);
	return(ft_save(tab, size));
}

int		ft_print_str(t_data *data)
{
	char	*tab;
	char	*tab_aux;
	char	*tmp;
	int		size;

	tmp = va_arg(g_args, char *);
	size = ft_strlen(tmp);
	data->precision = data->precision > 0 ? data->precision : size;
	data->precison  = data->precision > size ? size : data->precision;
	tab = ft_strndup(tmp, data->precision);
	if (!tab)
		return (0);
	size = data->precision > data->width ? data->precision : data->width;
	if (data->width > data->precision)
	{
		tab_aux = 
	}
}