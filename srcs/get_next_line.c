/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nado-nas <nado-nas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:37:04 by nado-nas          #+#    #+#             */
/*   Updated: 2025/10/09 20:11:12 by nado-nas         ###   ########.fr       */
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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char	*res;
	int			i;
	int			n;

	n = 0;
	res = "\0";
	i = ft_getidx(buffer);
	
	/*printf("i is %d, buffer -> [", i);
	for(int j = 0; j < BUFFER_SIZE; j++)
		printf("'%c%s'", (buffer[j] == '\n') ? '\0' : buffer[j], (buffer[j] == '\n') ? "\\n" : "");
	printf("]\n");*/
	
	if (i == BUFFER_SIZE)
	{
		//printf("Trying to read something...\n");
		n = read(fd, buffer, BUFFER_SIZE); //tudo foi lindo ou analogamente nada foi computado do arquivo para o buffer
		/*printf("buffer -> '");
		for (int j = 0; j < BUFFER_SIZE; j++)
			printf("%c%s", (buffer[j] == '\n') ? '\0' : buffer[j], (buffer[j] == '\n') ? "\\n" : "");
		printf("'\n");*/
		i = ft_getidx(buffer);
	}else{
		n = i + ft_strlen(&(buffer[i]));
	}
	while (n > 0)
	{
		//printf("reading [%d]'%c%s'\n" , i, (buffer[i] == '\n') ? '\0' : buffer[i], (buffer[i] == '\n') ? "\\n" : "");
		if (i >= n)
		{
			//printf("Idx overflow: getidx -> %d, i -> %d\n", ft_getidx(buffer), i);
			res = ft_memncat(res, buffer, i - ft_getidx(buffer));
			n = read(fd, buffer, BUFFER_SIZE);
			i = 0;
			continue;
		}
		if (buffer[i] == '\n')
		{
			//printf("\n\\n encountered!\n");
			return (ft_memncat(res, buffer, (i + 1) - ft_getidx(buffer)));
		}
		i++;
		
	}
	//printf("returning because n is %d\n", n);
	if (n == -1)
		return (NULL);
	return (res);
}

#include <fcntl.h>

int main()
{
	int fd = open("lol", O_RDONLY);
	if (fd == -1)
	{
		printf("\nERROR TRYING TO OPEN FILE\n");
		return (1);	
	}
	printf("\033[0;32mFirst instance of get_next_line\033[0m\n");
	printf("%s", get_next_line(fd));
	printf("\033[0;32mSecond instance of get_next_line\033[0m\n");
	printf("%s", get_next_line(fd));
	printf("\033[0;32mThird instance of get_next_line\033[0m\n");
	printf("%s", get_next_line(fd));
	printf("|END|\n");
	return (0);
}