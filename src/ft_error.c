/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:03:54 by mbany             #+#    #+#             */
/*   Updated: 2024/10/22 20:04:02 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>  // Potrzebne do write
#include <stdlib.h>  // Potrzebne do exit

int ft_error(char *message)
{
    // Wypisanie komunikatu błędu na stderr
    write(2, message, strlen(message));  // stderr to deskryptor 2
    write(2, "\n", 1);                   // Nowa linia po komunikacie

    return (1);  // Zwrot kodu błędu (może być różny, np. 1 oznacza błąd)
}
