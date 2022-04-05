#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

//exec
void	ft_exec1(char **argv, char **env, int *pfd);
void	ft_exec2(char **argv, char **env, int *pfd);

//cmd_to_path
char	*ft_cmd_to_path(char **cmd, char **env);

//exit
void	ft_exit(char *parg, char *s, char **arr);

//utils
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif