#include <stdio.h>
#define MONTHS 12 
#define MAXBRANCHES 100

void clear_buffer(){//* Function That Deletes Invalid Characters 
                    //*And Deletes Trailing Newlines '\n'
    int c;
    while ((c=getchar())!='\n' && c!=EOF);
}

int checkBranchInp(int* branchCount){
    //*Checks If scanf() function worked by either returning 1
    //*Or failed by returning 0
    
    if (scanf("%d",branchCount)!=1){
        clear_buffer();//? Removes The Invalid Character
        return 0;
    }
    clear_buffer();//? Removes newlines inside input buffer
    return 1;
}

int branchRange(int *branchStart,int* end,int branchCount){
    if(scanf("%d",branchStart)!=1){
        clear_buffer();
        return 0;
    }
    clear_buffer();
    //* Finds The End Depending On User Input Of Branch Start 
    //* and How Many Branches To Process
    *end=*branchStart+branchCount-1;
    return 1;
}

int rangeValid(int branchStart,int branchCount,int end, int branches){
    if (branchCount<=0 || end>branches|| branchStart<=0){ 
        return 0;
        }
    return 1;
}
//*Uses Previous Functions To Validate Input
int checkInput(int* branchStart,int* branchCount,int* end,int branches){
    printf("Enter Number Of Branches To Process (1-%d):",branches);
    if(!checkBranchInp(branchCount)){
        printf("Invalid Input Try Again\n");
        return 0;
    }
    printf("Enter Which Branch To Start From:");
    if(!branchRange(branchStart,end,*branchCount)){
        printf("Invalid Input Try Again\n");
        return 0;
    }
    if(!rangeValid(*branchStart,*branchCount,*end,branches)){
        printf("Invalid Input Try Again\n");
        return 0;
    }
    return 1;
}


void inputSales(double sales[][MONTHS],int branches){
    int branchCount,branchStart,end;
    //* Checks All User Input In The Following Function
    if(!checkInput(&branchStart,&branchCount,&end,branches)) return;

    for (int i=branchStart-1;i<end;i++){  
        for (int j=0;j<MONTHS;j++){
            printf("Enter Sales For Branch No. %d , Month No. %d:",i+1,j+1);
            //* Placed scanf() in a while loop to check if user entered
            //* a character or number and keeps looping through the same index 
            //* until user enters correct input
            while(scanf("%lf",&sales[i][j])!=1){
                printf("Invalid Input Try Again\n");
                clear_buffer();
            }
            clear_buffer();
        }
    }
}

void printSales(double sales[][MONTHS],int branches){
    int branchCount,branchStart,end;
    if(!checkInput(&branchStart,&branchCount,&end,branches)){
        return;
    }
    for(int i=branchStart-1;i<end;i++){
        for (int j=0;j<MONTHS;j++){
            printf("Branch No. %d Month %d : %.2f\n",i+1,j+1,sales[i][j]);
        }
    }
}
//* Returns Total Company Sales Including All Branches & All Months
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
    int branchCount,branchStart,end;
    double percent;
    if(!checkInput(&branchStart,&branchCount,&end,branches)){
        return;
    }
    //! Needed to Calculate Percentage
    double companyTotal=totalSales(sales,branches);
    for (int i=branchStart-1;i<end;i++){

        double branchTotal=0;//* Reset For Each Branch

        for (int j=0;j<MONTHS;j++){
            //* Calculate Branch Total Sales First In Inner Loop Alone
            branchTotal+=sales[i][j];
        }
        percent=(branchTotal/companyTotal)*100.0;
        printf("Percentage Of Branch No.%d: %.2f%%\n",i+1,percent);
    }
}

int peakSales(double sales[][MONTHS],int branches){
    //* Initialize max var as a small num
    double max = -999999999;
    int peakMonth=0;
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++){
            double peak=sales[i][j];
            if (peak > max)
            {
                //*Made max=peak for next loop iteration
                max = peak;
                //* [j] holds months
                peakMonth=j;
            }
        }

    }
    //* Retuning Month 5 is [4]+1 since
    //* array indicies start from 0
    return peakMonth+1;
}

void BranchesByMonth(double sales[][MONTHS],int branches){
    int choice_month,branchID[MAXBRANCHES];
    double sortedBranches[branches][MONTHS];

    //* Branch ID Initialization   
    for (int i=0;i<branches;i++)
        branchID[i]=i+1;

    //*Copies Original Array Into Separate Array For Sorting
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++)
        sortedBranches[i][j]=sales[i][j];
    }

    printf("Choose The Month You Want To Sort Each Branch By (1-12):");
    if(scanf("%d",&choice_month)!=1){
        printf("Invalid Input Try Again!\n");
        clear_buffer();
        return;
    }
    clear_buffer();
    //* Checks Month Range Input
    if (choice_month<1||choice_month>MONTHS){
        printf("Invalid Input Try Again!\n");
        return;
    }
    for (int i=0;i<branches;i++){
        for(int j=0;j<branches-i-1;j++){
            //* Bubble Sorting Descending Order
            if (sortedBranches[j][choice_month-1]<sortedBranches[j+1][choice_month-1]){
                //* Temp var to store an indice
                double temp = sortedBranches[j][choice_month-1];
                //* Swap var from next indice to og indice
                sortedBranches[j][choice_month-1]=sortedBranches[j+1][choice_month-1];
                //*Put Temp Var into next indice
                sortedBranches[j+1][choice_month-1]=temp;

                //* Sorting Index Of Branch
                int tempid=branchID[j];
                branchID[j]=branchID[j+1];
                branchID[j+1]=tempid;
            }
        }
    }
    printf("The Sorted Branches For Month %d Are:\n",choice_month);
    for (int i=0;i<branches;i++)
    printf("Branch No.%d: %.2f\n",branchID[i],sortedBranches[i][choice_month-1]);
}

