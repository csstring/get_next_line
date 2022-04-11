/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:57:29 by schoe             #+#    #+#             */
/*   Updated: 2022/04/11 16:37:51 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdlib.h>

ssize_t	ft_find_line(char *buff)
{
	ssize_t	i;

	i = 0;
	if (buff == NULL)
		return (-1);
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

void	ft_clear_buf(t_list *node, size_t i_lf, size_t len)
{
	char	*temp;

	if ((node -> buff)[i_lf + 1] != '\0')
		temp = ft_strndup((node -> buff) + (i_lf + 1), len - i_lf);
	else
		temp = NULL;
	free(node -> buff);
	node -> buff = temp;
}

char	*ft_get_line(int fd, t_list *node)
{
	char	buf[BUFFER_SIZE];
	ssize_t	len;

	if (node -> i_eof == 0)
	{
		free(node -> buff);
		return (NULL);
	}
	if (ft_find_line(node -> buff) != -1)
		ft_clear_buf(node, ft_find_line(node -> buff), ft_strlen(node -> buff));
	while (ft_find_line(node -> buff) == -1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0)
			node -> buff = ft_strjoin(node -> buff, buf, len);
		if (len < BUFFER_SIZE && ft_find_line(node -> buff) == -1)
		{
			node -> i_eof = 0;
			return (node -> buff);
		}
	}
	return (node -> buff);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*str;

	if (list == NULL)
	{
		list = (t_list *)malloc(sizeof(t_list));
		if (list == NULL)
			return (NULL);
		list -> buff = NULL;
		list -> i_eof = 1;
	}
	str = ft_get_line(fd, list);
	if (str == NULL)
	{
		free(list);
		list = NULL;
		return (NULL);
	}
	else if (ft_find_line(str) != -1)
		return (ft_strndup(str, ft_find_line(str) + 1));
	else
		return (ft_strndup(str, ft_strlen(str)));
}
