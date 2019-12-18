/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:44:24 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/17 18:13:16 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_data(t_data *data)
{
	printf("char: >%c<\n", data->str[data->pos]);
	printf("char: >%d<\n", data->str[data->pos]);
	printf("actual_type->%c\n", data->actual_type);
	printf("size->%d\n", data->size);
	printf("pos->%d\n", data->pos);
	printf("width->%d\n", data->width);
	printf("precision->%d\n", data->precision);
	printf("minus_flag->%d\n", data->minus_flag);
	printf("zero_flag->%d\n", data->zero_flag);
	printf("str->%s<\n", data->str);
	printf("out->%.*s<\n", data->size, data->out);
	printf("set_flags->%s\n", data->set_flags);
	printf("set_types->%s\n", data->set_types);
}
//start print_str
char	*ft_width_str(t_data *data, char *str)
{
	int		len;
	int		blank_start;
	int		str_start;
	char	*ret;

	ret = malloc(data->width + 1);
	if (!ret)
		return (0);
	len = ft_strlen(str);
	if (!data->minus_flag)
	{
		blank_start = 0;
		str_start = data->width - len;
	}
	else
	{
		blank_start = len;
		str_start = 0;
	}
	ft_memmove(ret + str_start, str, len);//str
	ft_memset(ret + blank_start, ' ', data->width - len);
	ret[data->width] = 0;
	return (ret);
}

int		ft_print_str(t_data *data)
{
	char	*tab;
	//char	*tab_aux;
	char	*tmp;
	int		size;
	int		precision;

//printf("entra a print_str\n");
//ft_print_data(data);
	tmp = va_arg(g_args, char *);
	if (!tmp)
		tmp = ft_strdup("(null)");
	if (!tmp)
		return (0);
	size = ft_strlen(tmp);
	precision = data->precision >= 0 ? data->precision : size;
	precision  = precision > size ? size : precision;
	tab = ft_strndup(tmp, precision);
	if (!tab)
		return (0);
	if (precision >= data->width)
	{
	//	printf("Acabado string pos = %d pos++ = %d\n", data->pos, data->pos + 1);
		data->pos++;
		return (ft_save(data, tab, precision));
	}
	tmp = ft_width_str(data, tab);
	if (!tmp)
		return (0);
	free (tab);
	//printf("acabado string pos = %d pos++ = %d\n", data->pos, data->pos + 1);
	data->pos++;
	return (ft_save(data, tmp, ft_strlen(tmp)));
}//end print_str
//start print_chr
int		ft_print_chr(t_data *data)
{
	char			*tab;
//	char			*tab_aux;
	unsigned int	chr;
	int				chr_pos;

//printf("entra a print_chr\n");
//ft_print_data(data);
	chr = va_arg(g_args, unsigned int);
	if(data->width <= 1)
	{
		tab = malloc(1);
		if (!tab)
			return (0);
		tab[0] = chr;
		data->pos++;
		return (ft_save(data, tab, 1));
	}
	tab = malloc(data->width);
	if (!tab)
		return (0);
	chr_pos = data->minus_flag ? 0 : data->width - 1;
	ft_memset(tab, ' ', data->width);
	tab[chr_pos] = chr;
	data->pos++;
	return (ft_save(data, tab, data->width));
}//end print_chr
//start print_int
char	*ft_width_int(t_data *data, char *str)
{
	char	*ret;
	char	blank;
	int		str_start;
	int		blank_start;
	int		size;

	ret = malloc(data->width + 1);
	if (!ret)
		return (0);
	ret[data->width] = 0;
	size = ft_strlen(str);
	if (!data->minus_flag)
	{
		blank = data->zero_flag ? '0' : ' ';
		str_start = data->width - size;
		blank_start = 0;
	}
	else
	{
		blank = ' ';
		str_start = 0;
		blank_start = size;
	}
	ft_memset(ret + blank_start, blank, data->width - size);
	ft_memmove(ret + str_start, str, size);
	return (ret);
}

char	*ft_precision_int(t_data *data, char *str, int precision)
{
	char	*ret;
	int		size;

	data->pos = data->pos;
	ret = malloc(precision + 1);
	if (!ret || !str)
		return (0);
	size = ft_strlen(str);
	ret[precision] = 0;
	ft_memset(ret, '0', precision);
	ft_memmove(ret + precision - size, str, size);
	return (ret);
}

void	ft_check_sign(char *str)
{
	int i;
	int zero_pos;

	i = 0;
	//printf("str >%s<\n", str);
	while (str[i] == ' ')
		i++;
	//printf("los espacios acaban en i %d\n", i);
	if (str[i] != '0')
		return ;
	//printf("encontramos un 0\n");
	zero_pos = i;
	while (str[i] == '0')
		i++;
	//printf("los 0s acaban en i %d\n", i);
	if (!ft_in_set("+-", str[i]))
		return ;
	//printf("encontramos un %c\n", str[i]);
	str[zero_pos] = str[i];
	str[i] = '0';
	//printf("mod: >%s<\n", str);
}


