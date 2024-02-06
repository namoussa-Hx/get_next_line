/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <namoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 20:56:04 by namoussa          #+#    #+#             */
/*   Updated: 2023/12/08 16:28:28 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*temp[1024];
	char		*buffer;
	int			i;

	if (fd >= 1024)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0
		|| BUFFER_SIZE > 2147483647)
		return (free(temp[fd]), temp[fd] = NULL, NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(temp[fd]), temp[fd] = NULL, NULL);
	while (1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
			break ;
		buffer[i] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buffer);
		if (!temp[fd])
			return (free(buffer), NULL);
		if (check_line(temp[fd]))
			break ;
	}
	return (free(buffer), print_line(&temp[fd]));
}
