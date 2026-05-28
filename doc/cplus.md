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

## stl 中常用的算法

查找。  
```c++
void fun() {
    vector<int> vec {1, 3, 8, 10};
    auto it = find(vec.begin(), vec.end(), 8);
    if (it != vec.end()) {
        std::cout << "find it: " << *it << std::endl;
    } else {
        std::cout << "not find" << std::endl;
    }

    it = find_if(vec.begin(), vec.end() [](int x) {
        return x > 4;
    });
}
```

删除。调用remove后，需要调用erase。  
```c++
void fun() {
    vector<int> vec { 1, 3, 9, 5, 8, 2 };
    auto it = remove_if(vec.begin(), vec.end(), [](int a) {
        return (a % 2) == 1;
    });

    std::cout << "after remove " << std::endl;
    for (const auto& i : vec) {
        std::cout << i << " " << std::endl;
    }

    std::cout << "after erase " << std::endl;

    if (it != vec.end()) {
        vec.erase(it, vec.end());
    }

    for (const auto& i : vec) {
        std::cout << i << " " << std::endl;
    }

    std::cout << std::endl;
}
```

累加。  
```c++
void fun_sum() {
    vector<int> vec { 1, 3, 9, 5, 8, 2 };

    int sum = accumulate(vec.begin(), vec.end(), 0);
    std::cout << "sum is: " << sum << std::endl;
}
```

统计。  
```c++
void fun() {
    vector<int> vec { 1, 3, 9, 5, 8, 2, 2, 2 };

    int cnt = count(vec.begin(), vec.end(), 2);
    std::cout << "have [" << cnt << "] " << "2" << std::endl;

    cnt = count_if(vec.begin(), vec.end(), [](int a){
        return a > 5;
    });
    std::cout << "have [" << cnt << "] " << ">5" << std::endl;
}
```

判断。  
- any_of 任意一个满足
- all_of 全都满足
- none_of 全不满足  

这里不在一一举例。  