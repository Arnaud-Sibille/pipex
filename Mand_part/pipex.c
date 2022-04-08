/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asibille <asibille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:29:46 by asibille          #+#    #+#             */
/*   Updated: 2022/04/08 14:02:13 by asibille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	int		fid;
	int		ret;

	if (argc == 5)
	{
		if (pipe(pfd) == -1)
			ft_exit(NULL, NULL, NULL);
		fid = fork();
		if (fid == -1)
			ft_exit(NULL, NULL, NULL);
		else if (!fid)
			ft_exec1(argv, envp, pfd);
		wait(NULL);
		fid = fork();
		if (fid == -1)
			ft_exit(NULL, NULL, NULL);
		else if (!fid)
			ft_exec2(argv, envp, pfd);
		close(pfd[0]);
		close(pfd[1]);
		wait(&fid);
		ret = WEXITSTATUS(fid);
		return (ret);
	}
	exit(EXIT_SUCCESS);
}
