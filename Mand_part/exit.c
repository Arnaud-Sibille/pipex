/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:29:42 by asibille          #+#    #+#             */
/*   Updated: 2022/04/07 09:29:43 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit(char *parg, char *s, char **arr)
{
	int	i;

	perror(parg);
	i = -1;
	if (arr)
	{
		while (arr[++i])
			free(arr[i]);
	}
	if (s)
		free(s);
	exit(EXIT_FAILURE);
}
