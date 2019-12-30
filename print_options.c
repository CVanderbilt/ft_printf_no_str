/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:44:24 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/18 18:28:25 by eherrero         ###   ########.fr       */
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
	printf("l_flag->%d\n", data->l_flag);
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
	free (str);
	return (ret);
}
/*
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
}*/

char	*ft_precision_int(t_data *data, char *str)
{
	char	*ret;
	int		len;

	len = ft_strlen(str);
	if (data->precision < len)
	{
		if (len == 1 && str[0] == '0' && data->precision >= 0)
		{
			free (str);
			return (ft_strdup(""));
		}
		else
			return (str);
	}
	ret = ft_calloc(data->precision + 1, 1);
	if (!ret)
		return (str);
	ret[data->precision] = 0;
	//printf("str: %p\np_mod: %d\nstr_mod: %p\nlen_mod: %d\nlen: %d\nprecision: %d\n", str, precision_mod, str_mod, len_mod, len, data->precision);
	//printf("memmove ret + p_mod, str_mod, len_mod\n");
	ft_memmove(ret + data->precision - len, str, len);
	//printf("moved: %s\n", ret);
	free (str);
	return (ret);
}

/*char	*ft_check_sign(t_data *data, char *str, int n)
{
	int		i;
	int		dgts;
	int		sign_pos;
	int		zero_pos;
	char	*ret;

	//printf("str >%s<\n", str);
	//printf("1\n");
	//if (!data->plus_flag && n >= 0)
	//	return (str);
	//printf("2 i: %d\n", i);
	i = 0;
	while (str[i] == ' ')
		i++;
	//printf("3\n");
	if (str[i] != '0')
		return (str);
	//printf("4\n");
	dgts = 0;
	zero_pos = i;
	while (str[i])
	{
		if (ft_in_set("+-", str[i]))
		{
			sign_pos = i;
			//printf("sign_pos: %d\n", i);
		}
		i++;
		dgts++;
	}
	if (dgts > data->precision)
	{
		str[zero_pos] = str[sign_pos];
		str[sign_pos] = '0';
		return (str);
	}
	else
	{
		if (zero_pos >= 1)
		{
			str[zero_pos - 1] = str[sign_pos];
			str[sign_pos] = '0';
			return (str);
		}
		else
		{
			dgts = ft_strlen(str);
			ret = malloc(dgts + 2);
			if (!ret)
				return (0);
			ret[dgts + 1] = 0;
			ft_memmove (ret + 1, str, dgts);
			ret[0] = str[sign_pos];
			ret[sign_pos + 1] = '0';
			//printf("copy:%s\n", ret);
			free(str);
			return (ret);
		}
	}

}*/

char	*ft_check_sign(char *str)
{
	int		i;
	int		frst_dgt;
	int		sign_pos;
	char	tmp;

	i = 0;
	while (str[i] == ' ')
		i++;
	frst_dgt = i;
	while (str[i] == '0')
		i++;
	if (!str[i] || ft_isdigit(str[i]))
		return (str);
	//printf("sin cambios: >%s<\n", str);
	if (str[i] == ' ' && (str[i + 1] == ' ' || !str[i + 1]))
		return (str);
	sign_pos = i;
	tmp = str[sign_pos];
	str[sign_pos] = str[frst_dgt];
	str[frst_dgt] = tmp;
	//printf("con cambios: >%s<\n", str);
	return (str);
}

