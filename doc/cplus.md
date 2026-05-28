# c++ 笔记

记录一些个人误解或有代表的知识点。  

## 函数返回临时结构体

之前一直认为如果函数返回一个函数内部的结构体是错误的--函数内部变量出函数后生命周期已经结束，因此是有问题的。  
```code
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
```
其实这样是没有问题的。在结束之前，编译器会拷贝或直接构造返回值(RVO)。  

RVO--返回值优化。  
理论流程是：
- 创建局部对象 p
- 拷贝/移动到返回值临时对象
- 再拷贝/移动到接收变量

RVO 优化后：  
编译器直接变成：  
在“调用者的空间里”直接构造返回对象。  

同样的，函数中返回一个容器也是没有问题的。  
```
vector<int> GetVector() {
    vector<int> vecInt;

    vecInt.push_back(1);
    vecInt.push_back(5);
    vecInt.push_back(7);

    return vecInt;
}
```