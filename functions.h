extern int loopCount;
extern int option;
extern int size;
struct employees{
    int id;
    char name[20];
    int salaryBasic;
    float salaryGross;
};
void addData(struct employees EMP[],int count);
void editRow(struct employees EMP[]);
void deleteRaw(struct employees EMP[]);
void previewChanges(struct employees EMP[]);
void saveChanges(struct employees EMP[]);
void viewDataTable();
void editDataTable();
void menu();
void getEmployeeDetails(struct employees EMP[],int num);
float calculateSalaryGross(int basicSalary);