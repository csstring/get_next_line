/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schoe <schoe@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 13:25:52 by schoe             #+#    #+#             */
/*   Updated: 2022/04/11 16:38:10 by schoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>

typedef struct s_list
{
	int		i_eof;
	char	*buff;
}	t_list;

ssize_t	ft_find_line(char *buff);
void	ft_clear_buf(t_list *node, size_t i_lf, size_t len);
char	*ft_get_line(int fd, t_list *node);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, size_t s2_len);
char	*ft_strndup(char *s1, size_t n);

#endif
