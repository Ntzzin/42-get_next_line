/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:37:15 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/21 11:23:55 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define MAX_FDS 10000

char	*get_next_line(int fd);

/*───────────────────────────────────────────
				Helper functions
─────────────────────────────────────────────*/
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlenx(const char *s);
char	*ft_memncat(char *s1, char *s2, int n);
int		ft_getidx(char *buff);

#endif