/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahooghe <ahooghe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 06:38:09 by ahooghe           #+#    #+#             */
/*   Updated: 2023/06/05 06:38:10 by ahooghe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	arr_size;

	if (size > 4294967294 || nmemb > 4294967294)
		return (NULL);
	arr_size = nmemb * size;
	if (arr_size > 2147483647)
		return (NULL);
	arr = malloc(arr_size);
	if (!arr)
		return (NULL);
	ft_bzero(arr, arr_size);
	return (arr);
}
