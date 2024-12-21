#include "main.h"
//subtraction operation
int subtraction(operand *tail1,operand *tail2, operand **res_head, operand **res_tail,int large){
    int data,borrow=0;
    
    //loop till both tail is null
    while(tail1 || tail2){

        //if any tail is null default value with 0
        int val1 = (tail1) ? tail1->data : 0; 
        int val2 = (tail2) ? tail2->data : 0;

        //for op1 larger
        if(large == 1)
        data = val1 - val2 - borrow;

        //for op2 larger
        else
        data = val2 - val1 - borrow;

        //if result is -ve take borrow
        if(data < 0){
            borrow = 1;
            data = data + (MAX+1);
        }
        //else no borrow required
        else{
            borrow = 0;
        }

        //insert to list
        insert_first(res_head,res_tail,data);

        if(tail1!=NULL)
        tail1 = tail1->prev;

        if(tail2!=NULL)
        tail2 = tail2->prev;
    }
}