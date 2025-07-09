
#include "types.h"
#include "stat.h"
#include "user.h"

int 
main(int argc, char *argv[]) {
    if (argc == 1){
        int return_value = readcount(0); //get readcount without resetting
        if (return_value < 0) {
            printf(2, "Error: Unable to retrieve read count.\n"); //print error message to stderr
            exit();
        }
        printf(1, "Read count: %d\n", return_value); //print readcount to stdout
        exit();
    }

    else if (argc == 2 && strcmp(argv[1], "reset") == 0) {
        int return_value = readcount(1);
        if (return_value < 0) {
            printf(2, "Error: Unable to reset read count.\n"); //print error message to stderr
            exit();
        }
        printf(1, "readcount reset from %d to 0.\n", return_value); //reset readcount and print to stdout
        exit();
    }
    else {
        printf(2, "Usage: 'readcount' or 'readcount reset'\n"); //print error message to stderr
        exit();
    }
}