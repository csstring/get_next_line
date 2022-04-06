/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:29:52 by schoe             #+#    #+#             */
/*   Updated: 2022/04/06 17:58:23 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_node_clear(t_lst **head, int fd)
{
	t_lst	*temp;
	t_lst	*first_node;

	if ((*head)->fd_index == fd)
	{
		temp = *head;
		*head = (*head)-> next;
		free(temp);
	}
	else
	{
		first_node = *head;
		temp = fd_find(fd, head);
		while ((*head)-> next -> fd_index != fd)
			*head = (*head)-> next;
		(*head)->next = (*head)->next -> next;
		free(temp);
		*head = first_node;
	}
	if (*head == NULL)
		free(head);
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
		return (ft_strdup(s2, s2_len));
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

int	ft_new_node(int fd, t_lst **head)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (0);
	new -> fd_index = fd;
	new -> next = NULL;
	new -> buff = NULL;
	new -> i_EOF = 1;
	if (*head == NULL)
		*head = new;
	else
	{
		new -> next = *head;
		*head = new;
	}
	return (1);
}

char	*ft_strdup(char *s1, int size)
{
	int		i;
	char	*s2;

	i = 0;
	s2 = (char *)malloc(sizeof(char) * (size + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
