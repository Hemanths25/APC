#include "main.h"
int multiplication(operand *head1, operand *tail1, operand *head2, operand *tail2, operand **res_head, operand **res_tail) {
    if (head1 == NULL || head2 == NULL) {
        printf("Error: One or both input lists are empty.\n");
        return e_failure; // Error
    }

    operand *temp2 = tail2; // Start from the least significant digit of the second number
    int position = 0;       // Track the place value (e.g., units, tens, hundreds)
    operand *final_head = NULL, *final_tail = NULL;

    // Traverse each digit of the second number from least to most significant
    while (temp2 != NULL) {
        operand *temp1 = tail1; // Start from the least significant digit of the first number
        operand *partial_head = NULL, *partial_tail = NULL;
        int carry = 0;

        // Add leading zeros for the current place value
        for (int i = 0; i < position; i++) {
            insert_first(&partial_head, &partial_tail, 0);
        }

        // Multiply each digit of the first number by the current digit of the second number
        while (temp1 != NULL) {
            long long product = (long long)temp1->data * temp2->data + carry;
            int remainder = product % 10000;
            carry = product / 10000;

            // Insert the remainder into the partial result list
            insert_first(&partial_head, &partial_tail, remainder);
            temp1 = temp1->prev; // Move to the previous digit of the first number
        }

        // If there's any carry left, insert it
        if (carry > 0) {
            insert_first(&partial_head, &partial_tail, carry);
        }

        // Add the current partial result to the cumulative result
        addition(final_tail, partial_tail, &final_head, &final_tail);

        // Move to the previous digit of the second number
        temp2 = temp2->prev;

        // Increment the position for the next place value
        position++;
    }

    // Update the result pointers
    *res_head = final_head;
    *res_tail = final_tail;

    return e_success; // Success
}
