#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *big, const char *little, size_t len);
void	ft_putstr_fd(char *s, int fd);
int		ft_strncmp(const char *str1, const char *str2, size_t n);

#endif