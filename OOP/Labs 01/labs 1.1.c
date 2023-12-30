/*
For the programming language, use C.

Write a program in which the number N (the number of transactions) is entered from standard input, 
followed by N transaction accounts. As a result, print the identification number and the total amount 
(with commission) of all transactions paid with a credit card. In case there is no transaction paid with 
a credit card, print 'No credit card transaction.'

In the structure Transaction, the following information should be stored:

Identification number (int)
Paid amount (int)
Commission (int)
Whether it is paid with a debit or credit card (0 - debit, 1 - credit)
Constraint: 0 < N < 100

Structure of input data:
N
id1 sum1 commission1 type1
...
idn sumn Commissionn typen
*/

#include <stdio.h>

typedef struct Transaction {
    int id;
    int sum;
    int commision;
    int payment_method;
} Transaction;

int main() {
    int n, transaction_flag = 0, count = 0;
    scanf("%d", &n);

    Transaction transaction[50];

    for (int i = 0; i < n; i++) {

        scanf("%d %d %d %d", &transaction[i].id, &transaction[i].sum, &transaction[i].commision, &transaction[i].payment_method);

        if (transaction[i].payment_method == 1) {
            transaction_flag = 1;
            count++;
        }
    }

    if (transaction_flag == 1) {
        for (int i = 0; i < n; i++) {
            if (transaction[i].payment_method == 1)
                printf("%d %d\n", transaction[i].id, transaction[i].sum + transaction[i].commision);
        }
    }
    if (count == 0) printf("No credit card transaction");
    return 0;
}
