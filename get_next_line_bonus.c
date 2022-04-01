/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:57:29 by schoe             #+#    #+#             */
/*   Updated: 2022/04/01 17:56:35 by schoe            ###   ########.fr       */
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
		{
			buf[len] = '\0';
			node -> buff = ft_strjoin(node -> buff, buf, len);
		}
		else
			return (NULL);
	}
	return (node -> buff);
}

int	ft_lstsize(t_lst **head)
{
	int		i;
	t_lst	*temp;

	temp = *head;
	i = 0;
	while (temp)
	{
		temp = temp -> next;
		i++;
	}
	return (i);
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
	{
		printf("list conunt : %d\n", ft_lstsize(head));
		return (NULL);
	}
	else if (find_LF(str) != -1)
		return (ft_strdup(str, find_LF(str) + 1));
	else
		return (str);
}

#include <fcntl.h>
int main(void)
{
	size_t	fd1, fd2, fd3, fd4, fd5, fd6, fd7;
	char	*str;

	str = (char *)malloc(30);
	//str2 = (char *)malloc(30);
	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	fd4 = open("test4.txt", O_RDONLY);
	fd5 = open("test5.txt", O_RDONLY);
	fd6 = open("test6.txt", O_RDONLY);
	fd7 = open("test7.txt", O_RDONLY);

	while (1)
	{
		str = get_next_line(fd1);
		if (str == NULL)
			break ;
		free(str);
		printf("%s", str);
	}
	while (2)
	{
		str = get_next_line(fd2);
		if (str == NULL)
			break;
		free(str);
		printf("%s", str);
	}
	while (1)
	{
		str = get_next_line(fd3);
		if (str == NULL)
			break ;
		free(str);
		printf("%s", str);
	}
while (1)
	{
		str = get_next_line(fd4);
		if (str == NULL)
			break ;
		free(str);
		printf("%s", str);
	}
while (1)
	{
		str = get_next_line(fd5);
		if (str == NULL)
			break ;
		free(str);
		printf("%s", str);
	}
while (1)
	{
		str = get_next_line(fd6);
		if (str == NULL)
			break ;
		free(str);
		printf("%s", str);
	}
while (1)
	{
		str = get_next_line(fd7);
		if (str == NULL)
			break ;
		free(str);
		printf("%s", str);
	}
	close (fd1);
	close (fd2);
	close (fd3);
	close (fd4);
	close (fd5);
	close (fd6);
	close (fd7);
	return (0);
}
