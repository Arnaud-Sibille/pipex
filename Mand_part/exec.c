/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:29:30 by asibille          #+#    #+#             */
/*   Updated: 2022/04/07 09:29:31 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec1(char **argv, char **env, int *pfd)
{
	char	**cmd;
	int		file_fd;
	char	*path;

	close(pfd[0]);
	file_fd = open(argv[1], O_RDONLY);
	if (file_fd == -1)
		ft_exit("open(argv[1], O_RDONLY)", NULL, NULL);
	if (dup2(file_fd, STDIN_FILENO) == -1)
		ft_exit("dup2(fd, STDIN_FILENO)", NULL, NULL);
	close(file_fd);
	if (dup2(pfd[1], STDOUT_FILENO) == -1)
		ft_exit("dup2(pfd[1], STDOUT_FILENO)", NULL, NULL);
	close(pfd[1]);
	cmd = ft_split(argv[2], ' ');
	if (!cmd)
		ft_exit("ft_split(argv[2], ' ')", NULL, NULL);
	path = ft_cmd_to_path(cmd, env);
	if (execve(path, cmd, NULL) == -1)
		ft_exit("execve(path, cmd, NULL)", path, cmd);
}

void	ft_exec2(char **argv, char **env, int *pfd)
{
	char	**cmd;
	int		file_fd;
	char	*path;

	close(pfd[1]);
	file_fd = open(argv[4], O_WRONLY | O_CREAT, 420);
	if (file_fd == -1)
		ft_exit("open(argv[4], O_WRONLY | O_CREAT, 420)", NULL, NULL);
	if (dup2(file_fd, STDOUT_FILENO) == -1)
		ft_exit("dup2(file_fd, STDOUT_FILENO)", NULL, NULL);
	close(file_fd);
	if (dup2(pfd[0], STDIN_FILENO) == -1)
		ft_exit("dup2(pfd[0], STDIN_FILENO)", NULL, NULL);
	close(pfd[0]);
	cmd = ft_split(argv[3], ' ');
	if (!cmd)
		ft_exit("ft_split(arg[3], ' ')", NULL, NULL);
	path = ft_cmd_to_path(cmd, env);
	if (execve(path, cmd, NULL) == -1)
		ft_exit("second execve(path, cmd, NULL)", path, cmd);
}
