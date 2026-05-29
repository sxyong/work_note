#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using ofstream = std::ofstream;
using ifstream = std::ifstream;

int fun_stream() {
    // write test
    ofstream f("test.data");
    if (!f) {
        std::cout << "open failed" << std::endl;
        return -1;
    }

    f << "test write file" << std::endl;
    f.close();

    //read test
    ifstream f2("test.data");
    if (!f2) {
        std::cout << "open failed" << std::endl;
        return -2;
    }

    std::string str;
    if (!getline(f2, str)) {
        std::cout << "getline failed" << std::endl;
        return -3;
    }

    std::cout << "read:" << str << std::endl;

    // istreamstream test
    std::istringstream ss(str);
    std::string s1, s2, s3;

    if (!(ss >> s1 >> s2 >> s3)) {
        std::cout << "string parse failed" <<std::endl;
        return -4;
    }

    std::cout << s1 << " " << s2 << " " << s3 << std::endl;
    return 0;
}

int main(int argc, char* argv[]) {
    fun_stream();
    return 0;
}