int		ft_print_int(t_data *data)
{
	long long int	n;
	int				size;
	int				precision;
	char			*tab;
	char			*tab_aux;

//ft_print_data(data);

	/*if (data->l_flag)
		n = data->l_flag == 1 ? va_arg(g_args, long int) : va_arg(g_args, long long int);
	else if (data->h_flag)
		n = data->h_flag == 1 ? va_arg(g_args, short) : va_arg(g_args, unsigned char);
	else
		n = va_arg(g_args, int);*/
	data->zero_flag = data->minus_flag ? 0 : data->zero_flag;
	n = va_arg(g_args, long long int);
	if (data->l_flag)
		n = data->l_flag == 1 ? (long int)n : n;
	else if (data->h_flag)
		n = data->h_flag == 1 ? (short)n : (signed char)n;
	else
		n = (int)n;
	if (n < 0)
		tab_aux = ft_strdup("-");
	else if (data->plus_flag || data->blank_flag)
		tab_aux = data->plus_flag ? ft_strdup("+") : ft_strdup(" ");
	else
		tab_aux = ft_strdup("");
	n *= n < 0 ? -1 : 1;
	tab = ft_itoa(n); // hay que cambiar itoas para que devuelvan long long int
	//tab = ft_strjoinfree(tab_aux, tab, 'B');
	//printf("num >%s<\n", tab);
	if (!tab)
		return (0);
	precision = data->precision;
	data->zero_flag = precision >= 0 ? 0 : data->zero_flag; // si precision cabcela 0_flag
	//if (data->minus_flag)
	//	precision = data->precision > data->width ? precision : data->width;
	
	//printf("precision: %d\n", precision);
	size = ft_strlen(tab);
	//printf("size: %d\n", size);
	//printf("tab: >%s<\n", tab);
	tab = ft_precision_int(data, tab);
	if (!data->zero_flag)
	{
		tab = ft_strjoinfree(tab_aux, tab, 'B');
		size = ft_strlen(tab);
	}
	//printf("tab p: >%s<\n", tab);
	if (data->width > size)
	{
		//printf("entra a width\n");
		tab = ft_width_int(data, tab);
		size = ft_strlen(tab);
	}
	if (data->zero_flag)
	{
		//printf("width: %d\nsize: %d\n", data->width, size);
		if (data->width < size)
			tab = ft_strjoinfree(tab_aux, tab, 'B');
		else
		{
		//	printf("tab_aux[0]: >%c<\ntab[0]: >%c<\n", tab_aux[0], tab[0]);
			if (tab[0] == ' ' || (tab[0] == '0' && size > 1))
			{
				tab[0] = tab_aux[0] ? tab_aux[0] : tab[0];
				free (tab_aux);
			}
			else
			{
				//printf("tab_aux: >%s< tab: >%s<\n", tab_aux, tab);
				tab = ft_strjoinfree(tab_aux, tab, 'B');
			}
		}
	}
	//printf("tab pw: >%s<\n", tab);
	//ft_check_plus(data, tab);
	//"       000000-123"
	//"       -000000123"
	//"         00000006"
	//"x         00000006"
	//printf"tab >%s<\n", tab);
	//printf("width: %d,size: %d\n", data->width, size);

	tab = ft_check_sign(tab);
	size = ft_strlen(tab);
	/*
	if ((data->width < size || !data->zero_flag) && (n < 0 || data->plus_flag))
	{
		//printf("entra primer if\n");
		//printf("width: %d,size: %d\n", data->width, size);
		//printf("tab >%s<\n", tab);
		n = ft_get_pos(tab, '0');
		if (n >= 0)
		{
		//	printf("??\n");
			tab_aux = malloc(size + 1);
			if (!tab_aux)
				return (0);
			//printf("tab:     %s\n", tab);
			ft_memmove(tab_aux + 1, tab, size);
			tab_aux[0] = tab_aux[1];
			tab_aux[n] = '0';
			//printf("size: %d\n", size);
			tab_aux[size + 1] = 0;
			//printf("tab_aux: %s\n", tab_aux);
			free(tab);
			tab = tab_aux;
			size = ft_strlen(tab);
		}
	}
	*/
	data->pos++;
	//printf("devueve %s\n", tab);
	//printf("size: %d\n", size);
	return (ft_save(data, tab, size));
}//end print_int
//start print_uns y valido para %x y %X
char	*ft_check_prefix(t_data *data, char *str, char *prefix)
{
	//printf("str:    %s\n", str);
	//printf("prefix: %s\n", prefix);
	if (!prefix)
		return (str);
	if (data->actual_type == 'o' && str[0] == '0')
		return (str);
	return (ft_arraynjoinfreeR(prefix, str, ft_strlen(prefix), ft_strlen(str) + 1));
}

