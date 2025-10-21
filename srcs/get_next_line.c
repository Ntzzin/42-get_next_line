/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:37:04 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/21 11:23:49 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

/**
 * @brief Flushes and repopulates the `buffer` while concatenating the
 * remaining data (if any) to the any previous one with ft_memncat().
 * @param fd The file descriptor.
 * @param buffer The read() buffer.
 * @param res The address to the variable containing all the
 * previously adquire data are stored.
 * @param i the index of the last characted computed.
 * @return The number of characters populated in the buffer.
 */
static int	ft_flush(int fd, char *buffer, char **res, int i)
{
	int	n;
	int	start;

	start = ft_getidx(buffer);
	*res = ft_memncat(*res, buffer, i - start);
	if (!(*res))
		return (-1);
	n = read(fd, buffer, BUFFER_SIZE);
	if (n == -1)
	{
		free(*res);
		*res = NULL;
		return (-1);
	}
	return (n);
}

/**
 * @brief Executes a verifying/setting procedure to ensure that there is
 * no data loss, that means only reading from the file when all data
 * present in the buffer was consumed.
 * @param fd The file descriptor.
 * @param buffer The read() buffer.
 * @param i The address to the variable that holds the index of the last
 * characted computed.
 * @return The number of characters populated in the buffer.
 */
static int	ft_init(int fd, char *buffer, int *i)
{
	int	n;

	*i = ft_getidx(buffer);
	if (*i == BUFFER_SIZE)
	{
		n = read(fd, buffer, BUFFER_SIZE);
		*i = ft_getidx(buffer);
	}
	else
		n = *i + ft_strlenx(&(buffer[*i]));
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
	n = ft_init(fd, buffer, &i);
	while (n > 0)
	{
		if (i >= n)
		{
			n = ft_flush(fd, buffer, &res, i);
			i = 0;
		}
		else if (buffer[i++] == '\n')
			return (ft_memncat(res, buffer, i - ft_getidx(buffer)));
	}
	return (res);
}
