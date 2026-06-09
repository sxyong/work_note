# 概述

最近在windows上开发，需要写一些bat脚本。每次用的时候都需要重新查一下，因此打算系统的学习一下。  

## 注释

bat 有两种注释，如下：  
```bat
REM 这是一个注释
:: 这是一个注释
```

## 变量

定义变量。  
`set NAME=zhangsan`  

打印变量。  
`echo %NAME%`  

## 参数

%1...%n 分别对应第一个到第n个参数。  
```bat
:: 调用方式
test.bat arg1 arg2 arg3

:: test.bat
echo %1
echo %2 
echo %3

:: 实际输出
arg1
arg2
arg3
```

## if判断

`字符`比较  
```bat
if "%NAME%" == "zhangsan" (
    echo "name is zhangsan"
)

:: 忽略大小写
if /I "abc" == "ABC" (
    echo "same"
)
```

`数字`比较  
```bat
if 8 LSS 3 echo "8 < 3"
```

支持的运算符：  
| 运算符 | 含义 |
| --- | -- |
| EQU | == |
| NEQ | != |
| LSS | <  |
| LEQ | <= |
| GTR | >  |
| GEQ | >= |

`文件、目录`是否存在  
```bat
if exist test.txt (
    echo "file exists"
)

if exist "c:/work" (
    echo "directory exists"
)
```

`变量`是否存在  
```bat
if defined NAME (
    echo "NAME exists"
)
```

## for循环

简单示例  
```bat
for %%i in (a b c) do (
    echo %%i
)

for %%i in (*.txt) do (
    echo %%i
)
```

数字循环  
```bat
:: for /L %%i in (start,step,end) do (...)
for /L %%i (1,1,10) do (
    echo %%i
)
```

## 常用命令

`目录`
```bat
:: 创建
mkdir test

:: 删除
rmdir /s /q test
:: /s 删除整个目录
:: /q 不询问

:: 拷贝目录
xcopy src dst /E /I /Y
```

`文件`
```bat
:: 创建
type nul > test.txt
echo. > test.txt

:: 写文件
echo hello > test.txt

:: 追加写
echo world >> test.txt

:: 读取全部
type test.txt

:: 逐行读取
for /f "delims=" %%i in (test.txt) do (
    echo %%i
)

::拷贝文件
copy a.txt b.txt

:: 移动文件
move a.txt dst\

:: 删除文件
del a.txt
```