void MonthsByBranch(double sales[][MONTHS],int branches){
    int branch_choice;
    double sortedMonths[branches][MONTHS];

    //* Copying Array Into Seperate Array So It Doesn't modify original 
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++)
        sortedMonths[i][j]=sales[i][j];
    }
    //*MonthID Initialization
    int MonthID[MONTHS];
    for (int i=0;i<MONTHS;i++){
        MonthID[i]=i+1;
    }

    printf("Choose The Branch You Want To Sort Each Month(1-%d)",branches);
    if (scanf("%d",&branch_choice)!=1){
        printf("Invalid Input Try Again\n");
        clear_buffer();
        return;
    }
    if (branch_choice<1 || branch_choice>branches){
        printf("Invalid Input Try Again\n");
        return;
    }
    clear_buffer();
    for (int i=0;i<MONTHS;i++){
        for (int j=0;j<MONTHS-i-1;j++){
            //* Bubble Sorting Descending Order
            if(sortedMonths[branch_choice-1][j]<sortedMonths[branch_choice-1][j+1]){
                double temp=sortedMonths[branch_choice-1][j];
                sortedMonths[branch_choice-1][j]=sortedMonths[branch_choice-1][j+1];
                sortedMonths[branch_choice-1][j+1]=temp;

                //*Bubble Sorting MonthID
                int tempid=MonthID[j];
                MonthID[j]=MonthID[j+1];
                MonthID[j+1]=tempid;
            }
        }
    }
    printf("The Sorted Months Of Branch No.%d Are:\n",branch_choice);
    for (int i=0;i<MONTHS;i++)
    printf("Month No.%d: %.2f\n",MonthID[i],sortedMonths[branch_choice-1][i]);
}

void savedata(double sales[][MONTHS],int branches){
    //* Creates the .txt file
    FILE *file=fopen("salesData.txt","w");

    //* Error Handling If can't open file
    if (file==NULL){
        printf("Error Opening File...\n");
        return;
    }
    //* Inputs data into the file
    fprintf(file,"%d\n",branches);
    for (int i=0;i<branches;i++){
        for (int j=0;j<MONTHS;j++)
            fprintf(file,"%f ",sales[i][j]);

        fprintf(file,"\n");
    }
    //*Closes File To Prevent Any Further Edits
    fclose(file);
}
void loaddata(double sales[][MONTHS],int *branches){
    //* Looks For the .txt file
    FILE*file=fopen("salesData.txt","r");

    //*Error Handling If Doesn't Exist
    if (file==NULL){
        printf("No Saved Data Found...\n");
        return;
    }
    //* Extracts Data
    fscanf(file,"%d",branches);
    for (int i=0;i<*branches;i++){
        for (int j=0;j<MONTHS;j++)
            fscanf(file,"%lf",&sales[i][j]);
    }
    //* Closes File
    fclose(file);
}

void resetdata(double sales[][MONTHS],int *branches){
    //* Checks If User Confirms To Reset Data
    char resetChoice;
    printf("Are You Sure You Want To Reset All Data? This Action Is Irreversible(Y/n):");
    if(scanf(" %c",&resetChoice)!=1){
        printf("Invalid Input Try Again");
        clear_buffer();
        return;
    }
    clear_buffer();
    if (resetChoice == 'N' || resetChoice == 'n')
    return;

    else if (resetChoice == 'Y' || resetChoice == 'y'){
    FILE *file=fopen("salesData.txt","w");
    if(file==NULL){
        printf("Error Resetting Data...\n");
        return;
    }
    fclose(file);//* Opening And Closing Without Any Edits Formats The File
    
    //*Formats Data The Actual Arrays And No. of branches
    //*For Later Use
    for (int i=0;i<*branches;i++){
        for(int j=0;j<MONTHS;j++)
        sales[i][j]=0;
    }
    *branches=0;
    printf("Data Reset...\n");
    }
}

void checkNoBranch(int* branches){
    while (*branches<=0){
        printf("Enter The Number Of Branches(1-%d):", MAXBRANCHES);
        if (scanf("%d",branches)!=1){
            printf("Invalid Input Try Again\n");
            clear_buffer();
        }
        clear_buffer();
        
        if (*branches<=0 || *branches>MAXBRANCHES){
            printf("Invalid Input Try Again\n");
            *branches=0;
        }
    }
}
void inputbranch(int* branches){
    *branches=0;
    checkNoBranch(branches);
}