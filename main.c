int ft_strlen(const char *s);
char *ft_strcpy(char * dst, const char * src);
int ft_strcmp(const char *s1, const char *s2);
int ft_write(int fildes, const void *buf, int nbyte);
int ft_read(int fildes, void *buf, int nbyte);
char * ft_strdup(const char *s1);

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <assert.h>

int main(void)
{
    /*
     * FT_STRLEN
    */
    {
        assert(ft_strlen("123") == 3);
        assert(ft_strlen("") == 0);
        assert(ft_strlen("RGbnp3D87W76R24RU7dhQ3sxjMXZ4CJ2u3PDUuMBVSQN33mA2Bjcqprdxz8ZQ7g4587ALj66wa423qRy664sJb4aX8Lid4u8qRu9") == 100);
    }

    /*
     * FT_STRCPY
    */
    {
        char a[1] = "";
        char b[2] = "A";
        ft_strcpy(a, b);

        assert(strcmp(a, "A") == 0);
    }
    {
        char a[10] = "123456789";
        char b[10] = "ABCDEFGHI";
        ft_strcpy(a, b);

        assert(strcmp(a, "ABCDEFGHI") == 0);
    }
    {
        char a[100] = "123456789";
        char b[100] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        ft_strcpy(a, b);

        assert(strcmp(a, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") == 0);
    }

    /*
     * FT_STRCMP
    */
    {
        assert(ft_strcmp("A", "A") == 0);
        assert(ft_strcmp("A", "B") < 0);
        assert(ft_strcmp("B", "A") > 0);
        assert(ft_strcmp("Meu", "Meu") == 0);
        assert(ft_strcmp("Meu123456789ewjkrwjkfwe", "Meu123456789ewjkrwjkfwe") == 0);
        assert(ft_strcmp("Meu", "Med") > 0);
        assert(ft_strcmp("Meu", "Mew") < 0);
        assert(ft_strcmp("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnxpqrstuvwxyz") < 0);
    }

    /*
     * FT_WRITE
    */
    {
        int ret = ft_write(1, "Salut!\n", strlen("Salut!\n"));
        assert(ret >= 0);

        ret = ft_write(1, "", strlen(""));
        assert(ret >= 0);

        ret = ft_write(1, "A\n", strlen("A\n"));
        assert(ret >= 0);

        ret = ft_write(42, "A\n", strlen("A\n"));
        assert(ret == -1);
        printf("Wrong FD = %s\n", strerror(errno));

        ret = ft_write(0, "meu\n", strlen("meu\n"));
        printf("Write on stdin = %s\n", strerror(errno));

        FILE *file;
        file = fopen("debug_file", "w");

        int fd = fileno(file);

        ft_write(fd, "Salut\nSalut\nSalut\nSalut\nSalut\nSalut\n", strlen("Salut\nSalut\nSalut\nSalut\nSalut\nSalut\n"));

        fclose(file);
    }

    /*
     * FT_READ
    */
    {
        char buf[1024];
        buf[1024-1] = '\0';
        printf("\n\nreading stdin: \n");
        int ret = ft_read(0, buf, 1024);
        printf("%d %s\n", ret, buf);
    }
    {
        char buf[1024];
        buf[1024-1] = '\0';
        int ret = ft_read(42, buf, 1024);
        printf("Wrong FD = %s\n", strerror(errno));
        printf("%d %s\n", ret, buf);
        assert(ret < 0);
    }

    {

        char buf[1024];
        buf[1024-1] = '\0';

        FILE *file = NULL;
        file = fopen("debug_file", "r");
        if (file == NULL) {
            return -1;
        }

        int fd = fileno(file);

        int ret = ft_read(fd, buf, 1024);

        printf("\n\nREADING FILE = %d %s\n", ret, buf);

        fclose(file);
    }

    /*
     * FT_STRDUP
    */
    {
        char *dest = ft_strdup("Salut!");
        assert(strcmp(dest, "Salut!") == 0);
        free(dest);
    }

    {
        char *dest = ft_strdup("");
        assert(strcmp(dest, "") == 0);
        free(dest);
    }

    {
        char *dest = ft_strdup("");
        assert(strcmp(dest, "") == 0);
        free(dest);
    }

    {
        char *dest = ft_strdup("6XH22H4aCtXKBtauzCx3RR8b434n4q359xjyYQdGQi63b239H4eTv6XW9PkbBz2U62EeM78B3yNJnw9RzJLu6eb49ih46TwFJ4uG");
        assert(strcmp(dest, "6XH22H4aCtXKBtauzCx3RR8b434n4q359xjyYQdGQi63b239H4eTv6XW9PkbBz2U62EeM78B3yNJnw9RzJLu6eb49ih46TwFJ4uG") == 0);
        free(dest);
    }


    printf("\n\nIf this message is displayed then all is fine :)\n");    

    return 0;
}