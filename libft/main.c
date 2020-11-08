/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmeribal <lmeribal@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 10:52:08 by lmeribal          #+#    #+#             */
/*   Updated: 2020/10/31 13:26:14 by lmeribal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <stdio.h>
#include <string.h>

#include "src/ft_strlen.c"
#include "src/ft_isdigit.c"
#include "src/ft_isalpha.c"
#include "src/ft_toupper.c"
#include "src/ft_tolower.c"
#include "src/ft_isascii.c"
#include "src/ft_isalnum.c"
#include "src/ft_isprint.c"
#include "src/ft_memset.c"
#include "src/ft_memccpy.c"
#include "src/ft_strncmp.c"
#include "src/ft_strchr.c"
#include "src/ft_strrchr.c"
#include "src/ft_atoi.c"

void ft_putchar(char c)
{
    write(1, &c, 1);
}


void ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_putchar(str[i]);
        i++;
    }
}


int main()
{
    //int result = ft_strlen("razdva");

    //int result = ft_isdigit('0');

    //int result = ft_isalpha('d');
    
    //char result = ft_toupper('d');
    //printf("%c", result);

    //char result = ft_tolower('D');
    //printf("%c", result);

    //int result = ft_isascii('\xd1');

    //int result = ft_isalnum('&');
    
    //int result = ft_isprint('\n');

    //char array[15] = "1234567890";
    //ft_memset(array, '1', 10);
    
    
    //char array[15] = "123456789";
    //char dest[15] = "";
    //ft_memccpy(array, dest, '5', 10);
    
    //char *str1 = "раз два";
    //char *str2 = "раз Три";
    //int result = ft_strncmp(str1, str2, 4);
    
    //char *str = "hello world";
    //int symb = 'l';
    //int result = ft_strchr(str, symb);
    
    //char str1[25] = "hello";
    //char str2[25] = "world";
    //ft_strcat(str1, str2);

    //char *str = "looool";
    //int result = ft_strrchr(str, 'l');

}