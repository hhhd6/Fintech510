#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
    int months;
    double contribution;
    double rate_of_return;
};
typedef struct _retire_info retire_info;

double countBalance(double balance, retire_info a) {
    balance = balance * (1 + a.rate_of_return) + a.contribution;
    return balance;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
    double balance = initial;
    
    // Working phase
    for (int i = 0; i < working.months + 1; i++) {
        int age = (startAge + i) / 12;
        int month = (startAge + i) % 12;
        printf("Age %3d month %2d you have $%.2f\n", age, month, balance);
        if (i == working.months) {
            break;
        }
        balance = countBalance(balance, working);
    }

    // Retired phase - No change in logic here
    for (int j = 1; j < retired.months; j++) {
        int age = (startAge + working.months + j) / 12;
        int month = (startAge + working.months + j) % 12;
        balance = countBalance(balance, retired);
        printf("Age %3d month %2d you have $%.2f\n", age, month, balance);
    }
}

int main(void) {
    int startAge = 327;  // 27 years and 3 months
    double initial = 21345;  // Initial savings of $21,345

    // Working phase: 40 years and 9 months, contributing $1000 per month with 4.5% annual return
    retire_info working = {
        489, 1000.0, 0.045 / 12
    };

    // Retired phase: 32 years, spending $4000 per month with 1% annual return
    retire_info retired = {
        384, -4000.0, 0.01 / 12
    };

    // Perform retirement calculation
    retirement(startAge, initial, working, retired);
    
    return 0;
}
