补充内容

# Static
1. non-static data members每个Object都会创建一份。全名称调用 ClassName::Function(&Object)  &Object相当于this指针，因此针对每个不同的Object有不同的调用不同non-static data member的地址！所以取得不同Object的data
2. static data member相当于和不同的Object脱离（independent）。总体只有一份。static data member用处是：用于存放所有User Object所共有的数据。重点区别！static member没有this pointer！！！所以不能去处理每个不同的Object
3. static member function同理，只能用于处理static data member
4. static member data的定义在类定义体之外！！！使用 Type ClassName::Data = Number; 进行初始化。
5. 加深了对member function的理解。因为可以通过类名进行调用，可以把member function当作普通函数一样使用！只是参数列表里，第一位总是默认会传入Object的this指针！！！




# 构造函数放入private区（Singleton设计模式）
* 目的：只产生一个Object。
* 形式：在Private区里，static创建一个class Object。然后通过public里的一个static mamber function进行调用初始化。从而创建出唯一的Object




# 模版(class Template)
* 模版会造成代码的膨胀，因为不同的类型会有不同的类似代码
* 编译器对function template进行argument deduction*（参数推导）





# namespace(命名空间)
菜鸟教程 [https://www.runoob.com/cplusplus/cpp-namespaces.html]








