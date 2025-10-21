/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:37:15 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/21 11:23:59 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*get_next_line(int fd);

/*───────────────────────────────────────────
				Helper functions
─────────────────────────────────────────────*/
size_t	ft_strlenx(const char *s);
char	*ft_memncat(char *s1, char *s2, int n);
int		ft_getidx(char *buff);

#endif