/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbany <mbany@student.42warsaw.pl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:36:03 by mbany             #+#    #+#             */
/*   Updated: 2024/10/22 19:36:15 by mbany            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char **load_map(const char *file)
{
    int fd;
    char **map;
    char *line;
    int i;

    map = malloc(sizeof(char *) * 100); // Zakładamy maksymalnie 100 wierszy
    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        printf("Error: could not open map file.\n");
        exit(EXIT_FAILURE);
    }
    
    i = 0;
    while (get_next_line(fd, &line) > 0)
    {
        map[i] = line;
        i++;
    }
    map[i] = NULL;
    close(fd);
    return map;
}
