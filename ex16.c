#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
    // make two people structures
    struct Person *joe = Person_create(
            "Joe Alex", 32, 64, 140);

    struct Person *frank = Person_create(
            "Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}

/* Psuedo-psuedo-code version!
 *
 * Include:
 *      • Your basic printf() function
 *      • Assert() to ensure malloc() works correctly
 *      • The standard C library for access to malloc()
 *      • Strdup() to duplicate a string
 *  
 * Create a new struct called Person with the following attributes:
 *      • A string (pointer of type char) called name
 *      • An integer called age
 *      • An integer called height
 *      • An integer called weight
 * 
 * Function!
 *      • Return type: pointer of type struct Person
 *      • Name: Person_create
 *      • Params: name, age, height, and weight
 *
 *      Create a Person struct named who and allocate it some memory to work with
 *      Assert that the memory was correctly allocated
 * 
 *      Assign who's name to a strdup (string duplicate) of the name passed in
 *      Assign who's age to the age passed in
 *      Do the same for height and weight
 * 
 *      Return who
 * 
 * Function!
 *      • Return type: void
 *      • Name: Person_destroy
 *      • Params: a pointer to a struct Person called who
 *
 *      Assert who points to valid memory
 * 
 *      Unallocate who's name
 *      Unallocate the rest of who
 * 
 * Function!
 *      • Return type: void
 *      • Name: Person_print
 *      • Params: a pointer to a struct Person called who
 *      
 *      Print "Name: (who's name)" followed by a newline
 *      Print "Name: (who's age)" followed by a newline
 *      Print "Name: (who's height)" followed by a newline
 *      Print "Name: (who's weight)" followed by a newline
 * 
 * Main function!
 *     Initialize two people structures with name, age, height, and weight
 *
 *      Print a message displaying the memory location of the first person
 *      Call Person_print() on the first person, printing his info
 * 
 *      Do the same for Joe
 * 
 *      Make everyone 20 years older and wiser and print them again
 *  
 *      Destroy both people with a Person_destroy() call for each
 * 
 *      Return 0 denoting successful execution if the program made it this far
 */

