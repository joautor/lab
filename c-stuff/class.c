#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char sound[100];
    void (*MakeSound)(struct Animal*);
} Animal;

void MakeSound(Animal* thisObject)
{
    printf("%s: %s!\n", thisObject->name, thisObject->sound);
}

Animal* CreateObject(char* name, char* sound)
{
    Animal* pAnimal = (Animal*)malloc(sizeof(Animal));
    pAnimal->MakeSound = MakeSound;
    strcpy(pAnimal->name, name);
    strcpy(pAnimal->sound, sound);
    return pAnimal;
}

int main() {
    // Write C code here
    printf("Hello world\n");

    Animal* animal = CreateObject("Wolf", "Awwwwooohh!");
    animal->MakeSound(animal);

    Animal* dog = CreateObject("Dog", "Aw aw aw!");
    dog->MakeSound(dog);

    Animal* cat = CreateObject("Cat", "meeooow!");
    cat->MakeSound(cat);
    return 0;
}
