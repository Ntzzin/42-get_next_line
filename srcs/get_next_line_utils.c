/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:45:54 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/21 11:37:37 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

/**
 * @brief Same core functionality as strlen(3) but with catch,
 * it returns 0 if the pointer to the string is NULL.
 */
size_t	ft_strlenx(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * @brief Same core functionality as strncpy(3) but with an adaptation to how
 * some cases are interpreted in this project: it skips all the NULL
 * characters and only starts to copy when it encounters any other one.
 * @warning This function is very dangerous due to the lack of any safety
 * verifications incurring in a high risk of reading invalid memory, for
 * this reason it is only used when the implementation itself ensure
 * that it will not happen.
 */
static char	*ft_strncpyx(char *dst, char *sbuff, size_t dsize)
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

/**
 * @brief Gets the index of the first non-null character present in the
 * `buffer`.
 * @param buff The buffer.
 * @return The index of the first non-null character, or, analogously,
 * the buffer size if none is found.
 */
int	ft_getidx(char *buff)
{
	int	i;

	i = 0;
	while (!buff[i] && i < BUFFER_SIZE)
		i++;
	return (i);
}

/**
 * @brief Concatenates `n` characters of an string into another one.
 * @param s1 The first string.
 * @param s2 The second string where n characters will be taken into
 * account.
 * @param n The number of bytes.
 * @return The index of the first non-null character, or, analogously,
 * the buffer size if none is found.
 */
char	*ft_memncat(char *s1, char *s2, int n)
{
	char	*cat;
	size_t	s1_len;

	s1_len = ft_strlenx(s1);
	cat = malloc(s1_len + n + 1);
	if (!cat)
	{
		if (s1)
			free(s1);
		return (NULL);
	}
	if (s1)
		ft_strncpyx(cat, s1, s1_len);
	ft_strncpyx(cat + s1_len, s2, n);
	cat[s1_len + n] = '\0';
	if (s1)
		free(s1);
	return (cat);
}
