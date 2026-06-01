# PlantUML

PlantUML 是一个用于创建图形化代码的工具，它支持多种图类型，如类图、顺序图、活动图等。PlantUML 使用文本描述图，然后通过 PlantUML 解释器将其转换为图形。

## 安装 PlantUML

本文只介绍在vscode中使用PlantUML，其他平台的安装方法可以参考[PlantUML官方文档](https://plantuml.com/zh/install)。

### 在vscode中安装 PlantUML

1. 打开vscode，点击左侧的扩展图标（四个方块组成的图标）。
2. 在扩展市场中搜索“PlantUML”，找到“PlantUML”扩展，点击安装。
3. 安装完成后，点击左侧的扩展图标，找到“PlantUML”，点击打开设置。
4. 在设置中，找到“PlantUML: Enable PlantUML”选项，勾选上。

### 安装graphviz

```
# windows
choco install graphviz

# linux
sudo apt-get install graphviz
```

## 使用 PlantUML

PlantUML 的类图语法非常接近自然语言，核心结构如下：
```
@startuml

class 类名 {
    属性
    方法
}

@enduml
```

只需创建一个文件，扩展名为 `.puml`，编写PlantUML 代码，然后`alt+d`即可展示。  

属性语法：`可见性 名称 : 类型`  
```
class Person {
    - name : string
    - age : int
}
```

方法语法：`可见性 方法名(参数) : 返回值`  
```
class Person {
    + getName() : string
    + setName(name : string) : void
}
```

可见性：  
```
+ public
- private
# protected
```

类图最重要的就是类之间的关系，PlantUML 支持以下关系：  
```
classA -- classB: 关联
classA ..> classB: 依赖
classA --|> classB: 继承
classA o-- classB：聚合
classA *--> classB: 组合
```

PlantUml 还支持布局。可以通过在类之间关系中添加`方向`关键字来指定布局。  
```
classA .up.> classB: 依赖  // 支持up,down,left,right
```