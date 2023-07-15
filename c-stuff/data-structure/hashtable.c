#include <stdio.h>
#include <stdbool.h>
#include <string.h>
// #include <assert.h>


#define TABLE_SIZE      20
#define INVALID_INDEX   -1

typedef struct Person {
    char* name;
    int age;
    char* address;
    // struct Person* nextPerson;
} Person;


// ToDo: Formulate a better hash function
int hash(char* str)
{
    // printf("str input: %s\n", str);
    if ((str == NULL) || (*str == '\0')) {
        printf("hash: Invalid str");
        return  INVALID_INDEX;
    }

    int index = 0;
    while((str != NULL) && (*str != '\0')) {
        index = ((index + (*str) * (index + 1)) % TABLE_SIZE);
        ++str;
    }
    printf("hash value: %d, %s\n", index, str);
    return index;
}

void displayTable(Person** personTable, int size)
{
    printf("\n==start table==\n");
    for (int i = 0; i < size; ++i) {
        Person* ptrPerson = personTable[i];
        if (ptrPerson == NULL) {
            printf("\t[%d]----- empty -----\n", i);
            continue;
        }
        printf("\t[%d] %s\t%2d \t%s\n", i, ptrPerson->name, ptrPerson->age, ptrPerson->address);
    }
    printf("==end table==\n");
}


void initializeEmptyHash(Person** personTable, int size)
{
    for (int i = 0; i < size; ++i) {
        personTable[i] = NULL;
    }
}

// ToDo: Handle collision instances, currently doens't insert when collision occurs
bool insertToHash(Person* person, Person** hashTable)
{
    if (person == NULL) {
        printf("person is null\n");
        return false;
    }
    int index = hash(person->name);
    if (index == INVALID_INDEX) {
        printf("invalid index\n");
        return false;
    }
    if ((index < 0) && (index <= TABLE_SIZE)) return false;

    if (hashTable[index] != NULL) {
        printf("insertToHash: Can't insert new data. Confict occured: %d, %s\n", index, person->name);
        return false;
    }
    hashTable[index] = person;
    printf("insertToHash: Success\n");
    return true;
}

Person* getDataFromHash(char* str, Person** hashTable)
{
    Person* p = NULL;
    int index = hash(str);
    if (index != INVALID_INDEX) {
        p = hashTable[index];
        if (strcmp(str, p->name) != 0) {
            p = NULL; // false positive, returns hash index but str does't match with the data
        }
    }
    return p;
}

void printPerson(Person* p)
{
    if (p != NULL) {
        printf("Get data: \ntname: %s\tage: %d\t address: %s\n",p->name, p->age, p->address);
    } else {
        printf("Person is NULL\n");
    }
}

int main()
{
    Person* hashTable[TABLE_SIZE];
    initializeEmptyHash(hashTable, TABLE_SIZE);

    Person one = {"Juan abc", 22, "Sample City"};
    Person two = {"De La one", 19, "Hello Province"};
    Person three = {"A", 24, "Blah blah city"};

    displayTable(hashTable, TABLE_SIZE);

    insertToHash(&one, hashTable);
    insertToHash(&two, hashTable);
    insertToHash(&three, hashTable);

    displayTable(hashTable, TABLE_SIZE);

    Person* p = NULL;
    p = getDataFromHash("Juan abc", hashTable);
    printPerson(p);
    p = getDataFromHash("abc", hashTable);
    printPerson(p);
    p = getDataFromHash("A", hashTable);
    printPerson(p);

    return 0;
}
