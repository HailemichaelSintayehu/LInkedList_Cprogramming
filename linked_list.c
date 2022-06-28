#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// items (item 1,item 2 and item 3) and pointer for each item ,at last NULL;
// addItem removetem and getItem

// structure of the node
void create();
void insertEnd();
void deleteUsingIndex();
void search();
void display();

struct node
{
        int data;
        struct node *next;
};
struct node *head = NULL;
// create display function also possible.

int main()
{
        int choice;
        while (1)
        {

                printf("\n\n*********Main Menu*********\n");
                printf("choice one option from the following list");
                printf("\n0.create \n1.Insert at last\n2.Delete one from the list\n3.Search for an element\n4.display\n5.Exit\n");
                printf("\nEnter your choice");
                scanf("%d", &choice);
                switch (choice)
                {
                case 0:
                        create();
                        break;
                case 1:
                        insertEnd();
                        break;
                case 2:
                        deleteUsingIndex();
                        break;
                case 3:
                        search();
                        break;
                case 4:
                        display();
                        break;
                case 5:
                        exit(0);
                default:
                        printf("\n Wrong Choice");
                }
        }
}
void create()
{
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));

        printf("Enter node data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (head == NULL)
        {
                head = temp;
        }
        else
        {
                struct node *ptr = head;
                while (ptr->next != NULL)
                {
                        ptr = ptr->next;
                }
                ptr->next = temp;
        }
}
void display()
{

        if (head == NULL)
        {
                printf("linked list is Empty\n");
                return;
        }
        printf("linked list: ");
        struct node *ptr = head;
        while (ptr != NULL)
        {
                printf("%d", ptr->data);
                printf(" ");
                ptr = ptr->next;
        }
        printf("\n");
}

void insertEnd()
{
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));

        // ask the user to insert the value by himself
        printf("Enter Node data");

        scanf("%d", &temp->data);

        temp->next = NULL;
        if (head == NULL)
        {
                head = temp;
        }
        else
        {
                struct node *ptr = head;
                while (ptr->next != NULL)
                {
                        ptr = ptr->next;
                }
                ptr->next = temp;
        }
}

void deleteUsingIndex()
{
        int position;
        struct node *ptr = head;
        printf("enter the postion to delete: ");
        scanf("%d", &position);
        if (head == NULL)
        {
                printf("Linked list is empty");
                return;
        }
        else if (position == 0)
        {
                ptr = head;
                head = ptr->next;
                free(ptr);
        }
        else
        {
                bool errr
                struct node *prev_ptr;
                for (int i = 0; i < position; i++)
                {
                        if (ptr->next == NULL)
                        {
                                printf("please enter valid position");
                                return;
                        }
                        
                        prev_ptr = ptr;

                        ptr = ptr->next;
                }
                prev_ptr->next = ptr->next;
                free(ptr);
        }
}
void search(int key)
{
        int count = 0;
        struct node *ptr = head;
        printf("enter number to search");
        scanf("%d", &key);
        while (ptr != NULL)
        {
                count++;
                if (ptr->data == key)
                {

                        printf("Found at position");
                        printf("%d", count);
                }
                ptr = ptr->next;
        }
}
