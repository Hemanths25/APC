#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 9999

typedef enum{
    e_success,
    e_failure
} Status;


typedef struct node{
    int data;
    struct node* prev;
    struct node* next;
}operand;

typedef struct new{
    int large;
    char sign[3];
    char operator;
}large_sign;



void help();
Status validation(char* op1,char* sy,char* op2);
Status divide_number(char* argv,operand **head,operand **tail);
Status find_larger_sign(char* num1, char* num2, operand *head1,operand *head2,large_sign* LONG_SIGN);
void print_sign(large_sign LARGE_SIGN);
void print_list(operand *head, large_sign LARGE_SIGN);
Status insert_first(operand **head, operand **tail, int data);
Status insert_last(operand **head, operand **tail, int data);
int addition(operand *tail1,operand *tail2, operand **res_head, operand **res_tail);
int subtraction(operand *tail1,operand *tail2, operand **res_head, operand **res_tail,int large);
int multiplication(operand *head1,operand *tail1,operand *head2, operand *tail2, operand **res_head, operand **res_tail);
int division(operand *head1, operand *tail1, operand **res_head, operand **res_tail);
 
 