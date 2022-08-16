#include <iostream>
#include <Windows.h>
class Stack {
public:
    Stack(int size) {
        this->stackMemory = VirtualAlloc(0, size, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
        this->sp = size;
    }
    void Push(void* ptr) {
        sp -= 4;
        *(DWORD*)((DWORD)this->stackMemory + sp) = (DWORD)ptr;
    }
    void* Pop() {
        void* ret = (void*)*(DWORD*)((DWORD)this->stackMemory + sp);
        sp += 4;
        return ret;
    }
private:
    void* stackMemory;
public:
    int sp = 0;
};

int main()
{
    Stack* stack = new Stack(64);
    std::cout << "Pushing string onto the stack." << std::endl;
    stack->Push((void*)"An example of how stack works!");
    std::cout << "string has been pushed! Poping it out of stack." << std::endl;
    const char* str = (const char*)stack->Pop();
    std::cout << "Poped string: " << str << std::endl;
    return 0;
}