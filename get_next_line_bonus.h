#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>

typedef struct s_lst
{
	int				fd_index;
	int	i_EOF;
	char			*buff;
	struct s_lst	*next;
}	t_lst;

int		find_line(char *buff);
void	clear_buf(t_lst *node, int i_LF, int len);
int		ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2, size_t s2_len);
void	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_get_line(int fd, t_lst *node);
int		ft_new_node(int fd, t_lst **head);
t_lst	*fd_find(int fd, t_lst **head);
char	*get_next_line(int fd);
char	*ft_strdup(char *S1, int size);
#endif
