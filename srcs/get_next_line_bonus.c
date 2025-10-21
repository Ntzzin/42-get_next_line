/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:37:04 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/21 11:23:20 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line_bonus.h>

/**
 * @file get_next_line_bonus.c
 * @brief All the functions have the same core functionalities, the only
 * change is that this version can handle multiple files descriptors at the
 * same time without any data loss with the dinamic use of a buffer for each 
 * open fd along with additional verifications to ensure no memory leaks or
 * unexpected crash.
 */

static int	ft_flush(int fd, char **buffer, char **res, int i)
{
	int	n;
	int	start;

	start = ft_getidx(buffer[fd]);
	*res = ft_memncat(*res, buffer[fd], i - start);
	if (!(*res))
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (-1);
	}
	n = read(fd, buffer[fd], BUFFER_SIZE);
	if (n == -1)
	{
		free(*res);
		free(buffer[fd]);
		*res = NULL;
		buffer[fd] = NULL;
		return (-1);
	}
	return (n);
}

static int	ft_init(int fd, char **buffer, int *i)
{
	int	n;

	if (!(fd >= 0 && fd < MAX_FDS))
		return (-1);
	if (!(buffer[fd]))
		buffer[fd] = calloc(BUFFER_SIZE + 1, 1);
	if (!(buffer[fd]))
		return (-1);
	*i = ft_getidx(buffer[fd]);
	if (*i == BUFFER_SIZE)
	{
		n = read(fd, buffer[fd], BUFFER_SIZE);
		*i = ft_getidx(buffer[fd]);
	}
	else
		n = *i + ft_strlenx(&(buffer[fd][*i]));
	return (n);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FDS];
	char		*res;
	int			i;
	int			n;

	n = 0;
	res = NULL;
	n = ft_init(fd, buffer, &i);
	while (n > 0)
	{
		if (i >= n)
		{
			n = ft_flush(fd, buffer, &res, i);
			i = 0;
		}
		else if (buffer[fd][i++] == '\n')
			return (ft_memncat(res, buffer[fd], i - ft_getidx(buffer[fd])));
	}
	if (!n)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (res);
}
