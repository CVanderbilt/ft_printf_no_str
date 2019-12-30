/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eherrero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:30:26 by eherrero          #+#    #+#             */
/*   Updated: 2019/12/17 17:19:55 by eherrero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

va_list			g_args;

typedef struct	s_data
{
	int			pos;
	int			size;
	int			width;
	int			precision;
	int			minus_flag;
	int			zero_flag;
	int			plus_flag;
	int			l_flag;
	int 		h_flag;
	int			blank_flag;
	int			hash_flag;
	char		actual_type;
	const char	*str;
	char		*out;
	char		*set_flags;
	char		*set_types;
}				t_data;



//printf.c
int				ft_state_print(t_data *data);
int				ft_state_precision(t_data *data);
int				ft_state_width(t_data *data);
int				ft_state_flags(t_data *data);
int				ft_printf(const char *str, ...);
//printf.c

//printt_options.c
int				ft_print_chr(t_data *data);
int				ft_print_str(t_data *data);
int				ft_print_int(t_data *data);
int				ft_print_uns(t_data *data);
int				ft_print_ptr(t_data *data);
int				ft_print_hex(t_data *data);
int				ft_print_ptg(t_data *data);
int				ft_print_num(t_data *data);
int				ft_print_err(t_data *data);
//printt_options.c

//data management
void			ft_data_init(t_data *data, const char *str);
void			ft_reinit_data(t_data *data);
void			ft_print_data(t_data *data);
void			ft_free_data(t_data *data);
int				ft_active_flag(t_data *data, char flag);
int				ft_save(t_data *data, char *src, int size);
int				ft_save_chr(t_data *data, char c);
//data management

//utils
void			ft_check_sign_position(char *str);
//utils
#endif
