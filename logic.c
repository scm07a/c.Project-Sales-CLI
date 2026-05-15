#include <stdio.h>
#define MONTHS 12 

char branchNo_str[100];
int branchNo,branchstart;

int exit_menu(){
    char choice;
    printf("Are You Sure You Want To Exit?(Y/n)");
    scanf(" %c",&choice);
    getchar();
    if (choice =='Y' || choice == 'y')
    return 1;
    return 0;
}

void inputSales(double sales[][MONTHS]){

    printf("How Many Of Your Branches Do You Want To Input Sales Of:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    sscanf(branchNo_str,"%d",&branchNo);

    if (branchNo<=0){ 
        printf("Invalid Input Try Again!");
        return;
    }
    printf("Enter Which Branch You Want To Start From:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    sscanf(branchNo_str,"%d",&branchstart);

    if (branchstart>branchNo) {
        printf("Invalid Choice Only %d Branches Allowed\n",branchNo);
        return;
    }

    for (int i=branchstart-1;i<branchNo;i++){  
        for (int j=0;j<MONTHS;j++){
            printf("Enter Sales For Branch No. %d , Month No. %d:",i+1,j+1);
            scanf("%lf",&sales[i][j]);
        }
    }
    getchar();
}

void printSales(double sales[][MONTHS]){
    if (!*sales) {
        printf("There Isn't Any Data Stored!");
        return;
    }
    
    printf("Enter Many Of Your Branches Do You Want To Print The Sales Of:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    sscanf(branchNo_str,"%d",&branchNo);

    if (branchNo<=0){ 
        printf("Invalid Input Try Again!");
        return;
    }

    printf("Enter Which Branch You Want To Start From:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    sscanf(branchNo_str,"%d",&branchstart);

    for(int i=branchstart-1;i<branchNo;i++){
        for (int j=0;j<MONTHS;j++){
            printf("Branch No. %d Month %d : %f\n",i+1,j+1,sales[i][j]);
        }
    }
}

double totalSales(double sales[][MONTHS],int branches){
    double sum=0;
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++){
            sum+=sales[i][j];
        }
    }
    return sum;
}



