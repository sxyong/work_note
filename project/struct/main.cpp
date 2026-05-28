#include <iostream>
#include <string.h>

struct Persion {
    int     age;
    char    name[256];
};

Persion GeneratePersion(int age, const char *name) {
    Persion p;

    p.age = age;
    strcpy(p.name, name);

    return p;
}

int main(int argc, char* argv[]) {

    Persion p;

    p = GeneratePersion(10, "zhangsan");

    std::cout << p.age << std::endl;
    std::cout << p.name << std::endl;

    return 0;
}