/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_to_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:29:37 by asibille          #+#    #+#             */
/*   Updated: 2022/04/07 11:54:59 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_find_str(char **env, char *s)
{
	int		i;
	int		j;

	if (env)
	{
		i = 0;
		while (env[i])
		{
			j = 0;
			while ((env[i][j] == s[j]) && env[i][j] && s[j])
				++j;
			if (!s[j])
				return (env[i]);
			++i;
		}
	}
	return (NULL);
}

static int	ft_divide(char *path_line, char c1, char c2)
{
	int	len;

	len = ft_strlen(path_line);
	while (*path_line)
	{
		if (*path_line == c1 || *path_line == c2)
			*path_line = 0;
		++path_line;
	}
	return (len);
}

static void	ft_exit2(char **cmd)
{
	free(cmd);
	write(2, "No path found in envp\n", 19);
	exit(EXIT_FAILURE);
}

static void	ft_exit3(char **cmd)
{
	write(2, "command not found: ", 19);
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, "\n", 1);
	free(cmd);
	exit(EXIT_FAILURE);
}

char	*ft_cmd_to_path(char **cmd, char **env)
{
	char	*path;
	char	*temp;
	char	*path_line;
	int		len;

	path_line = ft_find_str(env, "PATH=");
	if (!path_line)
		ft_exit2(cmd);
	len = ft_divide(path_line, ' ', ':');
	while (len > 0)
	{
		temp = ft_strjoin(path_line, "/");
		path = ft_strjoin(temp, cmd[0]);
		free(temp);
		if (!access(path, F_OK) && !access(path, X_OK))
			return (path);
		free(path);
		path_line += ft_strlen(path_line) + 1;
		len -= ft_strlen(path_line) + 1;
	}
	ft_exit3(cmd);
	return (NULL);
}
