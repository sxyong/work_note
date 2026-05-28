#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using VecInt    = std::vector<int>;

void fun_find() {
    VecInt vec { 1, 3, 9, 5, 8, 2 };

    std::cout << "test fun_find 1-----------------------------" << std::endl;
    auto it = find(vec.begin(), vec.end(), 8);
    if (it != vec.end()) {
        std::cout << "find it: " << *it << std::endl;
    } else {
        std::cout << "not find" << std::endl;
    }

    std::cout << "test fun_find 2-----------------------------" << std::endl;
    it = find_if(vec.begin(), vec.end(), [](int a) {
        return a > 4;
    });
    if (it != vec.end()) {
        std::cout << "find it: " << *it << std::endl;
    } else {
        std::cout << "not find" << std::endl;
    }
}

void fun_minmax() {
    VecInt vec { 1, 3, 9, 5, 8, 2 };

    std::cout << "test fun_minmax 1-----------------------------" << std::endl;
    auto it = max_element(vec.begin(), vec.end());
    if (it != vec.end()) {
        std::cout << "max: " << *it << std::endl;
    } else {
        std::cout << "not find" << std::endl;
    }

    std::cout << "test fun_minmax 2-----------------------------" << std::endl;
    it = min_element(vec.begin(), vec.end());
    if (it != vec.end()) {
        std::cout << "min: " << *it << std::endl;
    } else {
        std::cout << "not find" << std::endl;
    }
}

void fun_remove() {
    VecInt vec { 1, 3, 9, 5, 8, 2 };

    std::cout << "test fun_remove 1-----------------------------" << std::endl;
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

void fun_sum() {
    VecInt vec { 1, 3, 9, 5, 8, 2 };

    int sum = accumulate(vec.begin(), vec.end(), 0);
    std::cout << "sum is: " << sum << std::endl;
}

void fun_cout() {
    VecInt vec { 1, 3, 9, 5, 8, 2, 2, 2 };

    int cnt = count(vec.begin(), vec.end(), 2);
    std::cout << "have [" << cnt << "] " << "2" << std::endl;

    cnt = count_if(vec.begin(), vec.end(), [](int a){
        return a > 5;
    });
    std::cout << "have [" << cnt << "] " << ">5" << std::endl;
}

void fun_judge() {
    VecInt vec { 1, 3, 8, 10, 20};

    bool b = any_of(vec.begin(), vec.end(), [](int x) {
        return x > 8;
    });
    std::cout << "b is " << b << std::endl;

    b = all_of(vec.begin(), vec.end(), [](int x) {
        return x > 8;
    });
    std::cout << "b is " << b << std::endl;

    b = none_of(vec.begin(), vec.end(), [](int x) {
        return x > 100;
    });
    std::cout << "b is " << b << std::endl;
}

int main(int argc, char* argv[]) {
    fun_find();
    fun_minmax();
    fun_remove();
    fun_sum();
    fun_cout();
    fun_judge();

    return 0;
}