#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct person {
        char *name;
        int *age;
    } my;

    char n[] = "Jemwel";

    /*allocate storage for the age integer */
    my.age = (int*) malloc(sizeof(int) * 1);
    if (my.age == NULL)
    {
        fprintf(stderr, "Allocation error\n");
        exit(1);
    }
    /* assign value; the asterisk is required, but the 
     * standard dot operator is used */

    *my.age = 22;

    /*because 'n' is an array and 'my.name' is a pointer,
     * you can just copy the base address
     * again, the dot operator is use */

    my.name = n;

    /* output result
     * 'my.name' is a character pointer and the asterisk isn't required
     * the asterisk is required for 'my.age' */

    printf("%s is %d years old\n", my.name, *my.age);


    struct person president;
    president.age = (int*) malloc(sizeof(int) * 1);
    president.name = "The man who must not be named";
    *president.age = 69;

    printf("%s is %d years old\n", president.name, *president.age);


    /*creating struck Person as Person type, meaning di na need mag "struct Person personObj" */

    typedef struct Person
    {
        char name[32];
        int age;
    } Person;

    Person pres = {"the man who cant be moved", 97};

    printf("%s is %d years old\n", pres.name, pres.age);

    Person* first;

    first = &pres;

    /* output structure referene*/
    printf("%s is %d years old\n", first->name, first->age);

    Person* second;
    /*allocate the structure's memory*/

    second = (Person*)malloc(sizeof(Person));
    if (second == NULL)
    {
        fprintf(stderr, "Unable to allocate storage\n");
        exit(1);
    }

    strcpy(second->name, "George Washington");
    printf("How old was %s? ", second->name);

    scanf("%d", &(second->age));

    printf("size of Person in bytes %lu\n", (unsigned long) sizeof(Person));
    int x = 123;
    int *y = &x;

    printf("size of xy in bytes is %lu\n", (unsigned long) sizeof(*y));

    return 0;
}
