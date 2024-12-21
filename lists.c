#include "main.h"

//help menu
void help(){
	printf("\nERROR\n");
	printf("1. Addition\t-> ./a.out op1 + op2\n2. Substraction\t-> ./a.out op1 - op2\n");
	printf("3. Multiply\t-> ./a.out op1 x op2\n4. Division\t-> ./a.out op1 / op2\n\n");
}

//input validation
Status validation(char* op1,char* sy,char* op2){
	int i=0;

	//skipping sign if present
	if(op1[i]=='+' || op1[i]=='-'){
		i++;
	}

	//till end of number
	while(op1[i]!=0){
		//if other than digit characters failed
		if(!isdigit(op1[i])){
			return e_failure;		
		}
		i++;
	}
	i=0;

	if(op2[i]=='+' || op2[i]=='-'){
		i++;
	}

	while(op2[i]!=0){
		if(!isdigit(op2[i])){
			return e_failure;	
		}
		i++;
	}
	i=0;

	//if anything other than -,+,x,/ symbols return failure 
	if(!(sy[0]=='-' || sy[0]=='+' || sy[0]=='x' || sy[0]=='/' && sy[1]=='\0')){
		return e_failure;
	}
}

//to divide the number and add to linked list
Status divide_number(char* argv,operand **head,operand **tail){
	//taking duplicate of string
	char* str = strdup(argv);
	char* temp = str;

	//skipping sign
	if(*str == '-' || *str == '+'){
		str++;
	}

	//skipping zeros in start
	while(*str=='0'){
		str++;
	}

    int i,num;
    i = strlen(str);
	//taking 4 digit char and converting to integer
    while(i>=0){
    if(i<4 && i!=0){
        num = atoi(str);
    }

    else{
    num = atoi(str+i-4);
    }

    if(i!=0){
        insert_first(head,tail,num);
    }

    str[i-4] = '\0';
    i=i-4;
    }
	free(temp);
}

//to find larger number and sign of number		
Status find_larger_sign(char* num1, char* num2, operand *head1,operand *head2,large_sign* LONG_SIGN){
	LONG_SIGN->large = 1;
	//consider both operand positive initially
	strcpy(LONG_SIGN->sign,"++");

	//taking duplicate
	char* dup = strdup(num1);
	char* temp = dup;

	//adding sign to string
	if(*dup == '+' || *dup =='-'){
		LONG_SIGN->sign[0] = *dup;
		dup++;
	}
	int len1 = strlen(dup);
	//for 0's behind a number
	while(*dup=='0'){
		dup++;
	}

	dup = strdup(num2);
	if(*dup == '+' || *dup =='-'){
		LONG_SIGN->sign[1] = *dup;
		dup++;
	}
	//for 0's behind a number
	while(*dup=='0'){
		dup++;
	}

	int len2 = strlen(dup);
	free(temp);

	//checking larger number based on length
	if(len1!=len2){
	LONG_SIGN->large = len1>len2 ? 1 : 2;
	}

	//for same length number
	else{
		//traverse all node assign large based on value
		while(head1){
			if(head1->data > head2->data){
				LONG_SIGN->large = 1;
				break;
			}
			else if (head1->data != head2->data){
				LONG_SIGN->large = 2;
				break;
			}
			head1 = head1->next;
			head2 = head2->next;
		}
	}
}

//to print sign of result
void print_sign(large_sign LARGE_SIGN){

	char sign = LARGE_SIGN.sign[LARGE_SIGN.large-1];

	if(LARGE_SIGN.operator == '+' && sign != '+'){
			printf("%c",sign);
		}

	else if(LARGE_SIGN.operator == '-'){
		if(strcmp(LARGE_SIGN.sign,"-+")==0)
			printf("-");

		else if(strcmp(LARGE_SIGN.sign,"++")==0 && LARGE_SIGN.large == 2)
		printf("-");

		else if(strcmp(LARGE_SIGN.sign,"--")==0 && LARGE_SIGN.large == 1)
		printf("-");
	}

	else if(LARGE_SIGN.operator == '/'){
		if(strcmp(LARGE_SIGN.sign,"-+")==0 || strcmp(LARGE_SIGN.sign,"+-")==0)
	    printf("-");

		if(LARGE_SIGN.large == 2){
			printf("0");
		}
	}	
}

//print the result
void print_list(operand *head,large_sign LARGE_SIGN){

	if (head == NULL){
		printf("Result: 0\n");
	}
	
	else{
		printf("Result = ");
		print_sign(LARGE_SIGN);
		
	    while (head){
			if(head->prev != NULL && head->data <= 9 && head->data!=0)
		    printf("000%d", head -> data);

			else if(head->prev != NULL && head->data <= 99 && head->data!=0)
			printf("00%d", head -> data);

			else if(head->prev != NULL && head->data <= 999 && head->data!=0)
			printf("0%d", head -> data);

			else if(head->data!=0)
			printf("%d", head -> data);

		    head = head -> next;
	    }
    	printf("\n");
    }
}

//insert first
Status insert_first(operand **head, operand **tail, int data){
    operand* new = malloc(sizeof(operand));
    if(new == NULL){
        return e_failure;
    }
    
    new->data = data;
    new->prev = new->next = NULL;
    
    if(*head == NULL){
        *head = *tail = new;
        return e_success;
    }
    
    (*head)->prev = new;
    new->next = *head;
    *head = new; 
    return e_success;
}

//insert last
Status insert_last(operand **head, operand **tail, int data)
{
    operand* new = malloc(sizeof(operand));
    if(new == NULL){
        return e_failure;
    }
    
    new->data = data;
    new->prev = new->next = NULL;
    
    if(*head == NULL){
        *head = new;
        *tail = new;
        return e_success;
    }
    
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
    return e_success;
}