int		ft_print_int(t_data *data)
{
	int		n;
	int		size;
	int		precision;
	char	*tab;
	char	*tab_aux;

//ft_print_data(data);
	n = va_arg(g_args, int);
	tab = data->plus_flag ? ft_itoa_plus(n) : ft_itoa(n);
	//printf("num >%s<\n", tab);
	if (!tab)
		return (0);
	precision = data->precision;
	if (data->minus_flag)
		precision = data->precision > data->width ? precision : data->width;
	size = ft_strlen(tab);
	if (precision > size)
	{
		//printf("entra a precision\n");
		tab_aux = ft_precision_int(data, tab, precision);
		free(tab);
		tab = tab_aux;
		size = ft_strlen(tab);
	}
	if (data->width > size)
	{
		//printf("entra a width\n");
		tab_aux = ft_width_int(data, tab);
		free(tab);
		tab = tab_aux;
		size = ft_strlen(tab);
	}
	//ft_check_plus(data, tab);
	//"       000000-123"
	//"       -000000123"
	ft_check_sign(tab);
	data->pos++;
	//printf("devueve %s\n", tab);
	//printf("size: %d\n", size);
	return (ft_save(data, tab, size));
}//end print_int
//start print_uns y valido para %x y %X
int		ft_print_uns(t_data *data)
{
	unsigned int	n;
	int				size;
	int				precision;
	char			*tab;
	char			*tab_aux;

//printf("entra a print_uns\n");
//ft_print_data(data);
	data->actual_type = data->str[data->pos];
	n = va_arg(g_args, unsigned int);
	if (data->actual_type == 'u')
		tab = ft_itoa_unsigned(n, "0123456789");
	else
		tab = data->actual_type == 'x' ? ft_itoa_unsigned(n, "0123456789abcdef") :
			ft_itoa_unsigned(n, "0123456789ABCDEF");
	if (!tab)
		return (0);
	precision = data->precision;
	size = ft_strlen(tab);
	if (data->minus_flag)
		precision = data->precision > data->width ? precision : data->width;
	if (precision > size)
	{
		tab_aux = ft_precision_int(data, tab, precision);
		free(tab);
		tab = tab_aux;
		size = ft_strlen(tab);
	}
	if (data->width > size)
	{
		tab_aux = ft_width_int(data, tab);
		free(tab);
		tab = tab_aux;
		size = ft_strlen(tab);
	}
	data->pos++;
	return (ft_save(data, tab, size));
}//end print_uns y valido para %x y %X
//start print_ptr
char	*ft_precision_ptr(t_data *data, char *str, int precision)
{
	int		len;
	char	*ret;

	data->pos = data->pos;
	len = ft_strlen(str);
	ret = malloc(precision + 1);
	if (!ret)
		return (0);
	ret[precision] = 0;
	ft_memset(ret, '0', precision - len);
	ft_memmove(ret + precision - len, str, len);
	return (ret);
}

char	*ft_width_ptr(t_data *data, char *str)
{
	int		len;
	int		mod;
	int		head_size;
	char	*ret;
	char	*ret_aux;

	len = ft_strlen(str);
	if (len < data->width - 2)
	{
		ret = malloc(data->width - 1);
		if (!ret)
			return (0);
		mod = data->width - 2 - len;
		ret[data->width - 1] = 0;
		ft_memset(ret, ' ', mod);
		ft_memmove(ret + mod, str, len);
	}
	else
		ret = ft_strdup(str);
	if (!ret)
		return (0);
	len = ft_strlen(ret);
	//printf("len %d\n", len);
	head_size = data->plus_flag ? 3 : 2;
	printf("head_size %d\n", head_size);
	ret_aux = malloc(len + head_size + 1);
	printf("reserva: %d\n", len + head_size + 1);
	if (!ret_aux)
		return (0);
	ft_memmove(ret_aux + 2, ret, len);
	ret_aux[0] = data->plus_flag ? '+' : '0';
	ret_aux[1] = data->plus_flag ? '0' : 'x';
	ret_aux[2] = data->plus_flag ? 'x' : ret_aux[2];
	ret_aux[len + head_size + 1] = 0;
	free(ret);
	ret = ret_aux;
	return (ret);
}

int		ft_print_ptr(t_data *data)
{
	long unsigned int	n;
	int					size;
	char				*str;
	char				*str_aux;

//printf("entra a print_ptr\n");
//ft_print_data(data);
	n = va_arg(g_args, long unsigned int);
	str = ft_itoa_unsigned(n, "0123456789abcdef");
	if (!str)
		return (0);
	size = ft_strlen(str);
	//printf("str >%s<\n", str);
	//printf("size: %d\n", size);
	data->zero_flag = data->precision < 0 ? data->zero_flag : 0;
	if (data->zero_flag && !data->minus_flag && data->precision < data->width - 2)
		data->precision = data->width - 2;
	if (data->precision > size)
	{
		str_aux = ft_precision_ptr(data, str, data->precision);
		free(str);
		str = str_aux;
		size = ft_strlen(str);
	}
	str_aux = ft_width_ptr(data, str);
	free(str);
	str = str_aux;
	size = ft_strlen(str);
	data->pos++;
	return (ft_save(data, str, size));
}//end print ptr
//start print ptg
int		ft_print_ptg(t_data *data)
{
	char	*tab;
	//char	*tab_aux;
	char	chr;
	char	blank;
	int		chr_pos;

//printf("entra a print_ptg\n");
//ft_print_data(data);
	chr = '%';

	blank = data->zero_flag && !data->minus_flag ? '0' : ' ';
	if(data->width <= 1)
	{
		tab = malloc(1);
		if (!tab)
			return (0);
		tab[0] = chr;
		data->pos++;
		return (ft_save(data, tab, 1));
	}
	tab = malloc(data->width);
	if (!tab)
		return (0);
	chr_pos = data->minus_flag ? 0 : data->width - 1;
	ft_memset(tab, blank, data->width);
	tab[chr_pos] = chr;
	data->pos++;
	return (ft_save(data, tab, data->width));
}//end print ptg
//start print err
int		ft_print_err(t_data *data)
{
	int i;

//printf("entra a print_err\n");
//ft_print_data(data);
	i = data->pos;
	while (data->str[i] != '%')
		i--;
	ft_save_chr(data, data->str[i]);
	data->pos = i + 1;
	return (1);
}
