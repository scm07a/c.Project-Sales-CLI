#include <stdio.h>
#include <sys/types.h>
#include <windows.h>
#include "logic.h"
//Todo Remember to make exit method and make it return an int each time 
int main(){
    SetConsoleOutputCP(CP_UTF8);
    int branches,option;
    char choice[100];
    double sales[BRANCHES][MONTHS];//*BRANCHES is max number allowed

    printf("Enter The Number Of Branches:");
    scanf("%d",&branches);//* Used For Loop Through Input and Output Of Array "sales[][]"
    getchar();
    if (branches<=0|| branches>100){
        printf("Invalid Input Exiting Program...\n");
        return 0;
    }
    while (1){
        printf("\n  - - - - - - - - - - - - - - - - - - - - - - -RETAIL COMPANY DATABASE- - - - - - - - - - - - - - - - - - - - - - -\n");
        printf("  ❘      0.Exit                                                                           No. Of Branches:%d        ❘\n",branches);
        printf("  ❘              1.Input Sales Data.                            2.Show Sales Data.                                 ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘              3.Total Company Sales.                         4.Branch Percentages.                              ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘              5.Peak Sales Month.                            6.Sort Each Branch By Month Sales.                 ❘\n");
        printf("  ❘                                                                                                                ❘\n");
        printf("  ❘              7.Sort Each Month By Branch Sales.             8.Change No. Of Branches.                          ❘\n");
        printf("  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n");
        printf("  Enter Your Choice:");
        fgets(choice,sizeof(choice),stdin);
        sscanf(choice,"%d",&option);

        if (option == 0){
            if(exit_menu())
            break;
        continue;
        }

        else if (option == 1){
            continue;
        }

        else if (option == 2){
            continue;
        }

        else if (option == 3){
            continue;
        }
        
        else if (option == 4){
            continue;
        }
        
        else if (option == 5){
            continue;
        }
        
        else if (option == 6){
            continue;
        }
        
        else if (option == 7){
            continue;
        }

        else if (option == 8){
            printf("\nEnter The Number Of Branches:");
            scanf("%d",&branches);
            getchar();
            if (branches<=0){
                printf("Invalid Input Exiting Program...\n");
                return 0;
    }
        }
        
        else{
            printf("Invalid Choice Try Again!\n");
        }
    }
    return 0;
}