/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:38:23 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/12 19:39:33 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_state_print(t_data *data)
{
	int		i;
	char	*str;
/*
	printf("----------ft_state_print----------\n\n");
	ft_print_data(data);
	printf("----------------------------------\n\n");
	*/
	i = data->pos;
	str = data->str;
	//printf("str[i]: >%c<\n", str[i]);
	if (str[i] == 'c')
		return (ft_printf_chr(data));
	if (str[i] == 's')
		return (ft_printf_str(data));
	if (ft_in_set("di", str[i]))
		return (ft_printf_int(data));
	if (str[i] == 'p')
		return (ft_printf_ptr(data));
	if (ft_in_set("xX", str[i]))
		return (ft_printf_hex(data));
	if (str[i] == '%')
		return (ft_printf_ptg(data));
	if (str[i] == 'u')
		return (ft_printf_uns(data));
	else
		return (ft_printf_err(data));
}

int		ft_state_precision(t_data *data)
{
	int		i;
	char	*str;
/*
	printf("--------ft_state_precision--------\n\n");
	ft_print_data(data);
	printf("----------------------------------\n\n");
	*/

	i = data->pos;
	str = data->str;
	if (str[i] != '.')
		return (0);
	data->precision = 0;
	i++;
	if (str[i] == '*')
	{
		data->precision = va_arg(g_args, int);
		i++;
	}
	else
	{
		data->precision = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	data->pos = i;
	return (ft_state_print(data));
}

int		ft_state_width(t_data *data)
{
	int		i;
	char	*str;
/*
	printf("----------ft_state_width----------\n\n");
	ft_print_data(data);
	printf("----------------------------------\n\n");
	*/
	i = data->pos;
	str = data->str;
	if (str[i] == '*')
	{
		data->width = va_arg(g_args, int);
		i++;
	}
	else if (ft_isdigit(str[i]))
	{
		data->width = ft_atoi(str + i);
		while (ft_isdigit(str[i]))
			i++;
	}
	else
		return (0);
	data->pos = i;
	if (str[i] == '.')
		return (ft_state_precision(data));
	return (ft_state_print(data));
}

int		ft_state_flags(t_data *data)
{
	int		i;
	char	*str;
	char	*set;
/*
	printf("----------ft_state_flags----------\n\n");
	ft_print_data(data);
	printf("----------------------------------\n\n");
	*/
	set = data->set_flags;
	str = data->str;
	i = data->pos;
	if (!ft_active_flag(data, str[i]))
	{
		if (str[i] == '.')
			return (ft_state_precision(data));
		if (str[i] == '*' || ft_isdigit(str[i]))
			return (ft_state_width(data));
		//if (ft_in_set(data->set_types, str[i]))
		return (ft_state_print(data));
	}	
	data->pos++;
	return (ft_state_flags(data));
}

int		ft_printf(const char *str, ...)
{
	t_data	data;

	ft_data_init(&data, str);
	va_start (g_args, str);
	//printf("\n\n???\n\n");
	while (str[data.pos])
	{
		//printf("\n\nentra al while\nanaliza: %c\n", str[data.pos]);
		if (str[data.pos] == '%')
		{
			data.pos++;
			if (str[data.pos] == '%')
			{
				ft_save(&data, "%");
				data.pos++;
			}
			else
				ft_state_flags(&data);
		}
		else
		{
			//printf("save\n");
			ft_save_chr(&data, data.str[data.pos]);
			data.pos++;
		}
		ft_reinit_data(&data);
	}

/*	printf("-----------final_state------------\n\n");
	ft_print_data(&data);
	printf("----------------------------------\n\n");
	*/

	
	//printf("original:\n");	
	//ft_putstr_fd(data.out, 1);
	//printf("nuevo:\n");	
	ft_printnchr_fd(data.out, data.size, 1);
	return (data.size);

	printf("num: %d\n", data.size);
	ft_putstr_fd(data.out, 1);
	return (ft_strlen(data.out));
}
/*
int main()
{
	int tst = 128098;
	int	a;
	int b;
	int c;
	int d;
	//:w
	//char *p = ft_strdup("kktest");
	//printf("\n\n???\n\n");
	//ft_printf("ho%ca, %s%d", 'l', "mundo", 33);
	printf("PROPIO:\n");
	//tst = ft_printf(">%-20p%-20p%-20p%-20p<", &a, &b, &c, &d);
	tst = ft_printf(">%2.9p<", 1234);
	printf("result: %d\n", tst);
	printf("=====================================\n");
	printf("SYSTEM:\n");
	//tst = printf(">%-20p%-20p%-20p%-20p<", &a, &b, &c, &d);
	tst = printf(">%2.9p<", 1234);
	printf("result: %d\n", tst);
	//printf("%");
}*/
