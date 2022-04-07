/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:47:47 by asibille          #+#    #+#             */
/*   Updated: 2022/04/07 09:29:03 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static size_t	ft_malsize(char const *s, unsigned int start, size_t len)
{
	size_t	mal_size;

	if (start >= ft_strlen(s))
		mal_size = 0;
	else if (len <= (ft_strlen(s) - start))
		mal_size = len;
	else
		mal_size = ft_strlen(s) - start;
	return (mal_size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*ptr_cpy;

	if (!s)
		return (NULL);
	ptr = malloc(ft_malsize(s, start, len) + 1);
	if (!ptr)
		return (NULL);
	ptr_cpy = ptr;
	if (start <= ft_strlen(s))
	{
		s += start;
		while (len > 0 && *s)
		{	
			*ptr_cpy = *s;
			++s;
			++ptr_cpy;
			--len;
		}
	}
	*ptr_cpy = 0;
	return (ptr);
}
