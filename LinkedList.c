/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.c
 * Author: Duane Bougard
 * Student Number: 3566258
 *
 * Created on 30 August 2018, 10:07 AM
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "Header.h"
//#include "main.c"

int size=0;
struct Node *head=NULL;
struct Node{
    char data;
    struct Node *next;
};


/*
 * Calculates the number of items in the link list and prints it out.
 * This function first checks if head is not equal to null, meaning if it is empty, if so it prints out zero
 * if it is not empty it prints out the total number of items in linked list 
 * Input: Nothing
 * Output: Prints out the number of items in the linked list
 * Caveats:
 */
void Length()
{
    if(head!=NULL) // if list is  not empty
    {
        printf("%d\n",size); //print size
    }
    else
    {
        printf("0\n",size); // if list is empty print size=0
    }
}

/*
 * This function prints out the value of the last node in the linked list to the user
 * It first checks if the list is empty, if not it assigns a variable currentNode to the head node
 * It then uses this currentNode variable to loop through the linkedlist, while a next node exists
 * currentNode is then updated to the next node in the list
 * The loop ends as soon as there is no next node, meaning the loop has reached the last node
 * The last node is then printed out to the user, using the PrintNode function
 * Input: Nothing
 * Output: Nothing but it prints out the value of the last node to the user
 * Caveats:
 */
void Tail()
{
    if(head!=NULL)
    {
        struct Node *current=head; //assign head to a pointer variable current
        while(current->next!=NULL) //while there is a next item in the list
        {
            current=current->next; //the current node is set to the next node in the list
        }
        PrintNode(current->data,0); //print the value of the last node
    }
    else
    {
        error(); //print out an error to the user
    }
}

/*
 * This functions "pushes" a node onto the linked list. 
 * The node that has the data type char is inserted in front into the list, replacing the previous first node and becomes the new head.
 * The function first checks if the input "nextdata" is less than 65, greater than 90 or if it is an empty character
 * If so, size is incremented by 1 and a new node nextNode is created, 
 * the new node is then set equal to head, head is then equal to the newNode
 * head->character is then equal to next data. this inserts the new node into the linked list 
 * and it becomes head, while the previous head becomes the second item in the list.
 * If the input "nextdata" is NOT less than 65, greater than 90 or if it is NOT an empty character invoke invalid() function to print an error to user
 * Input: char nextdata
 * Output: No output
 * Caveats: Nothing
 */
void Push(char newdata)
{
    if(!(newdata<65 || newdata>90 || newdata==' ')) //checks if the input "nextdata" is less than 65, greater than 90 or if it is an empty character
    {
        size++; //increase the value of size by 1
        struct Node *nextNode=malloc(sizeof(struct Node)); //create a new node
        nextNode->next=head; //swap the new node with the head node
        head=nextNode;
        head->data=newdata; 
    }
    else
    {
        error(); //print out an error
    }
}

/*
 * Prints out an error message "Input not valid"to stderr
 * Input: No input
 * Output No output
 * Caveats:
 */
int error()
{
    fprintf(stderr, "Input not valid\n"); // error message printed to stderr for the user
    return 0; //return nothing
}

/*
 * 
 * Input:
 * Output
 * Caveats:
 */
int Boolean(int answer)
{
    if(answer==0)
    {
        error();
    }
    else if(answer==1)
    {
        size--;
    }
}

/*
 * This function searches for an item in the list of type char and then deletes the first instance of that char item from the list.
 * Input: char deleteData
 * Output: No output
 * Caveats:
 */
