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
