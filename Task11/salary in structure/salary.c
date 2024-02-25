#include <stdio.h>


typedef struct {
    float salary;
    float bonus;
    float deductions;
} Employee;

int main() {

    Employee ahmed, waleed, amr;


    printf("Please Enter Ahmed Salary: ");
    scanf("%f", &ahmed.salary);
    printf("Please Enter Ahmed Bonus: ");
    scanf("%f", &ahmed.bonus);
    printf("Please Enter Ahmed Deduction: ");
    scanf("%f", &ahmed.deductions);


    printf("Please Enter Amr Salary: ");
    scanf("%f", &Amr.salary);
    printf("Please Enter Amr Bonus: ");
    scanf("%f", &Amr.bonus);
    printf("Please Enter Amr Deduction: ");
    scanf("%f", &Amr.deductions);


    printf("Please Enter Waleed Salary: ");
    scanf("%f", &waleed.salary);
    printf("Please Enter Waleed Bonus: ");
    scanf("%f", &waleed.bonus);
    printf("Please Enter Waleed Deduction: ");
    scanf("%f", &waleed.deductions);


    float totalValue = ahmed.salary + ahmed.bonus - ahmed.deductions +
                       waleed.salary + waleed.bonus - waleed.deductions +
                       amr.salary + amr.bonus - amr.deductions;

    printf("Total value supplied by the finance team: %.2f\n", totalValue);

    return 0;
}
