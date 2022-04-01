/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 11:29:52 by schoe             #+#    #+#             */
/*   Updated: 2022/04/01 12:29:15 by schoe            ###   ########.fr       */
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

void	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return ;
	while (i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strjoin(char *s1, char *s2, size_t s2_len)
{
	char	*temp;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	temp = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (temp == NULL)
		return (NULL);
	ft_strlcpy(temp, s1, s1_len + 1);
	ft_strlcpy(temp + s1_len, s2, s2_len + 1);
	return (temp);
}

int	ft_new_node(int fd, t_lst **head)
{
	t_lst	*new;
	char	*str;

	new = (t_lst *)malloc(sizeof(t_lst));
	if (new == NULL)
		return (0);
	new -> fd_index = fd;
	new -> next = NULL;
	str = (char *)malloc(sizeof(char) * 1);
	str[0] = '\0';
	new -> buff = str;
	if (*head == NULL)
		*head = new;
	else
		//
	return (1);
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
