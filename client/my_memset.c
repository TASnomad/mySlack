#include <libmy.h>

void *my_memset(void *s, int c, int n)
{
	char *dst;

	dst = 0x0;
	if (n)
	{
		dst = (char *) s;
		while (--n)
		{
			*dst++ = c;
		}
	}
	return ((void *) dst);
}
