#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum Type {unknown,square, triangle, circle} Type;

typedef struct Square {
    char message[16];
} Square;

typedef struct Triangle {
    char message[16];
} Triangle;

typedef struct Circle {
    char message[16];
} Circle;

typedef struct Shape {
    Type type;
    union _data {
        /*char square[16];
        char triangle[16];
        char circle[16];*/
        Square square;
        Triangle triangle;
        Circle circle;
    } data;
} Shape;

Shape* createObject(Type type)
{
    Shape* shape = (Shape*)malloc(1 * sizeof(Shape));

    switch(type) {
        case square:
            shape->type = square;
            //strcpy(shape->data.square, "I am square");
            strcpy(shape->data.square.message, "I am square");
            break;
        case triangle:
            shape->type = triangle;
            //strcpy(shape->data.triangle, "I am triangle");
            strcpy(shape->data.triangle.message, "I am triangle");
            break;
        case circle:
            shape->type = circle;
            //strcpy(shape->data.circle, "I am circle");
            strcpy(shape->data.circle.message, "I am circle");
            break;
        default:
            shape->type = unknown;
    }
    return shape;
}
int main()
{
    Shape* shapes[3];

    for(int i = 0; i < 3; ++i)
    {
        shapes[i] = createObject((Type)(i+1));
    }

    for(int i = 0; i < 3; ++i)
    {
        char* message = "";
        switch(shapes[i]->type) {
            case square:
                message = shapes[i]->data.square.message;
                break;
            case triangle:
                message = shapes[i]->data.triangle.message;
                break;
            case circle:
                message = shapes[i]->data.circle.message;
                break;
            default:
                message = "default";
        }
        printf("message: %s\n", message);
    }
    return 0;
}
