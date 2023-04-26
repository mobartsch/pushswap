/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbartsch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:10:02 by mbartsch          #+#    #+#             */
/*   Updated: 2023/01/17 11:10:07 by mbartsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*read_from_file(int fd, char *rest)
{
	char	*gelesen;
	int		bytes;

	gelesen = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!gelesen)
		return (NULL);
	gelesen[0] = '\0';
	bytes = 1;
	while (is_nl(gelesen) && bytes > 0)
	{
		bytes = read(fd, gelesen, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(gelesen);
			free(rest);
			return (NULL);
		}
		if (bytes > 0)
		{
			gelesen[bytes] = '\0';
			rest = join_str(gelesen, rest);
		}
	}
	free(gelesen);
	return (rest);
}

char	*extract_nl(char *whole_line)
{
	size_t	z;
	char	*new_line;

	z = 0;
	if (!whole_line[z])
		return (NULL);
	while (whole_line[z] && whole_line[z] != '\n')
		z++;
	if (whole_line[z] == '\n')
		z++;
	new_line = (char *)malloc(sizeof(char) * (z + 1));
	ft_strlcpy(new_line, whole_line, z + 1);
	return (new_line);
}

char	*from_nl(char *rest)
{
	size_t	z;
	char	*new_rest;

	z = 0;
	while (rest[z] && rest[z] != '\n')
		z++;
	if (rest[z] == '\0')
	{
		free(rest);
		return (NULL);
	}
	new_rest = ft_strdup(&rest[z + 1]);
	free(rest);
	return (new_rest);
}

char	*get_next_line(int fd)
{
	char		*output;
	static char	*rest[1024];

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(rest[fd]);
		return (NULL);
	}
	rest[fd] = read_from_file(fd, rest[fd]);
	if (!rest[fd])
		return (NULL);
	output = extract_nl(rest[fd]);
	rest[fd] = from_nl(rest[fd]);
	return (output);
}
