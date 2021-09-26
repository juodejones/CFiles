#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Emp {
    int empNo, bpay, allow, ded, netpay;
    char name[20];
    struct Emp *next;
};

void main() {

    int n = 0, exit = 0, e[n];
    char reply;
    struct Emp *ref_ptr, *this_ptr;

    ref_ptr = (struct Emp *) malloc(sizeof(struct Emp));
    this_ptr = ref_ptr;

    while (exit == 0) {
        printf("Enter employee Number : ");
        scanf("%d", &this_ptr->empNo);
        printf("Enter employee Name : ");
        scanf("%s", this_ptr->name);
        printf("Enter the basic pay, allowance and deduction of the employee : ");
        scanf("%d %d %d", &this_ptr->bpay, &this_ptr->allow, &this_ptr->ded);
        getchar();
        e[n] = this_ptr->bpay + this_ptr->allow - this_ptr->ded;
        n++;
        printf("\nWould you like to add more (Y/N)? : ");
        scanf("%c", &reply);
        if ( toupper(reply)=='Y') {
            this_ptr->next = (struct Emp *) malloc(sizeof(struct Emp));
            this_ptr = this_ptr->next;
        } else {
            exit = 1;
            this_ptr->next = (struct Emp *) NULL;
        }
    }

    this_ptr = ref_ptr;
    for (int i = 0; i < n; ++i) {
        printf("Emp.No.->%d\tName->%s\t\t\tBpay->%d\tAllow->%d\tDed->%d\tNetpay->%d\t\n", this_ptr->empNo, this_ptr->name,
               this_ptr->bpay, this_ptr->allow, this_ptr->ded, e[i]);
        this_ptr = this_ptr->next;
    }

}
