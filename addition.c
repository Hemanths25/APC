#include "main.h"
//addition operation
int addition(operand *tail1,operand *tail2, operand **res_head, operand **res_tail){
    int data,carry=0;
    
    //loop till both tail is null
    while(tail1 || tail2){

        //if any tail is null default value with 0
        int val1 = (tail1) ? tail1->data : 0; 
        int val2 = (tail2) ? tail2->data : 0;

        data = val1 + val2 + carry;

        //if number is larger than 9999 carry is generated
        if(data > MAX){
            carry = 1;
            data = data - (MAX+1);
        }
        //else no carry
        else{
            carry = 0;
        }

        //insert to list
        insert_first(res_head,res_tail,data);

        if(tail1!=NULL)
        tail1 = tail1->prev;

        if(tail2!=NULL)
        tail2 = tail2->prev;
    }
    //after all if still carry is remining add to list
    if(carry){
        insert_first(res_head,res_tail,carry);
    }
}