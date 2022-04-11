/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:29:52 by schoe             #+#    #+#             */
/*   Updated: 2022/04/11 16:40:08 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <stdlib.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_node_clear(t_list **head, int fd)
{
	t_list	*temp;
	t_list	*first_node;

	if ((*head)->fd_index == fd)
	{
		temp = *head;
		*head = (*head)-> next;
		free(temp);
	}
	else
	{
		first_node = *head;
		temp = ft_fd_find(fd, *head);
		while ((*head)-> next -> fd_index != fd)
			*head = (*head)-> next;
		(*head)->next = (*head)->next -> next;
		free(temp);
		*head = first_node;
	}
}

char	*ft_strjoin(char *s1, char *s2, size_t s2_len)
{
	char	*temp;
	size_t	s1_len;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s1 == NULL)
		return (ft_strndup(s2, s2_len));
	s1_len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (temp == NULL)
		return (NULL);
	while (i < s1_len)
		temp[i++] = s1[k++];
	k = 0;
	while (i < s1_len + s2_len)
		temp[i++] = s2[k++];
	temp[i] = '\0';
	free(s1);
	return (temp);
}

int	ft_new_node(int fd, t_list **head)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new -> fd_index = fd;
	new -> next = NULL;
	new -> buff = NULL;
	new -> i_eof = 1;
	new -> next = *head;
	*head = new;
	return (1);
}

char	*ft_strndup(char *s1, size_t n)
{
	size_t	i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (n + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
