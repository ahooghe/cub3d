/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:39:46 by ahooghe           #+#    #+#             */
/*   Updated: 2023/06/05 06:39:47 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && (s[i] != (char)c))
	{
		i++;
	}
	if ((char)c == 0)
		return ((char *)s + i);
	if (!s[i])
		return (NULL);
	return ((char *)s + i);
}
