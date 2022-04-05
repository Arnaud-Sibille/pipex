/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:35:41 by asibille          #+#    #+#             */
/*   Updated: 2022/01/10 18:08:20 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ptr = malloc(sizeof(*s1) * (s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	while (*s1)
	{
		*ptr = *s1;
		++ptr;
		++s1;
	}
	while (*s2)
	{
		*ptr = *s2;
		++ptr;
		++s2;
	}
	*ptr = 0;
	return (ptr - s1_len - s2_len);
}
