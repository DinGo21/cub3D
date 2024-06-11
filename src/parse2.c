/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:57:01 by disantam          #+#    #+#             */
/*   Updated: 2024/06/11 11:38:26 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	skip_empty_lines(t_map *map, char *line, int fd)
{
	int	i;

	while (line)
	{
		i = 0;
		while (line[i] == '\t' || line[i] == ' ')
			i++;
		if (line[i] != '\n' && line[i] != '\0')
			break ;	
		if (line[i] == '\0')
		{
			free(line);
			parsing_error(map, "unexpected EOF");
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	parse_map(t_map *map, char *line, int fd)
{
	char *tmp;

	skip_empty_lines(map, line, fd);
	while (line)
	{
		tmp = ft_join(tmp, line);
		if (!tmp)
			parsing_error(map, strerror(errno));
		line = get_next_line(fd);
	}
}
