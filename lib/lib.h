#ifndef LIB_H
# define LIB_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 512
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_isdigit(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* gnl */
int		ft_find_line(char *str);
int		ft_strlen_gnl(char *str);
char	*get_next_line(int fd);
char	*ft_add_str_buffer_size(char *str, int fd);
char	*str_join(char *str, char *buffer, int rd);
char	*str_trim(char *str);
char	*next_line(char *str);
void	ft_free_gnl(char **str);
void	ft_free_twice(char *one, char *sec);

#endif