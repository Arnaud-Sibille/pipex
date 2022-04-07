/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:50:00 by asibille          #+#    #+#             */
/*   Updated: 2022/04/07 09:28:46 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static size_t	ft_malsizeb(char const *s, char c)
{
	size_t	mal_size;

	mal_size = 0;
	while (*s && (*s != c))
	{
		++mal_size;
		++s;
	}
	return (mal_size);
}

static size_t	ft_malsizea(char const *s, char c)
{
	size_t	mal_size;
	int		in;

	in = 1;
	mal_size = 0;
	while (*s)
	{
		if (*s != c)
			in = 0;
		else if (in == 1)
			;
		else
		{
			++mal_size;
			in = 1;
		}
		++s;
	}
	if (in == 0)
		++mal_size;
	return (mal_size);
}

static int	ft_freesplit(char **ptr, size_t i)
{
	if (!ptr[i])
	{
		while ((i) >= 0)
		{
			free(ptr[i]);
			--(i);
		}
		free(ptr);
		return (1);
	}
	else
		return (0);
}

static size_t	ft_algo_split(char const *s, char c, char **ptr, size_t *i)
{
	while (*s)
	{
		if (*s != c)
		{
			ptr[*i] = (ft_substr(s, 0, ft_malsizeb(s, c)));
			if (ft_freesplit(ptr, *i))
				return (-1);
			++(*i);
			s = s + ft_malsizeb(s, c);
		}
		else
			++s;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**ptr;
	size_t	ret_algo;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (ft_malsizea(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	ret_algo = ft_algo_split(s, c, ptr, &i);
	if ((int) ret_algo == -1)
		return (NULL);
	ptr[i] = NULL;
	return (ptr);
}
