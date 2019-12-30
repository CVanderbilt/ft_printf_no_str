
#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, char c)
{
	char *ret;
	if (!s1 || !s2)
		return (0);
	ret = ft_strjoin(s1, s2);
	if (!ret)
		return (0);
	if (c == 'L' || c == 'B')
		free (s1);
	if (c == 'R' || c == 'B')
		free (s2);
	return (ret);
}
