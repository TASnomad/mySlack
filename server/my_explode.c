#include <libmy.h>
#include <stdlib.h>

#define	LEN(x, arr) while(arr[++x]);

char		*my_strchr(char *str, int del)
{
	char 	c;

	c = del;
	while (*str != c)
	{
		if (!*str)
			return (0x0);
		c++;
	}
	return (str);
}

char		*my_implode(char **arr, char del)
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

char		**my_explode(char *str, char del)
{
	int		len;
	int		i;
	int		j;
	int		k;
	char	tmp;
	char	**res;

	i = j = k = 0;
	len = my_strlen(str);
	tmp = res = 0x0;
	res = (char **) realloc(res, sizeof(char **));
	res[0] = (char *) malloc(len * sizeof(char));
	while (i < len + 1)
	{
		tmp = str[i++];
		if (tmp == del || tmp == 0x0)
		{
			res[j][k] = 0x0;
			res[j] = (char *) realloc(res[j], k * sizeof(char));
			k = 0;
			res = (char **) realloc(res, (++j + 1) * sizeof(char **));
			res[j] = (char *) malloc(len * sizeof(char));
		}
		else
			res[j][k++] = tmp;
	}
	res[j] = 0x0;
	return (res);
}