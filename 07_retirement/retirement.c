#include <stdlib.h>
#include <stdio.h>

struct _retire_info {
  int months;
  double contribution;
  double rate_of_return;
};

typedef struct _retire_info retire_info;

void printCurrentBalance(int age, double balance) {
  printf("Age %3d month %2d you have $%.2lf\n", age / 12, age % 12, balance);
}


double accountCalculation(int startAge, double startBalance, retire_info info) {
  double balance;
  balance = startBalance;
  for (int m = 0; m < info.months; m++) {
    printCurrentBalance(startAge + m, balance);
    balance = balance + balance *  info.rate_of_return + info.contribution;
  }
  return balance;
}


void retirement(int startAge, //in mounth
		double initial, //initial savings in dollars
		retire_info working, // info about working
		retire_info retired) { // info about retired

  double balance;

  // Calculation while working
  balance = accountCalculation(startAge, initial,  working);
  // Calculation shile retired
  balance = accountCalculation(startAge + working.months, balance, retired);
}

int main(void) {

    //Starting conditions:
    int start_age;
    double initial_balance;

    start_age = 327;
    initial_balance = 21345;

    //Conditions while working:
    retire_info working;
    working.months = 489;
    working.contribution = 1000;
    working.rate_of_return = 0.045 / 12;

    //Conditions while retired
    retire_info retired;
    retired.months = 384;
    retired.contribution = -4000;
    retired.rate_of_return = 0.01 / 12;

    retirement(start_age, initial_balance, working, retired);

    return 0;
}
