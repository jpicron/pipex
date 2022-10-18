/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:08:58 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/18 11:14:23 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <string.h>
# include <stdio.h>

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		tube[2];
	int		infile;
	int		outfile;
	char	*paths;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
}t_pipex;

char	*ft_strjoin(char const *s1, char const *s2);
char	*find_path(char **envp);
void	second_child(t_pipex pipex, char *argv[], char *envp[]);
void	first_child(t_pipex pipex, char *argv[], char *envp[]);
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);
void	close_pipes(t_pipex *pipex);
void	msg_error(char *err);
int		msg(char *err);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char	*s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s);

#endif
