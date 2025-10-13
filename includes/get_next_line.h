/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:37:15 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/08 18:04:30 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define RD -1 // byte has been read

char	*get_next_line(int fd);

/*───────────────────────────────────────────
				Helper functions
─────────────────────────────────────────────*/
char	*ft_memncat(char *s1, char *s2, int n);

int		ft_getidx(char *buff);

#endif