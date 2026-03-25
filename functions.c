#include <stdio.h>

void addData(struct employees EMP[],int size){

    printf("Enter Employee ID, Employee Name, Basic Salary :\n");
    while(loopCount<size){
        printf("(%03d) : ",loopCount+1);
        getEmployeeDetails(EMP,loopCount);
        loopCount++;
    }
    menu();
}

void editRow(struct employees EMP[]){

    int num;
    previewChanges();
    printf("Enter Row Number You Want Edit : ");
    scanf("%d",&num);
    printf("Enter Employee ID, Employee Name, Basic Salary : ");
    getEmployeeDetails(EMP,num-1);
    menu();
}

void deleteRaw(struct employees EMP[]){

    int num;
    previewChanges();
    printf("Enter Row Number You Want Delete : ");
    scanf("%d",&num);
    for(int i=num-1;i<loopCount;i++){
        EMP[i].id = EMP[i+1].id;
        EMP[i].name = EMP[i+1].name;
        EMP[i].salaryBasic = EMP[i+1].salaryBasic;
        EMP[i].salaryGross = EMP[i+1].salaryGross;
    }
    EMP[loopCount].id = 0;
    EMP[loopCount].name[0] = '\0';
    EMP[loopCount].salaryBasic = 0;
    EMP[loopCount].salaryGross = 0.0;
    loopCount--;
    menu();
}

void previewChanges(struct employees EMP[]){

    printf("| %-02s| %-5s| %-20s| %-15s| %-15s|\n","NO:","ID","Employee Name","Basic Salary","Gross Salary");
    for(int i=0;i<loopCount;i++){
        printf("| %-02d| %-5d| %-20s| %-15d| %-15.2f|\n",loopCount+1,EMP[loopCount].id,EMP[loopCount].name,EMP[loopCount].salaryBasic,EMP[loopCount].salaryGross);
    }
    menu();
}

void saveChanges(struct employees EMP[]){

    FILE *fp;
    fp = fopen("dataSheet.txt","a");
    for(int i=0;i<loopCount;i++){
        fprintf("%15s : %-02d\n%15s : %-5d\n%15s : %-20s\n%15s : %-15d\n%15s : %-15.2f\n\n","Employee ID",EMP[i].id,"Employee Name",EMP[i].name,"Basic Salary",EMP[i].salaryBasic,"Gross Salary",EMP[i].salaryGross);
    }
    fclose(fp);
    loopCount = 0;
    size = 0;
    menu();
}

void viewDataTable(){
    menu();
}

void editDataTable(){
    menu();
}

void menu(){
    printf("(01) %15s : 1\n(02) %15s : 2\n(03) %15s : 3\n(04) %15s : 4\n(05) %15s : 5\n(06) %15s : 6\n(07) %15s : 7\n(08) %15s : 8\n\nEnter Your Option : ","Add Data","Edit Raw","Delete Raw","Preview Changes","Save Changes","View Data Table","Edit Data Table","Exit");
    scanf("%d",&option);
    printf("\n");
}

void getEmployeeDetails(struct employees EMP[],int num){

    scanf("%3d %19s %d",&EMP[num].id, EMP[num].name,&EMP[num].salaryBasic);
    EMP[num].salaryBasic=(EMP[num].salaryBasic<0)?0:EMP[num].salaryBasic;
    EMP[num].salaryGross = calculateSalaryGross(EMP[num].salaryBasic);
}

float calculateSalaryGross(int basicSalary){
    
    float grossSalary,transportAllowance = (float)basicSalary*10/100, attendanceAllowance = (basicSalary>35000)? (float)basicSalary*5/100:(float)basicSalary*8/100;
    grossSalary = transportAllowance + attendanceAllowance;
    return grossSalary;
}