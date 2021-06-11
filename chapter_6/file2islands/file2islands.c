#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct island
{
    const char *name;
    const char *opens;
    const char *closes;
    struct island *next;
} island;

void display(island *start)
{
    island *i = start;
    for (;i != NULL;i = i->next)
    {
        printf("Name: %s open: %s-%s\n", i->name, i->opens, i->closes);
    }
}

void release(island *start)
{
    island *i = start;
    island *next = NULL;
    for(;i != NULL; i = next)
    {
        next = i->next;
        free((void *)(i->name));
        free(i);
    }
}

island *create(const char *island_name)
{
    island *i = (island *)malloc(sizeof(island));
    i->name = strdup(island_name);
    i->opens = "09:00";
    i->closes = "17:00";
    i->next = NULL;
    return i;
}

int main()
{
    island *start = NULL;
    island *i = NULL;
    island *next = NULL;
    char name[80];
    for (;fgets(name, 80, stdin) != NULL; i = next)
    {
        next = create(name);
        if (start == NULL)
            start = next;
        if (i != NULL)
            i->next = next;
    }
    display(start);
    release(start);
    return 0;
}
