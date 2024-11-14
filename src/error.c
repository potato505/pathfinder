#include"../inc/header.h"


int file_error(int argc, char *argv[])
{
    (void)argv;
    if(argc != 2)
    {
        print_str_error("usage: ./pathfinder [filename]\n");
        return 1;
    }
    int file = open(argv[1], O_RDONLY);
    char k;
    int n = 0;
    if (file < 0) 
    {
        print_str_error("error: file ");
        print_str_error(argv[1]);
        print_str_error(" does not exist\n");
        return 1;
    }
    while (read(file, &k, 1) > 0) 
    {
        n++;
    }
    if(n == 0)
    {
        print_str_error("error: file ");
        print_str_error(argv[1]);
        print_str_error(" is empty\n");
        return 1;
    }
    close(file);
    return 0;
}

int error(char **path)
{
    for(int i = 0; path[0][i] != '\0'; i++)
    {
        if(path[0][i] < 48 || path[0][i] > 57 )
        {
            print_str_error( "error: line 1 is not valid\n");
            return 1;
        }
    }
    for(int i = 1; path[i] != NULL; i++)
    {
        int tire = 0;
        int coma = 0;
        for(int j = 0; path[i][j] != '\0'; j++)
        {
            if(coma > 0)
            {
                if(path[i][j] < 48 || path[i][j] > 57 )
                {
                    print_str_error("error: line ");
                    error_printint(i + 1);
                    print_str_error(" is not valid\n");
                    return 1;
                }
            }
            if(path[i][j] == '-')
            {
                if(tire > 0)
                {
                    print_str_error("error: line ");
                    error_printint(i + 1);
                    print_str_error(" is not valid\n");
                    return 1; 
                }
                tire = j;
            }
            if(path[i][j] == ',')
            {
                if(coma > 0)
                {
                    print_str_error("error: line ");
                    error_printint(i + 1);
                    print_str_error(" is not valid\n");
                    return 1; 
                }
                coma = j;
            }
        }
        if(tire == 0)
        {
            print_str_error("error: line ");
            error_printint(i + 1);
            print_str_error(" is not valid\n");
            return 1;
        }
        if(coma < tire || (coma  - tire == 1) || path[i][coma + 1] == '\0')
        {
            print_str_error("error: line ");
            error_printint(i + 1);
            print_str_error(" is not valid\n");
            return 1;
        }

    }
    return 0;
}

int error_info(t_edge *edge, char **list, int n, char *first_line)
{
    int f = get_int(first_line);
    int N = 0;
    while(list[N] != NULL)
    {
        N++;
    }
    if(N != f)
    {
        print_str_error("error: invalid number of islands\n");
        return 1;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(rovno(edge[i], edge[j]))
            {
                print_str_error("error: duplicate bridges\n");
                return 1;
            }
        }
    }
    long sum = 0;
    int max = 2147483647;
    for(int i = 0; i < n; i++)
    {
        sum += edge[i].data;
        if(sum > max)
        {
            print_str_error("error: sum of bridges lengths is too big\n");
            return 1;
        }
    }
    return 0;
}

