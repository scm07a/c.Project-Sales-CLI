#include <stdio.h>
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

void inputSales(double sales[][MONTHS],int branches){
    char branchNo_str[100];
    int branchNo,branchstart;  
    printf("How Many Of Your Branches Do You Want To Input Sales Of:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchNo)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }

    printf("Enter Which Branch You Want To Start From:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchstart)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }
    int end=branchstart+branchNo-1;
    
    if (branchNo<=0 || end>branches|| branchstart<=0){ 
            printf("Invalid Input Try Again!\n");
            return;
        }
    for (int i=branchstart-1;i<end;i++){  
        for (int j=0;j<MONTHS;j++){
            printf("Enter Sales For Branch No. %d , Month No. %d:",i+1,j+1);
            scanf("%lf",&sales[i][j]);
        }
    }
    getchar();
}

void printSales(double sales[][MONTHS],int branches){
    char branchNo_str[100];
    int branchNo,branchstart;

    printf("Enter How Many Of Your Branches Do You Want To Print The Sales Of:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchNo)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }


    printf("Enter Which Branch You Want To Start From:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchstart)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }

    int end=branchstart+branchNo-1;
        if (branchNo<=0||end>branches|| branchstart<=0){ 
        printf("Invalid Input Try Again!\n");
        return;
    }
    for(int i=branchstart-1;i<end;i++){
        for (int j=0;j<MONTHS;j++){
            printf("Branch No. %d Month %d : %.2f\n",i+1,j+1,sales[i][j]);
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

void percentageSales(double sales[][MONTHS], int branches){
    char branchNo_str[100];
    int branchNo,branchstart;
    double percent;

    printf("Enter How Many Of Your Branches Do You Want To Print The Sales Of:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchNo)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }

    printf("Enter Which Branch You Want To Start From:");
    fgets(branchNo_str,sizeof(branchNo_str),stdin);
    if(sscanf(branchNo_str,"%d",&branchstart)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }

    int end=branchstart+branchNo-1;
        if (branchNo<=0||end>branches|| branchstart<=0){ 
        printf("Invalid Input Try Again!\n");
        return;
    }
    double companyTotal=totalSales(sales,branches);
    for (int i=branchstart-1;i<end;i++){

        double branchTotal=0;//* Reset For Each Branch

        for (int j=0;j<MONTHS;j++){
            //* Calculate Branch Total Sales First In Inner Loop Alone
            branchTotal+=sales[i][j];
        }
        percent=(branchTotal/companyTotal)*100.0;
        printf("Percentage Of Branch No.%d: %.2f%\n",i+1,percent);
    }
}

int peakSales(double sales[][MONTHS],int branches){
    
    float max = -999999999;
    int peakMonth=0;
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++){
            double peak=sales[i][j];
            if (peak > max)
            {
                max = peak;
                peakMonth=j;
            }
        }

    }
    return peakMonth+1;
}

void BranchesByMonth(double sales[][MONTHS],int branches){
    char new_month[50];
    int int_month;
    printf("Choose The Month You Want To Sort Each Branch By:\n1.January 2.Feburary 3.March 4.April\n5.May     6.June     7.July     8.August\n9.September 10.October 11.November 12.December\n:");
    fgets(new_month,sizeof(new_month),stdin);
    if(sscanf(new_month,"%d",&int_month)!=1){
        printf("Invalid Input Try Again!\n");
        return;
    }
    if (int_month<1||int_month>MONTHS){
        printf("Invalid Input Try Again!\n");
        return;
    }
    for (int i=0;i<branches;i++){
        for(int j=0;j<branches-i-1;j++){
            if (sales[j][int_month-1]<sales[j+1][int_month-1]){
                double temp = sales[j][int_month-1];
                sales[j][int_month-1]=sales[j+1][int_month-1];
                sales[j+1][int_month-1]=temp;
            }
        }
    }
    printf("The Sorted Branches For Month %d Are:\n",int_month);
    for (int i=0;i<branches;i++)
    printf("Branch No.%d: %.2f\n",i+1,sales[i][int_month-1]);
}

void MonthsByBranch(double sales[][MONTHS],int branches){
    char choice_chr[50];
    int branch_choice;
    printf("Choose The Branch You Want To Sort Each Month(1-%d)",branches);
    fgets(choice_chr,sizeof(choice_chr),stdin);
    if (sscanf(choice_chr,"%d",&branch_choice)!=1){
        printf("Invalid Input Try Again\n");
        return;
    }
    if (branch_choice<1||branch_choice>branches){
        printf("Invalid Input Try Again\n");
        return;
    }
    for (int i=0;i<MONTHS;i++){
        for (int j=0;j<MONTHS-i-1;j++){
            if(sales[branch_choice-1][j]<sales[branch_choice-1][j+1]){
                double temp=sales[branch_choice-1][j];
                sales[branch_choice-1][j]=sales[branch_choice-1][j+1];
                sales[branch_choice-1][j+1]=temp;
            }
        }
    }
    printf("The Sorted Months Of Branch No.%d Are:\n",branch_choice);
    for (int i=0;i<MONTHS;i++)
    printf("Month No.%d: %.2f\n",i+1,sales[branch_choice-1][i]);
}

void savedata(double sales[][MONTHS],int branches){
    FILE *file=fopen("salesData.txt","w");

    if (file==NULL){
        printf("Error Opening File...\n");
        return;
    }

    fprintf(file,"%d\n",branches);
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++)
            fprintf(file,"%f ",sales[i][j]);

        fprintf(file,"\n");
    }
    fclose(file);
}
void loaddata(double sales[][MONTHS],int *branches){
    FILE*file=fopen("salesData.txt","r");
    if (file==NULL){
        printf("No Saved Data Found...\n");
        return;
    }
    fscanf(file,"%d",branches);
    for (int i=0;i<*branches;i++){
        for (int j=0;j<MONTHS;j++)
            fscanf(file,"%lf",&sales[i][j]);
    }
    fclose(file);
}

// void resetdata(double sales[][MONTHS],int branches)