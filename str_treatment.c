/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_treatment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:05:46 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/17 17:57:49 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_active_flag(t_data *data, char flag)
{
	if (flag == '-')
		data->minus_flag = 1;
	else if (flag == '0')
		data->zero_flag = 1;
	else if (flag == '+')
		data->plus_flag = 1;
	else
		return (0);
	return (1);
}

int		ft_save_chr(t_data *data, char c)
{
/* original:	
	char	*tmp;
//	printf("reservamos para tmp:");
	if (!(tmp = calloc(2, sizeof(char))))
		return (0);
	tmp[0] = c;
	if (!ft_save(data, tmp))
		return (0);
//	printf(" liberamos");
	free (tmp);
//	printf(" no muere\n");
	
	printf("(chr)size: %d plus %d (%c)\n", data->size, 1, c);
	data->size++;
	return (1);
	*/
	char *tmp;
	int i;
//printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
//printf("(chr)size: %d plus %d (%c)\n", data->size, 1, c);
//printf("data->pos = %d\n", data->pos);
//ft_print_data(data);
//printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	if(!(tmp = malloc(data->size + 1)))//tal vez usar size
		return (0);
	//printf("char added: %c, prev size: %d strlen %d\n", c, data->size, ft_strlen(data->out));
	//printf("data out: %s\n", data->out);
	i = -1;
	//while(data->out[++i])
	//	tmp[i] = data->out[i];
	while (++i < data->size)
		tmp[i] = data->out[i];
	tmp[i] = c;
	free(data->out);
	data->out = tmp;
	//ft_printnchr_fd(data->out, data->size, 1);
	//write(1, "\n", 1);
	data->size++;
	//printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
	return (1);
}
/*
int		ft_save(t_data *data, char *str)
{
	char	*newstr;


	if (!(newstr = ft_strjoin(data->out, str)))
		return (0);
	free (data->out);
	data->out = newstr;
	printf("(str)size: %d plus %d (%s)\n", data->size, ft_strlen(str), str);
	data->size += ft_strlen(str);
	return (1);
}
*/

int		ft_save(t_data *data, char *tab, int size)
{
	char	*tab_aux;

	tab_aux = ft_arraynjoin(data->out, tab, data->size, size);
	//ft_printnchr_fd(tab_aux, data->size + size, 1);
	if (!tab_aux)
		return (0);
//printf("(str)size: %d plus %d (", data->size, size);
//ft_printnchr_fd(tab, size, 1);
//printf(")\n");
//	printf("size: %d\n", data->size);
	data->size += size;
//	printf("new size: %d\n", data->size);
	free(data->out);
	free(tab);
	data->out = tab_aux;
//	ft_printnchr_fd(tab_aux, data->size + 1, 1);
//	write(1, "\n", 1);
	return (1);
}

void	ft_check_sign_position(char *str)
{
	int	i;
	int	first_zero;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] == '0')
	{
		first_zero = i;
		while (str[i] == '0')	
			i++;
		if (str[i] == '-')
		{
			str[i] = '0';
			str[first_zero] = '-';
		}
	}
}

void	ft_data_init(t_data *data, const char *str)
{
//	printf("data init:\n");
	data->pos = 0;
	data->width = 0;
	data->size = 0;
	data->precision = -1;
	data->minus_flag = 0;
	data->plus_flag = 0;
	data->zero_flag = 0;
	data->actual_type = 0;
	data->set_flags = ft_strdup("-0+");
	data->set_types = ft_strdup("ucsdpxXi%");
	data->out = ft_strdup("");
	data->str = ft_strdup(str);
//	printf("sin problemas\n");
}

void	ft_reinit_data(t_data *data)
{
	data->width = 0;
	data->precision = -1;
	data->minus_flag = 0;
	data->zero_flag = 0;
	data->plus_flag = 0;
	data->actual_type = 0;
}
