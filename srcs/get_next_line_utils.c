/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:45:54 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/10 12:46:38 by nado-nas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"


static size_t  ft_strlen(const char *s)
{
        size_t  i;
        //printf("|strlen for '%s'|\n", s);
        i = 0;
        while (s[i]){
            //printf("-char is '%c'\n", s[i]);
            i++;
        }
        return (i);
}

static char   *ft_strncpy(char *dst, char *sbuff, size_t dsize)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	
	/*printf("	\033[0;31m(function call) ft_strncpy(%s, ", (ft_strlen(dst)) ? dst : "(empty)");
    for(int j = 0; j < BUFFER_SIZE; j++)
		printf("%c%s", (sbuff[j] == '\0') ? '\0' : sbuff[j], (sbuff[j] == '\0') ? "\\0" : "");
	printf(", %d)\033[0m\n", (int)dsize);*/
	
	while (!sbuff[i])
		i++;
	//printf("		\033[0;33mcurrent char [%d]'%c'\033[0m\n", i, sbuff[i]);
    while (j < (int)dsize)
	{
		//printf("		\033[0;33mcopying '%c' into dst[%d]\033[0m\n", sbuff[j + i], j);
		dst[j] = sbuff[j + i];
        sbuff[j + i] = 0;
		j++;
	}
    return (dst);
}

char	*ft_memncat(char *s1, char *s2, int n)
{
    char    *cat;
    size_t  s1_len;
	
	// printf("\033[0;31m(function call) ft_memncat(%s, ", (ft_strlen(s1)) ? s1 : "(empty)");
    // for(int j = 0; j < BUFFER_SIZE; j++)
	// 	printf("%c%s", (s2[j] == '\n') ? '\0' : s2[j], (s2[j] == '\n') ? "\\n" : "");
	// printf(", %d)\033[0m\n", n);
	
    s1_len = ft_strlen(s1);
    //printf("--s1len = %d\n", (int)s1_len);
    //printf("--s2len = %d\n", n);
    cat = malloc(s1_len + n + 1);
    if (!cat)
	{
    	return (NULL);
	}
	//printf("	\033[0;32m succesfuly allocated %d byte%c\033[0m\n", (int)s1_len + n + 1, (((int)s1_len + n + 1) == 1) ? '\0' : 's');
    ft_strncpy(cat, s1, s1_len);
	
	// printf("	\033[0;33m first cat result: '");
	// for(int j = 0; j <= (int)ft_strlen(cat); j++)
	// 	printf("%c%s", (cat[j] == '\n') ? '\0' : cat[j], (cat[j] == '\0') ? "\\0" : ((cat[j] == '\n') ? "\\n" : ""));
	// printf("'\033[0m\n");
	
    ft_strncpy(cat + s1_len, s2, n);
	
	// printf("	\033[0;33m second cat result: '");
	// for(int j = 0; j <= (int)ft_strlen(cat); j++)
	// 	printf("%c%s", (cat[j] == '\n') ? '\0' : cat[j], (cat[j] == '\0') ? "\\0" : ((cat[j] == '\n') ? "\\n" : ""));
	// printf("'\033[0m\n");
	
    cat[s1_len + n] = '\0';
	
	printf("\033[0;36m(function return) '");
	for(int j = 0; j <= (int)ft_strlen(cat); j++)
		printf("%c%s", (cat[j] == '\n') ? '\0' : cat[j], (cat[j] == '\0') ? "\\0" : ((cat[j] == '\n') ? "\\n" : ""));
	printf("'\033[0m\n");
	
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

