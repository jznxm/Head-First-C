#include <stdio.h>
#include <unistd.h>

int main()
{
    char *my_env[] = {(char *)"JUICE=peach and apple", NULL};
    execle("diner_info.out", "diner_info.out", "4", NULL, my_env);
    puts("Hey, there must be somthing wrong.");
}
