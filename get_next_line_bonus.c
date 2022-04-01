/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:57:29 by schoe             #+#    #+#             */
/*   Updated: 2022/04/01 21:41:06 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <unistd.h>
int	find_LF(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

t_lst	*fd_find(int fd, t_lst **head)
{
	t_lst	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (temp -> fd_index == fd)
			return (temp);
		temp = temp -> next;
	}
	return (temp);
}

void	clear_buf(t_lst *node, int i_LF, int len)
{
	char	*temp;

	temp = ft_strdup((node -> buff) + (i_LF + 1), len - i_LF);
	free(node -> buff);
	node -> buff = temp;
}

char	*ft_get_line(int fd, t_lst *node)
{
	char	buf[BUFFER_SIZE + 1];
	int		len;

	if (find_LF(node -> buff) != -1)
		clear_buf(node, find_LF(node -> buff), ft_strlen(node -> buff));
	while (find_LF(node -> buff) == -1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0)
			node -> buff = ft_strjoin(node -> buff, buf, len);
		else
			return (NULL);
	}
	return (node -> buff);
}

char	*get_next_line(int fd)
{
	static t_lst	**head;
	char			*str;

	if (head == NULL)
	{
		head = (t_lst **)malloc(sizeof(t_lst *));
		*head = NULL;
	}
	if (!(fd_find(fd, head)))
	{
		if (!(ft_new_node(fd, head)))
			return (NULL);
	}
	str = ft_get_line(fd, fd_find(fd, head));
	if (str == NULL)
		return (NULL);
	else if (find_LF(str) != -1)
		return (ft_strdup(str, find_LF(str) + 1));
	else
		return (str);
}
