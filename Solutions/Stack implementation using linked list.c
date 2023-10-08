#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <malloc.h>
struct node {
    int info;
    struct node * next;
};
struct node * top= NULL;
struct node * createnode(){
    struct node * newnode;
    int value;
    printf("Enter a value: ");
    scanf ("%d",&value);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->info=value;
    newnode->next=NULL;
    return(newnode);
}
struct node * push(struct node * top){
    struct node* ptr;
    int ch=0;
    do{
        ptr=createnode();
        if (top==NULL){
            top=ptr;
        }
        else{
            ptr->next=top;
            top=ptr;
        }
        printf("Do you want to add more values (0/1): ");
        scanf("%d", &ch);
    }while(ch!=0);
    return (top);   
}
 int peek(struct node * top){
    return(top->info);
}
struct node * pop(struct node * top){
    top=top->next;
    return(top);
}

int main()
{
   int ch1;
   printf("<---------PROGRAM FOR CREATION OF STACK------->");
   do{
        printf("\n--------------------------");
        printf("\n#1 Push. ");
        printf("\n#2 Peek.");
        printf("\n#3 Pop.");
        printf("\n#0 Exit.");
        printf("\nEnter your choice: ");
        scanf("%d",&ch1);
        switch (ch1)
        {
        case 1:
            top=push(top);
            break;
        case 2:
            printf("\n--------------------------");
            printf("\ntop= %d",peek(top),"\n");
            break;
        case 3:
            top=pop(top);
            printf("\n--------------------------");
            printf("\npop done successfully");
            break;
        case 0:
            printf("BYE-BYE");
            exit(0);
        }

    }while(1);
}
