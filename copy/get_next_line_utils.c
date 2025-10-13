/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:45:54 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/11 15:46:15 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strncpy(char *dst, char *sbuff, size_t dsize)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!sbuff[i])
		i++;
	while (j < (int)dsize)
	{
		dst[j] = sbuff[j + i];
		sbuff[j + i] = 0;
		j++;
	}
	return (dst);
}

char	*ft_memncat(char *s1, char *s2, int n)
{
	char	*cat;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	cat = malloc(s1_len + n + 1);
	if (!cat)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	if (s1)
		ft_strncpy(cat, s1, s1_len);
	ft_strncpy(cat + s1_len, s2, n);
	cat[s1_len + n] = '\0';
	if (s1)
		free(s1);
	return (cat);
}

int	ft_getidx(char *buff)
{
	int	i;

	i = 0;
	while (!buff[i] && i < BUFFER_SIZE)
		i++;
	return (i);
}
