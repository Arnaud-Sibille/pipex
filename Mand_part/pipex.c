/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:29:46 by asibille          #+#    #+#             */
/*   Updated: 2022/04/14 10:34:52 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_getfile(char *file)
{
	int	file_fd;

	file_fd = open(file, O_TRUNC | O_RDWR | O_CREAT, 420);
	if (file_fd == -1)
		ft_exit("file", NULL, NULL);
	return (file_fd);
}

static void	ft_check_fid(int fid)
{
	if (fid == -1)
		ft_exit(NULL, NULL, NULL);
}

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	int		fid;
	int		ret;
	int		out_fd;

	if (argc == 5)
	{
		out_fd = ft_getfile(argv[4]);
		if (pipe(pfd) == -1)
			ft_exit(NULL, NULL, NULL);
		fid = fork();
		ft_check_fid(fid);
		if (!fid)
			ft_exec1(argv, envp, pfd);
		fid = fork();
		ft_check_fid(fid);
		if (!fid)
			ft_exec2(argv, envp, pfd, out_fd);
		close(pfd[0]);
		close(pfd[1]);
		wait(&fid);
		ret = WEXITSTATUS(fid);
		return (ret);
	}
}
