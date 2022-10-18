/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:11:06 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/18 11:11:55 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_char(char c, char set)
{
	if (c == '\0')
		return (1);
	if (c == set)
		return (1);
	return (0);
}

static int	count(char *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (check_char(str[i + 1], c) == 1
			&& check_char(str[i], c) == 0)
			cnt++;
		i++;
	}
	return (cnt);
}

static void	add_split(char *split, char *incrstr, char c)
{
	int	i;

	i = 0;
	while (check_char(incrstr[i], c) == 0)
	{
		split[i] = incrstr[i];
		i++;
	}
	split[i] = '\0';
}

static void	*split_fill(char **split, char *str, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		if (check_char(str[i], c) == 1)
			i++;
		else
		{
			j = 0;
			while (check_char(str[i + j], c) == 0)
				j++;
			split[k] = (char *) malloc (sizeof(char) * (j + 1));
			if (!split[k])
				return (NULL);
			add_split(split[k], str + i, c);
			k++;
			i = i + j;
		}
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		num;
	int		i;

	if (s == NULL)
		return (NULL);
	num = count((char *)s, c);
	split = (char **) malloc (sizeof(char *) * (num + 1));
	if (!split)
		return (NULL);
	if (!(split_fill(split, (char *)s, c)))
	{
		i = -1;
		while (split[++i])
			free(split[i]);
		free(split);
		return (NULL);
	}
	split[num] = 0;
	return (split);
}