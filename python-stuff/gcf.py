#!/usr/bin/python3

def getGCF(x, y):
    num1 = x
    num2 = y
    gcf = 0
    while True:
        r = num1 % num2
        if r == 0:
            gcf = num2
            break
        else:
            num1 = num2
            num2 = r
    return gcf

def getgcf(x,y):
    num1 = x
    num2 = y
    r = num1 % num2
    while r != 0:
        num1 = num2
        num2 = r
        r = num1 % num2
    return num2


print("GCF is " + str(getGCF(10, 5)));
print("GCF is " + str(getGCF(10, 3)));
print("GCF is " + str(getGCF(5, 3)));
print("GCF is " + str(getGCF(100, 75)));

print("GCF is " + str(getgcf(10, 5)));
print("GCF is " + str(getgcf(100, 75)));
