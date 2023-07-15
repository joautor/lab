#include <iostream>

template <class T> class MyScopedPtr {
private:
   T* rawPointer;

public:
   MyScopedPtr(T* _rawPointer) : rawPointer(_rawPointer) { }

   ~MyScopedPtr()
   {
      delete rawPointer;
   }

   T& operator*()
   {
      return *rawPointer;
   }

   T* operator->()
   {
      return rawPointer;
   }
};

struct Object {
private:
   std::string name;
public:
   Object(const std::string& _name) : name(_name) {}
   ~Object() { std::cout << "I am deleted :( " << name << std::endl;}
   void foo()
   {
      std::cout << "foooooo from object class: " << name << std::endl;
   }
};

int main()
{
   MyScopedPtr<Object> ptr(new Object("one"));

   ptr->foo();

   MyScopedPtr<int> ptrInt(new int(69));

   MyScopedPtr<Object> ptrObj(new Object("two"));

   return 0;
}