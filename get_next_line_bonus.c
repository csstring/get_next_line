/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:57:29 by schoe             #+#    #+#             */
/*   Updated: 2022/04/06 19:48:40 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <unistd.h>

int	find_line(char *buff)
{
	int	i;

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

t_list	*fd_find(int fd, t_list **head)
{
	t_list	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (temp -> fd_index == fd)
			return (temp);
		temp = temp -> next;
	}
	return (NULL);
}

void	clear_buf(t_list *node, int i_lf, int len)
{
	char	*temp;

	if ((node -> buff)[i_lf + 1] != '\0')
		temp = ft_strdup((node -> buff) + (i_lf + 1), len - i_lf);
	else
		temp = NULL;
	free(node -> buff);
	node -> buff = temp;
}

char	*ft_get_line(int fd, t_list *node)
{
	char	buf[BUFFER_SIZE];
	int		len;

	if (find_line(node -> buff) != -1)
		clear_buf(node, find_line(node -> buff), ft_strlen(node -> buff));
	if (node -> i_eof == 0)
	{
		free(node -> buff);
		return (NULL);
	}
	while (find_line(node -> buff) == -1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0)
			node -> buff = ft_strjoin(node -> buff, buf, len);
		else
		{
			node -> i_eof = 0;
			return (node -> buff);
		}
	}
	return (node -> buff);
}

char	*get_next_line(int fd)
{
	static t_list	**head;
	char			*str;

	if (head == NULL)
	{
		head = (t_list **)malloc(sizeof(t_list *));
		if (head == NULL)
			return (NULL);
		*head = NULL;
	}
	if (!(fd_find(fd, head)))
		if (!(ft_new_node(fd, head)))
			return (NULL);
	str = ft_get_line(fd, fd_find(fd, head));
	if (str == NULL)
	{
		ft_node_clear(head, fd);
		if (*head == NULL)
			head = NULL;
		return (NULL);
	}
	else if (find_line(str) != -1)
		return (ft_strdup(str, find_line(str) + 1));
	else
		return (ft_strdup(str, ft_strlen(str)));
}
