#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int i = 0;
    clock_t begin, end;
    double time_spent;
    // go through each string in argv
    // why am I skipping argv[0]?
    begin = clock();
    for(i = 1; i < argc; i++) {
        printf("arg %d: %s\n", i, argv[i]);
        if(i == argc - 1) {
            printf("All args printed; exiting loop.\n");
            break;
        }
    }

    // let's make our own array of strings
    char *states[] = {
        "California", "Oregon",
        "Washington", "Texas"
    };
    int num_states = 4;

    for(i = 0; i < num_states; i++) {
        printf("state %d: %s\n", i, states[i]);
        if(i == num_states - 1) {
            printf("All states printed; exiting loop.\n");
            break;
        }
    }
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%.10lf seconds", time_spent);

    return 0;
}
