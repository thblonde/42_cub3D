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
char	*get_next_line(int fd);
char	*read_the_file(int fd, char *the_static_char);
char	*join_the_buf_to_new_string(char *the_static_char, char *buf);
char	*recuparation_of_the_line(char *the_static_char);
char	*recuparation_of_the_rest_of_the_line(char *the_static_char);
int		gnl_strlen(char *str);
int		question_is_it_the_new_line(char *buf, int c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	ft_free_for_gnl(char **str);

#endif