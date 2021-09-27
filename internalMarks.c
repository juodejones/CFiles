//Created  by Juode

#include<stdio.h>

struct student
{
    char studentName[30];
    long rollNo;
    int marks[5][3];
    int internal[5];

}students[10];

void calcinternal(int n)
{

    int total;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            total = 0;
            for (int k = 0; k < 3; k++)
            {
                total += students[i].marks[j][k];
            }
            students[i].internal[j] = total/3;
        }

    }

}

int main()
{
    int stud, sub, test, n;

    printf("Enter the number of students : ");
    scanf("%d", &n);
    for(stud = 0 ; stud < n; stud++){
        printf("Enter name: ");
        scanf("%s", students[stud].studentName);
        printf("Enter roll number : ");
        scanf("%ld",&students[stud].rollNo);

        for (sub = 0; sub < 5 ; sub++)
        {
            printf("Subject %d marks \n" , (sub+1));

            for ( test = 0; test < 3 ; test++)
            {
                printf("Enter test %d mark: ",(test+1));
                scanf("%d",&students[stud].marks[sub][test]);
            }
        }
    }
    calcinternal(n);

    for (stud = 0; stud < n; stud++)
    {
        printf("\t\t\tMarksheet");
        printf("Name : %s \n", students[stud].studentName);
        printf("Roll No : %ld \n", students[stud].rollNo);

        for (sub = 0; sub < 5; sub++)
        {
            printf("Internal mark of %d : %d \n", (sub+1), students[stud].internal[sub]);
        }
    }
    return 0;
}
