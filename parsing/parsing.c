/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkerkeni <mkerkeni@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 09:47:07 by ykifadji          #+#    #+#             */
/*   Updated: 2024/04/18 11:43:37 by mkerkeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	file_name(char *file_name)
{
	char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (!dot)
		return (1);
	if (ft_strlen(dot) != 4)
		return (1);
	else
		if (dot[1] != 'x' || dot[2] != 'p' || dot[3] != 'm')
			return (1);
	return (0);
}

int	check_file_name(char *file_name)
{
	char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (!dot)
		return (1);
	if (ft_strlen(dot) != 4)
		return (1);
	else
		if (dot[1] != 'c' || dot[2] != 'u' || dot[3] != 'b')
			return (1);
	return (0);
}

void	check_pos(t_cube *cube, int c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		cube->bool++;
	if (cube->bool > 1)
		ft_handlerror(8);
	if (cube->bool == 1 && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		cube->pos = c;
}

int	size_of_file(t_cube *cube, char *av)
{
	char	*str;
	int		fd;

	cube->nb_line = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_handlerror(2);
	str = get_next_line(fd);
	while (str)
	{
		cube->nb_line++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (cube->nb_line + 1);
}

void	parsing(t_cube *cube, char *av)
{
	int	fd;
	int	i;

	cube->file = ft_calloc(sizeof(char *), size_of_file(cube, av));
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_handlerror(2);
	i = 0;
	cube->file[i] = get_next_line(fd);
	while (cube->file[i])
		cube->file[++i] = get_next_line(fd);
	close(fd);
	cpy_elem(cube);
}
