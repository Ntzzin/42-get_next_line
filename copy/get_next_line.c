/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:37:04 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/13 12:04:15 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	handle_buffer_end(int fd, char *buffer, char **res, int *i)
{
	int		n;
	int		start;

	start = ft_getidx(buffer);
	*res = ft_memncat(*res, buffer, *i - start);
	if (!(*res))
		return (-1);
	n = read(fd, buffer, BUFFER_SIZE);
	if (n == -1)
	{
		free(*res);
		*res = NULL;
		return (-1);
	}
	*i = 0;
	return (n);
}

// static char	*ft_setres(void)
// {
// 	char	*res;

// 	res = malloc(1);
// 	if (!res)
// 		return (NULL);
// 	res[0] = '\0';
// 	return (res);
// }

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE];
// 	char		*res;
// 	int			i;
// 	int			n;

// 	n = 0;
// 	res = ft_setres();
// 	i = ft_getidx(buffer);
// 	if (i == BUFFER_SIZE)
// 	{
// 		n = read(fd, buffer, BUFFER_SIZE);
// 		i = ft_getidx(buffer);
// 	}
// 	else
// 		n = i + ft_strlen(&(buffer[i]));
// 	while (n > 0 && res)
// 	{
// 		if (i >= n)
// 			n = handle_buffer_end(fd, buffer, &res, &i);
// 		else if (buffer[i++] == '\n')
// 			return (ft_memncat(res, buffer, i - ft_getidx(buffer)));
// 	}
// 	if (n <= 0 && !ft_strlen(res))
// 		return (free(res), NULL);
// 	return (res);
// }
static int	init_buffer(int fd, char *buffer, int *i)
{
	int	n;

	*i = ft_getidx(buffer);
	if (*i == BUFFER_SIZE)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		*i = ft_getidx(buffer);
	}
	else
		n = *i + ft_strlen(&(buffer[*i]));
	return (n);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*res;
	int			i;
	int			n;

	n = 0;
	res = NULL;
	n = init_buffer(fd, buffer, &i);
	while (n > 0)
	{
		if (i >= n)
			n = handle_buffer_end(fd, buffer, &res, &i);
		else if (buffer[i++] == '\n')
			return (ft_memncat(res, buffer, i - ft_getidx(buffer)));
	}
	return (res);
}
