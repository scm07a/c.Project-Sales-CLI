#include <stdio.h>
//*100 As Max Branches
#define BRANCHES 100
#define MONTHS 12 


int exit_menu(){
    char choice;
    printf("Are You Sure You Want To Exit?(Y/n)");
    scanf(" %c",&choice);
    getchar();
    if (choice =='Y' || choice == 'y')
    return 1;
    return 0;
}

