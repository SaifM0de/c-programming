#include <stdio.h>
#include <stdlib.h>

struct _retire_info {
  int months;
  double contribution, rate_of_return;
};
typedef struct _retire_info retire_info;

double compute(double balance, int contribution, double rate_of_return) {
  double interest = balance * rate_of_return;
  double bal_change = interest + contribution;
  return bal_change;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  double balance = initial;
  double bal_change = 0;
  for(int i = 0; i <= working.months; i++) {
    int year = (startAge + i)/12;
    int month = (startAge + i)%12;
    balance = balance + bal_change;
    if(i == working.months) {
      break;
    }
    printf("Age %3d month %2d you have $%1.2f\n", year, month, balance);
    bal_change =  compute(balance, working.contribution, working.rate_of_return);
  }
  bal_change = 0;
  for(int j = 0; j < retired.months; j++) {
    int year = (startAge + working.months + j)/12;
    int month = (startAge + working.months + j)%12;
    balance = balance + bal_change;
    printf("Age %3d month %2d you have $%1.2f\n", year, month, balance);
    bal_change = compute(balance, retired.contribution, retired.rate_of_return);
  }
}

int main(void) {
  retire_info working;
  retire_info retired;
  
  //Starting conditions
  int startAge = 327;
  double initial = 21345;
  
  //Initialize retire_info working
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045/12;

  //Initialize retire_info retired
  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01/12;

  retirement(startAge, initial, working, retired);

  return EXIT_SUCCESS;
}