char	*ft_check_prefix_mod(char *str)
{
	int i;
	int zero_pos;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (str[i] != '0' || ft_in_set("xX", str[i + 1]))
		return (str);
	zero_pos = i;
	while (str[i] == '0')
		i++;
	if (ft_in_set("xX", str[i]))
	{
		str[zero_pos + 1] = str[i];
		str[i] = '0';
	}
	return (str);
}

char	*ft_prefix_select(t_data *data, char type, unsigned long long int n)
{
	if (type == 'p')
		return (ft_strdup("0x"));
	if (data->hash_flag && ft_in_set("xX", type) && n != 0)
		return (type == 'x' ? ft_strdup("0x") : ft_strdup("0X"));
	if (data->hash_flag && type == 'o')
		return (ft_strdup("0"));
	return (0);
}

int		ft_print_uns(t_data *data)
{
	unsigned long long int	n;
	int						size;
	int						precision;
	char					*tab;
	char					*prefix;

//printf("entra a print_uns\n");
//ft_print_data(data);
	data->actual_type = data->str[data->pos];
	n = va_arg(g_args, unsigned long long int);
	prefix = ft_prefix_select(data, data->actual_type, n);
	tab = 0;
	if (data->actual_type != 'p')
	{
		if (data->l_flag)
			n = data->l_flag == 1 ? (unsigned long int)n : n;
		else if (data->h_flag)
			n = data->h_flag == 1 ? (unsigned short)n : (unsigned char)n;
		else
			n = (unsigned int)n;
	}
	if (data->actual_type == 'u')
		tab = ft_itoa_unsigned(n, "0123456789");
	else if (ft_in_set("xXp", data->actual_type))
		tab = data->actual_type == 'x' || data->actual_type == 'p'? ft_itoa_unsigned(n, "0123456789abcdef") :
			ft_itoa_unsigned(n, "0123456789ABCDEF");
	else if (data->actual_type == 'o')
		tab = ft_itoa_unsigned(n, "01234567");
	if (!tab)
		return (0);
	//printf("tab: >%s<\n", tab);
	precision = data->precision;
	size = ft_strlen(tab);
	if (data->minus_flag)
		precision = data->precision > data->width ? precision : data->width;
	tab = ft_precision_int(data, tab);
	size = ft_strlen(tab);
	//printf("tab p: >%s<\n", tab);
	/*if (precision > size)
	{
		tab_aux = ft_precision_int(data, tab, precision);
		free(tab);
		tab = tab_aux;
		size = ft_strlen(tab);
	}*/
	tab = ft_check_prefix(data, tab, prefix);
	//printf("tab pp: >%s<\n", tab);
	size = ft_strlen(tab);
	if (data->width > size)
	{
		tab = ft_width_int(data, tab);
		size = ft_strlen(tab);
	}
	if (data->actual_type != 'o')
		tab = ft_check_prefix_mod(tab);
	//printf("tab ppw: >%s<\n", tab);
	//printf("size: %d\n", size);
	data->pos++;
	if (prefix)
		free (prefix);
	return (ft_save(data, tab, size));
}//end print_uns y valido para %x y %X y %p
//start print dbl
int		ft_print_dbl(t_data *data)
{


	data->pos = data->pos;
	return (0);	
}
//end print dbl

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
//start print num
int		ft_print_num(t_data *data)
{
	int *p;

	p = va_arg(g_args, int *);
	if (!p)
		return (1);
	*p = data->size;
	return (1);
}
//end print num
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
