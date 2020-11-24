#include "get_next_line.h"

#include <stdio.h>

int get_next_line(int fd, char **line)
{
	static char *last_string;
    char buf[10 + 1];
    size_t last_symbol;
	char *pointer_to_n;
	int flag;

	flag = 1;
	if (last_string)
		*line = ft_strdup(last_string);
	else
		*line = ft_strdup("");
    while (flag && (last_symbol = read(fd, buf, 10)))
    {
        buf[last_symbol] = '\0';
		if ((pointer_to_n = ft_strchr(buf, '\n')))
		{
			*pointer_to_n = '\0';
			flag = 0;
			pointer_to_n++;
			last_string = ft_strdup(pointer_to_n);
		}
        *line = ft_strjoin(*line, buf);
    }
    return (0);
}

int main()
{
    char *line;
    int fd;

    fd = open("file.txt", O_RDONLY);
    get_next_line(fd, &line);
    printf("%s\n\n", line);

	get_next_line(fd, &line);
	printf("%s\n\n", line);

	get_next_line(fd, &line);
	printf("%s\n\n", line);
}