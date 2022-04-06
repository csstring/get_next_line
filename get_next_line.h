/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:25:52 by schoe             #+#    #+#             */
/*   Updated: 2022/04/06 20:17:06 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

typedef struct s_list
{
	int				fd_index;
	int				i_eof;
	char			*buff;
	struct s_list	*next;
}	t_list;

int		find_line(char *buff);
t_list	*fd_find(int fd, t_list **head);
void	clear_buf(t_list *node, int i_lf, int len);
char	*ft_get_line(int fd, t_list *node);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, size_t s2_len);
int		ft_new_node(int fd, t_list **head);
char	*ft_strdup(char *s1, size_t size);

#endif
