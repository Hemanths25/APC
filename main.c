#include "main.h"

int main(int argc,char* argv[]){

    if(argc!=4){
        help();
        return e_failure;
    }

    if(validation(argv[1],argv[2],argv[3])==e_failure){
        printf("Enter a valid equation\n");
        return e_failure;
    }

    //for operand 1
    operand *head1 = NULL;
    operand *tail1 = NULL;

    //for operand 2
    operand *head2 = NULL;
    operand *tail2 = NULL;

    //for result
    operand *res_head = NULL;
    operand *res_tail = NULL;

    operand *mul_head = NULL;
    operand *mul_tail = NULL; 

    //to find large number and sign
    large_sign LARGE_SIGN;

    //storing operator to structure
    LARGE_SIGN.operator = argv[2][0];

    //to divide 4 numbers in each node
    divide_number(argv[1],&head1,&tail1); 
    divide_number(argv[3],&head2,&tail2);

    //to find larger number and sign
    find_larger_sign(argv[1],argv[3],head1,head2,&LARGE_SIGN);
    

    //for addition operation
    if(LARGE_SIGN.operator == '+'){

        //if sign of both operand is different perform subtraction
        if(strcmp(LARGE_SIGN.sign,"+-")==0 || strcmp(LARGE_SIGN.sign,"-+")==0){
            subtraction(tail1,tail2,&res_head,&res_tail,LARGE_SIGN.large);
        }

        //if sign of both operand is same perform subtraction
        else{
            addition(tail1,tail2,&res_head,&res_tail);
        }
    }

    //for subtraction operation
    else if(LARGE_SIGN.operator == '-'){
        
        //if sign of both operand is different perform addition
        if(strcmp(LARGE_SIGN.sign,"+-")==0 || strcmp(LARGE_SIGN.sign,"-+")==0){
            addition(tail1,tail2,&res_head,&res_tail);
        }
        
        //if sign of both operand is same perform subtraction
        else{
            subtraction(tail1,tail2,&res_head,&res_tail,LARGE_SIGN.large);
        }
    }

    //to perform division
    else if(LARGE_SIGN.operator == '/'){
        if(division(head1,head2,&res_head,&res_tail)==e_failure){
            return e_failure;
        }
    }

    //to perform multiplication
    else if(LARGE_SIGN.operator == 'x'){
       multiplication(head1,tail1,head2,tail2,&res_head,&res_tail);
    }

    //to print the result
    print_list(res_head,LARGE_SIGN);
}