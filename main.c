#include <stdio.h>
#include "logic.h" //*Custom Header File Containing All Function Declarations

int main(){
    int branches=0,option;
    double sales[MAXBRANCHES][MONTHS]={0};//* Initialize All Values To Zero
    loaddata(sales,&branches);//* Loads The Saved Data And Overrides the Zero
    checkNoBranch(&branches);//* If 0 Or Lower Branches Prompts User To Enter No. Between 1-100 For Branches

    while (1){//* Main Menu Of The Program
        printf("\n  = = = = = = = = = = = = = = = = = = = = = Sales Management Database = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("  |     0.Exit                                                                             No. Of Branches:%d      |\n",branches);
        printf("  |              1.Input Sales Data.                                2.Show Sales Data.                            |\n");
        printf("  |                                                                                                               |\n");
        printf("  |              3.Total Company Sales.                             4.Branch Percentages.                         |\n");
        printf("  |                                                                                                               |\n");
        printf("  |              5.Peak Sales Month.                                6.Sort Each Branches By Month Sales.          |\n");
        printf("  |                                                                                                               |\n");
        printf("  |              7.Sort Each Months By Branch Sales.                8.Change No. Of Branches.                     |\n");
        printf("  |                                                                                                               |\n");
        printf("  |              9.Save Data.                                       10.Reset Data.                                |\n");
        printf("  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
        printf("  Enter Your Choice:");
        //*Input Validation
        if(scanf("%d",&option)!=1){
            printf("Invalid Input Try Again\n");
            clear_buffer();
            continue;
        }
        clear_buffer();

        //* Exit
        if (option == 0){
            char choice;
            printf("Are You Sure You Want To Exit?(Y/n)");
            scanf(" %c",&choice);
            clear_buffer();
            if (choice == 'Y' || choice == 'y'){
                savedata(sales,branches);
                break;
            }
            else if (choice == 'N' || choice == 'n')
                continue;
            else 
                printf("Invalid Input...\n");
        }

        //* Input Data
        else if (option == 1){
            inputSales(sales,branches);
            savedata(sales,branches);
        }

        //* Print Data
        else if (option == 2)
            printSales(sales,branches);

        //* Print Total Company Sales
        else if (option == 3)
            printf("Total Company Sales: $%.2f\n",totalSales(sales,branches));

        //* Print Percentage Sales For Any Branch
        else if (option == 4)
            percentageSales(sales,branches);

        //* Month With Peak Sales
        else if (option == 5)
            printf("Month No.%d Has The Peak Sales.\n",peakSales(sales,branches));

        //*Filter Branch Sales By A Chosen Month
        else if (option == 6)
            BranchesByMonth(sales,branches);

        //* Filter Months Sales By A Chosen Branch
        else if (option == 7)
            MonthsByBranch(sales,branches);

        //* Change Number Of Branches
        else if (option == 8){
            inputbranch(&branches);
            savedata(sales,branches);
        }

        //* Save Changed Data
        else if (option == 9)
            savedata(sales,branches);

        //* Reset Everything
        else if (option == 10){
            resetdata(sales,&branches);
            checkNoBranch(&branches);//*Activates To Prompt User To Enter No. Of Branches After Resetting It To Zero
        }
        else printf("Invalid Choice Try Again!\n");
    }
    return 0;
}