/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpicron <jpicron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:06:07 by jpicron           #+#    #+#             */
/*   Updated: 2022/10/18 11:14:14 by jpicron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s)
{	
	char	*dup;
	int		i;

	i = ft_strlen(s);
	dup = malloc((i + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static	int	ft_join(const char *s1, char*s3, int j)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		s3[j] = s1[i];
		j++;
		i++;
	}
	return (j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	j = ft_join(s1, s3, j);
	j = ft_join(s2, s3, j);
	i = 0;
	s3[j] = '\0';
	return (s3);
}

int	ft_strncmp(const char *s1, const char	*s2, size_t n)
{
	unsigned int	a;
	unsigned char	*str1;
	unsigned char	*str2;

	a = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while ((str1[a] || str2[a]) && a < n)
	{
		if (str1[a] != str2[a])
		{
			return (str1[a] - str2[a]);
		}
		a++;
	}
	return (0);
}
