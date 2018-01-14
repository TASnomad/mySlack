#include    <libmy.h>
#include    <stdlib.h>

#define		LEN(x, arr) while(arr[++x]);

char        *my_implode(char **arr, char del)
{
	int		arr_cont;
	int		len;
	int		i;
	char	*res;

	i = len = arr_cont = 0;
	res = 0x0;
	LEN(arr_cont, arr);
	while (i++ < arr_cont)
		len += my_strlen(arr[i]);
	res = (char *) malloc((len + 1 + arr_cont + 1) * sizeof(char));
	if (!res)
		return (0x0);
	i = 0;
	while (i++ < arr_cont)
	{
		my_strncat(res, arr[i], my_strlen(arr[i]));
		my_strncat(res, &del, 1);
	}
	res[len + arr_cont - 1] = 0x0;
	return (res);
}