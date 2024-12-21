#include "main.h"
int division(operand *head1, operand *head2, operand **res_head, operand **res_tail) {
    // if (head1 == NULL || head2 == NULL) {
    //     printf("Error: One or both operands are NULL.\n");
    //     return e_failure;
    // }

    // Convert the divisor (head2) to a single integer
    long long int num2 = 0;
    operand *temp2 = head2;

    while (temp2 != NULL) {
        num2 = num2 * 10000 + temp2->data;
        temp2 = temp2->next;
    }

    // Check for division by zero
    if (num2 == 0) {
        printf("Error: Division by zero is undefined.\n");
        return e_failure;
    }

    // Initialize variables for manual division
    operand *temp1 = head1;
    long long int remainder = 0;
    *res_head = NULL;
    *res_tail = NULL;

    // Process each chunk of the dividend
    while (temp1 != NULL) {
        // Bring down the next chunk of the dividend
        remainder = remainder * 10000 + temp1->data;

        // Calculate the current digit of the quotient
        long long int current_quotient = remainder / num2;

        // Update the remainder
        remainder = remainder % num2;

        // Store the current quotient in the result linked list
        insert_last(res_head, res_tail, current_quotient);

        // Move to the next node in the dividend
        temp1 = temp1->next;
    }

    return e_success;
}
