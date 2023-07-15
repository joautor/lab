#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 13

typedef struct Node {
    int id;
    char name[SIZE];
    float price;
    struct Node* next;
} Node;

void dumpNode(const Node* node)
{
    printf("Node(%d)-> name: %s, price: %.2f; next: %p\n", node->id, node->name, node->price, node->next);
}

char* getInput()
{
    static char temp[SIZE]; //we are returning an address of a local variable so we need to set it to static
    //scanf("%s", temp);

    if (fgets(temp, SIZE,stdin) == NULL)
    {
        fprintf(stderr, "Error in getting input");
        exit(1);
    }

    //remove newline in the input string
    temp[strcspn(temp, "\n")] = 0;

    return temp;
}

Node* allocate()
{
    Node* node;

    node = (Node*) malloc(sizeof(Node) * 1);
    if (node == NULL)
    {
        fprintf(stderr, "Error in allocating memory\n");
        exit(1);
    }
    return node;
}

void deleteAllNodes(Node* node)
{
    Node* next;
    while(node == NULL)
    {
        next = node->next;
        free(node);
        node = next;
    }
    printf("deleted all nodes!\n");

}

Node* createNode(int id)
{
    Node* newNode = allocate();

    printf("Enter item name: ");
    strcpy(newNode->name, getInput()); 

    printf("Enter item price: ");
    newNode->price = strtof(getInput(), NULL);

    newNode->next = NULL;
    newNode->id = id;

    printf("----------------------\n");

    return newNode;
}

void showAllItems(const Node* node)
{
    while (node != NULL)
    {
        dumpNode(node);
        node = node->next;
    }
}

void removeNode(Node* node, int index, Node** outputFirst)
{
    printf("removing node number %d... ", index);
    Node* prevNode;

    while (node != NULL)
    {
       // printf("(node->id :  %d\n", node->id);

        if (node->id == index)
        {
            if (prevNode != NULL)
            {
                prevNode->next = node->next;
            }
            else  // if the node to delete is the head of the linkedlist 
            {
                *outputFirst = node->next;
            }
            free(node);
            break;
        }
        prevNode = node;
        node = node->next;
    }
    printf("done! \n");
}

int main()
{
    Node *first, *current;
    int size = 5;

    first = createNode(0);
    current = first;

    for(int id = 1; id < size; ++id)
    {
        current->next = createNode(id);
        current = current->next;
    }

    showAllItems(first);
    removeNode(first, 3, &first);
    showAllItems(first);
    removeNode(first, 0, &first);
    showAllItems(first);

    deleteAllNodes(first);

    return 0;
}
