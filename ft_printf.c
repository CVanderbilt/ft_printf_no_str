/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:38:23 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/17 18:13:17 by eherrero         ###   ########.fr       */
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
		return (ft_print_chr(data));
	if (str[i] == 's')
		return (ft_print_str(data));
	if (ft_in_set("di", str[i]))
		return (ft_print_int(data));
	if (str[i] == 'p')
		return (ft_print_ptr(data));
	if (ft_in_set("uxX", str[i]))
		return (ft_print_uns(data));
	if (str[i] == '%')
		return (ft_print_ptg(data));
	else
		return (str[i] == 0 ? 1 : ft_print_err(data));
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
		return (str[i] == 0 ? 1 : 0);//modificado para cuando null acabar
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
	return (str[i] == 0 ? 1 : ft_state_print(data));//modificado para  cuandp null acabar
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
		return (str[i] == 0 ? 1 : 0);//modificado para cuando null acabar
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
		return (str[i] = 0 ? 1 : ft_state_print(data));//modificado para cundo null acabar
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
		printf("parece que modificamos str, hacer const");
		printf("\n----------intro----------\n");
		ft_print_data(&data);
		printf("-------------------------\n\n");
		if (str[data.pos] == '%')
		{
//printf("encontrado %%: data->pos = %d\n", data.pos);
			data.pos++;
			//printf("kk\n");
			ft_state_flags(&data);
			//printf("??\n");
		}
		else
		{
			//printf("save\n");
			ft_save_chr(&data, data.str[data.pos]);
			data.pos++;
		}
		//printf("next_char: >%c<\n", str[data.pos]);
		ft_reinit_data(&data);
	}
/*
	printf("-----------final_state------------\n\n");
	ft_print_data(&data);
	printf("----------------------------------\n\n");
*/	

	
	//printf("original:\n");	
	//ft_putstr_fd(data.out, 1);
	//printf("nuevo:\n");
	ft_printnchr_fd(data.out, data.size, 1);
	return (data.size);
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
