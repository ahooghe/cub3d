/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:39:57 by ahooghe           #+#    #+#             */
/*   Updated: 2023/06/05 06:39:58 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	if (s == NULL)
	{
		dup = (char *)malloc(sizeof (char));
		dup[0] = '\0';
		return (dup);
	}
	size = (ft_strlen(s) + 1) * sizeof(char);
	dup = (char *)malloc(size);
	if (!dup)
		return (NULL);
	ft_memmove(dup, s, size);
	return (dup);
}