void Remove(char item)
{
    struct Node *current=head; //assign head to a variable of type struct Node
    if(head==NULL) // if the list is empty
    {
        Boolean(0);
        return;
    }
    else if(item<'A' || item>'Z') //check if item is not a letter from A to Z
    {
        Boolean(0);
        return;
    }
    else if((head->data)==item) //if the first item is equal to the value of head
    {
        head=head->next; //remove head
        Boolean(1);
        return;
    }
    else
    {
        bool isFound=false;
        int boole=0;
        while((isFound==false) && (current->next !=NULL))
        {
            if(current->next->data == item)
            {
                struct Node *tempcurrent=current->next->next;
                current->next=tempcurrent;
                isFound=true;
                boole=1;
            }
            current=current->next;
        }
        Boolean(boole);
    }
}

/*
 * This function prints out the value of the first element in the linked list to the user
 * It first checks if the list is not empty, if so it then prints out the value of the first node using PrintNode function
 * If the linked list is empty, it prints out an error using invalid() function
 * Input: No input
 * Output: No output but prints out the first element to the user
 * Caveats:
 */
void Head()
{
    if(head!=NULL) //if the list is not empty
    {
        PrintNode(head->data,0); //print the value of head 
    }
    else
    {
        error(); //print an error
    }
}

/*
 * This function prints out all the items in the list if any
 * It first checks if the list is not empty
 * If it is not empty, it assigns head to a struct node pointer currentNode
 * It loops through the list while currentNode is not NULL
 * In the while loop it prints out the data value of currentNode 
 * CurrentNode is then updated to the next item in the list until currentNode is NULL
 * If the list is empty, print (-)
 * Input:
 * Output
 * Caveats:
 */
void PrintList()
{
    if(head!=NULL) //if the list is not empty
    {
        struct Node *current=head; //assign head to the the variable current
        while(current!=NULL) //while current is not euqal to NULL
        {
            PrintNode(current->data,1); //prints out the value of current node
            current=current->next; //set current to the next node in the list
            if(!(current==NULL))
            {
                printf("-");
            }
        }
        printf("\n"); //print new line
    }
    else
    {
        printf("-\n");
    }
}
/*
 * This function is used to print the value of a node in a linked list
 * Input: char printChar, int type
 * Output No output, but it prints the value of a node
 * Caveats:
 */
void PrintNode(char Char,int type)
{
    if(type==0)
    {
        printf("%c\n",Char);
    }
    else if(type==1)
    {
        printf("%c", Char);
    }
}

/*
 * This function is used to determine which function to compute, using input of type char
 * Input: char* instruction
 * Output: int value, from 0-6
 */
int Function(char *run)
{
    if(strcmp(run, "Push")==0) //checks if run is equal to the value of "Push"
    {
        return 0; //returns int zero
    }
    else if(strcmp(run,"Remove")==0) //checks if run is equal to the value of "Remove"
    {
        return 1; //returns int one
    }
    else
    {
        if(strcmp(run,"Head")==0)//checks if run is equal to the value of "Head"
        {
            return 2;//returns int two
        }
        else if(strcmp(run,"Tail")==0)//checks if run is equal to the value of "Tail"
        {
            return 3;//returns int three
        }
        else if(strcmp(run,"Length")==0)//checks if run is equal to the value of "Length"
        {
            return 4;//returns int four
        }
        else if(strcmp(run,"PrintList")==0)//checks if run is equal to the value of "PrintList"
        {
            return 5;//returns int five
        }
        else //else 
        {
            return 6; //returns int six
        }
    }
}

/*
 * This function computes the sppecific function using the input given, its dependent on the value of int which
 * It makes use of a switch with 0-6 cases
 * Input: int func, char* string
 * Output: No output
 * Caveats:
 */
void compute(int func,char* string)
{
    switch(func)
    {
        case 0: Push(string[0]); //invoke the Push function
                break;
        case 1: Remove(string[0]);//invoke the Remove function
                break;        
        case 2: Head();//invoke the Head function
                break;
        case 3: Tail();//invoke the Tail function
                break;
        case 4: Length();//invoke the Length function
                break;
        case 5: PrintList();//invoke the PrintList function
                break;
        case 6: error();//invoke the Error function to print an error
                break;        
    }
}

