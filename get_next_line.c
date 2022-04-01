/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:57:29 by schoe             #+#    #+#             */
/*   Updated: 2022/04/01 12:29:17 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <unistd.h>
#include <stdio.h>
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

void	clear_buf(t_lst *node, int i_LF, int len)
{
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (len - i_LF));
	temp = (node -> buff) + (i_LF + 1);
	free(node -> buff);
	node -> buff = temp;
}

char	*ft_get_line(int fd, t_lst *node)
{
	char	buf[BUFFER_SIZE + 1];
	size_t	len;

	if (find_LF(node -> buff) != -1)
		clear_buf(node, find_LF(node -> buff), ft_strlen(node -> buff));
	while (find_LF(node -> buff) == -1)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len > 0)
		{
			buf[len] = '\0';
			node -> buff = ft_strjoin(node -> buff, buf, len);
		}
		else
			return (NULL);
	}
	return (node -> buff);
}

char	*get_next_line(int fd)
{
	static 	t_lst	**head;

	head = (t_lst **)malloc(sizeof(t_lst *));
	*head = NULL;
	if (!(fd_find(fd, head)))
	{
		if (!(ft_new_node(fd, head)))
			return (NULL);
	}
	return (ft_get_line(fd, fd_find(fd, head)));
}

#include <fcntl.h>
int main(void)
{
	size_t	fd1;
	size_t	fd2;
	char	*str1;
	char	*str2;

	str1 = (char *)malloc(30);
	str2 = (char *)malloc(30);
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	while (1)
	{
		str1 = get_next_line(fd1);
		if (str1 == NULL)
			break;
		printf("%s", str1);
	}
	printf("%s", "\n");
	while (2)
	{
		str2 = get_next_line(fd2);
		if (str2 == NULL)
			break;
		printf("%s", str2);
	}
	close (fd1);
	close (fd2);
	return (0);
}
