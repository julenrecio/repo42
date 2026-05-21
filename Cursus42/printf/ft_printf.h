/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 17:33:17 by jrecio-t          #+#    #+#             */
/*   Updated: 2026/05/21 16:07:06 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(char const *format, ...);
int	ft_printf_decimal(int n);
int	ft_printf_unsigned_decimal(unsigned int n);
int ft_printf_hex(unsigned int i, int mayus);
int ft_printf_pointer(size_t p);

#endif