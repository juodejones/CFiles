//Created  by Juode

#include <stdio.h>
#include <time.h>

struct date
{
    int day;
    int month;
    int year;
}Date;

struct employee
{
    long int empId;
    char empName[20];
    int empSalary;
    struct date empDate;
};

int increment(int salary)
{
    int salInc;
    if(salary <= 2000)
        salInc = (salary * 15) / 100;
    else if(salary > 2000 && salary <= 5000)
        salInc = (salary * 10) / 100;
    else
        salInc = 0;

    return salInc;
}

int main()
{
    int n;
    long int empId;
    int choice;
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    int thisYear = local->tm_year;

    printf("Enter the number of employees : ");
    scanf("%d", &n);
    struct employee empList[n];

    for( int i=0; i < n ; i++ )
    {
        printf("Enter employee %d ID: ", i+1);
        scanf("%ld",&empList[i].empId);
        printf("Enter employee %d Name: ", i+1);
        scanf("%s",empList[i].empName);
        printf("Enter employee %d Salary: ", i+1);
        scanf("%d",&empList[i].empSalary);
        printf("Enter employee %d Joining Date (DD MM YYYY): ", i+1);
        scanf("%d%d%d", &empList[i].empDate.day, &empList[i].empDate.month, &empList[i].empDate.year);

    }


    printf("Enter your choice: ");
    printf("\n\t1 -> Increment Salary");
    printf("\n\t2 -> Show employee details\n");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter employee ID: ");
            scanf("%ld", &empId);
            for (int i = 0; i < n; i++) {
                if (empId == empList[i].empId) {
                    empList[i].empSalary += increment(empList[i].empSalary);
                    printf("Salary of %s is %d", empList[i].empName, empList[i].empSalary);
                    break;
                }
            }
            printf("Employee Not found");
            break;
        case 2:
            for (int i = 0; i < n; i++) {
                int diff = thisYear - empList[i].empDate.year;
                if(diff >= 10)
                {
                    printf("Employee ID -> %ld\tEmployee Name -> %s\tEmployee Salary -> %i",
                           empList[i].empId, empList[i].empName, empList[i].empSalary);
                }
            }
            break;
        default:
            printf("Invalid Choice!");
    }
    return 0;
}

