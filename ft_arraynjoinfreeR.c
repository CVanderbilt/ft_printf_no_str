#include "libft.h"

void	*ft_arraynjoinfreeR(void *s1, void *s2, int n1, int n2)
{
	char	*ret;

	ret = ft_arraynjoin(s1, s2, n1, n2);
	if (!ret)
		return (0);
	free (s2);
	return (ret);
}
