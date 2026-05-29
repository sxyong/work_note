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

## 智能指针

- unique_ptr  
```c++
unique_ptr<int> p = make_unique<int>(10);
// p.get() 获取原始指针。
// 本身也可以当作对象指针来使用

// ❌ 错误  不能拷贝
// std::unique_ptr<int> p2 = p1;

// ✅ 正确  可以移动
std::unique_ptr<int> p2 = std::move(p1);
```

- shared_prt  
```c++
shared_ptr<int> p = make_shared<int>(10);
shared_ptr<int> p2 = p;
```
p和p2指向同一个指针。内部使用引用计数管理。当计数为0的时候销毁。  

- weak_ptr  
```c++
class A {
    share_ptr<B> b;
};

class B {
    weak_ptr<A> a;
};
```
当2个对象相互引用的时候，不能都使用share_ptr,其中一个需要使用weak_ptr。  

weak_ptr的创建方法如下：  
```c++
unique_ptr<int> p = make_unique<int>(10);
weak_ptr<int> p2 = p;
```

## c++ 流

流是一种抽象，用来表示“连续的数据序列”。常见的方法有：<<, >>, read, write。常用的有文件（ifstream, ofstream, fstream），内存（stringstream, istringstream, ostream），标准设备（cin, cout, cerr）。  

文本模式用<<, >>格式化读写。二进制直接使用read, write。  

文件流示例：  
```c++
#include <fstream>
std::ofstream ofs("data.txt");
ofs << "hello\n";

std::ifstream ifs("data.txt");
std::string s;
ifs >> s;  // 读取到空格或换行
```

内存流示例：  
```c++
#include <sstream>
std::stringstream ss;
ss << 123 << " " << 456;

int a, b;
ss >> a >> b;
```

示例代码参考project/stream。  

