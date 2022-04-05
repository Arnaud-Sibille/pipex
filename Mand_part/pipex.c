#include "pipex.h"

int main(int argc, char **argv, char **envp)
{
	int		pfd[2];
	int		fid;

	if (argc == 5)
	{
		if (pipe(pfd) == -1)
			ft_exit("pipe(pid)", NULL, NULL);
		fid = fork();
		if (fid == -1)
			ft_exit("fork()", NULL, NULL);
		else if (!fid)
			ft_exec1(argv, envp, pfd);
		wait(NULL);
		fid = fork();
		if (fid == -1)
			ft_exit("second fork()", NULL, NULL);
		else if (!fid)
			ft_exec2(argv, envp, pfd);
		close(pfd[0]);
		close(pfd[1]);
		wait(NULL);
	}
}