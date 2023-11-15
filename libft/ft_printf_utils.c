/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:39:12 by ahooghe           #+#    #+#             */
/*   Updated: 2023/06/05 06:39:13 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_str(char *str)
{
	int	printed;

	printed = 0;
	if (str == NULL)
		return (print_str("(null)"));
	while (str[printed])
	{
		ft_putchar_fd(str[printed], 1);
		printed++;
	}
	return (printed);
}

char	*u_itoa(unsigned int n)
{
	char			*a;
	int				digits;
	unsigned int	num;

	num = n;
	digits = 1;
	while (num / 10 != 0)
	{
		digits++;
		num /= 10;
	}
	a = (char *)malloc((digits + 1) * sizeof(char));
	if (a == NULL)
		return (NULL);
	a[digits] = '\0';
	while (digits > 0)
	{
		a[digits - 1] = n % 10 + '0';
		digits--;
		n /= 10;
	}
	return (a);
}

int	print_unsigned(unsigned int n)
{
	int		printed;
	char	*a;

	printed = 0;
	a = u_itoa(n);
	printed += print_str(a);
	free(a);
	return (printed);
}

int	print_nbr(int n)
{
	int		printed;
	char	*a;

	printed = 0;
	a = ft_itoa(n);
	printed += print_str(a);
	free(a);
	return (printed);
}

int	print_char(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
