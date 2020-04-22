//@ author Devang Sharma
// Using linked lists to switch numbers around
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node
{
    int value;
    struct node *next;
}
node;

int main(void)
{
    // heading Node
    node *head = NULL;

    // Allocating memory for the nodes
    head = malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Error\n");
        return 1;
    }
    // Getting input from user
    head->value = get_int("First number: ");
    // Assigning the next of this node to the second node
    head->next = NULL;
    // Assigning head to the first node

    // Creating second node
    node *s = malloc(sizeof(node));
    if (s == NULL)
    {
        printf("Error creating second node");
        return 1;
    }
    // Getting input from user
    s->value = get_int("Second number: ");
    // Linking second and third node
    s->next = NULL;
    head->next = s;


    // Creating third node
    node *t = malloc(sizeof(node));
    if (t == NULL)
    {
        printf("Error creating third node");
        return 1;
    }
    t->value = get_int("Third number: ");
    t->next = NULL;
    s->next = t;
    node *temp1 = head;
    printf("Your original numbers are: ");
    while (temp1 != NULL)
    {
        printf("%i, ", temp1->value);
        temp1 = temp1->next;
    }
    printf("\n");
    //free(s);
    //free(t);
    // Swapping
    node *temp = head;
    head = head->next;
    temp->next = head->next;
    head->next = temp;
    temp = head;
    printf("The new numbers are: ");
    while (temp != NULL)
    {
        printf("%i, ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    while (head != NULL)
    {
        node *tmp = head->next;
        free(head);
        head = tmp;
    }

}
