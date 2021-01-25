# OOP OOD(Obejct Oriented Design)

* Inheritance（继承）
* Composition（复合）
* Delegation（委托）
### 明确一个概念！OOP并不是只有继承关系，上述三个关系都是OOP！


# Composition, 表示 has-a
* 表示一个class里面有！另外一（多）个其他class（has-a/N）
* 例子：标准库的 queue 内部直接储存了一个 deque 类型。然后所有的public member functins都是直接调用 deque 的方法完成操作的，而不需要自己重写操作。表示 queue has a deque
* Adaptor模式，在已有功能的class基础上，衍生出一个只需稍微改造即可完成功能的衍生类。类似于包含关系延伸出一个子集
* 也可以理解为 Container 包含一个 Component 的关系

#### 用流程图表示class之间的关系！！！

### Composition下的构造和析构函数关系
1. 构造由内而外，先构造coponent，再构造container的其他data members
2. 析构由外而内，先释放container的data members，再释放coponent的内存
3. 编译器可以自动完成 Composition 关系的 Component 的构造函数和析构函数调用（注意区分继承关系，继承关系要设计者自己调用 父类的构造和析构函数）





# Delegation（委托），表示Coposition by reference
* 表示用 指针 指向component，而不是直接创造一个coponent存放在container里。即使用指针实现的Coposition关系。（为什么叫by reference，因为学术届，没有by pointer，所以by reference即表达了用指针代理coponent）
* 此时，component的创建是在container被使用时才会创建，而不是container被创建就创建了component
* pointer to implementation/ Handle(代表container) with Body(代表component)模式。优点是：component的改变不会影响container。编译防火墙，Body的修改不会改变Handle的使用，所以改变Body时，编译器只需要重新编译Body部分而不用编译Handle部分
* 可以实现reference counting共享特性。多个指针指向同一份内容，可以节省内存。如果想改变其中一个指针指向的内容，不能影响其他指针，就新创建一份内容，给这个指针进行改变






# Inheritance（继承），表示is-a
* 父类的数据被完整继承下来到子类！
* 父类的函数，子类都可以使用！

#### 继承关系下的构造和析构函数
* 子类的data member包含有父类的data member
* 构造函数也是由内（父）而外（子），但是要设计者显式调用
* 析构函数也是由外（子）而内（父），这里不一样了，父类必须是虚函数！！！见C++ Primer详细讲解（牵扯到dynamic binding）

#### Inheritance with virtual fucntions（虚函数）
* *这里的override（覆盖）是专业术语，专门针对virtual function的，不能用overload（重载）。还要区分overwrite（重写）见网站 [https://blog.csdn.net/chen134225/article/details/81188476]*
* non-virtual函数：不希望子类覆盖（override）父类的函数
* virtual函数：希望子类覆盖（override）父类的函数
* pure virtual函数：希望子类一定要覆盖（override）的函数（父类中添加该函数，没有默认定义）。只用于抽象基类



## template method（设计模式），这里的template不是C++的模版
调用父类的一个function，这个function里面调用了一个virtual function，父类没有实现，而去调用子类的这个virtual function的过程。(过程和合理性，注意最后一步是合理的，相当于this->VirtualFunction，因为传入的this指针是子类的对象！所以可以使用子类的虚函数）





## Inheritance + Composition 关系下的构造和析构(习题)
适用于延迟开发的设计模式
1. 子类具有composition时
* 构造函数先后：先构造父类的data member，然后是component的构造，最后是其他子类数据
* 析构函数：与上述相反
2. 父类具有composition



## Delegation + Inheritance 关系(Observer设计模式)
适用于GUI的设计模式



最著名的二十三个设计模式，课程讲了最简单的三个和其组合
