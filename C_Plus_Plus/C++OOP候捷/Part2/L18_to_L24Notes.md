# this
* this 对理解类调用，继承类之间的切换调用很关键
* template method里，子类对象调用一个父类的非虚函数时，非虚函数内部有一个虚函函！这时调用的该虚函数其实是子类对象的虚函数！因为 this 指针！this指针在member function调用时，是当作参数传入的，所以虚函数是 this->虚函数，而传入的this是对应于子类的对象，所以这个虚函数当然是子类的虚函数调用！



# Dynamic Binding
把汇编代码拿出来说事儿了！！！




# 谈谈const
1.	const / non-const class Object （调用下面一行）
	const / non-const class member function
	只有一种情况不可以调用，就是const class Object 不能调用 non-const class member function。其他的三种组合情况都是可以的！

2. const / non-const class member function是两个function！编译器可以识别（因为函数签名不同）
3. 所以设计函数的时候，要注意是否需要写两个版本，或者应该使用哪个单独版本！！！
4. 当 const / non-const 两版本的函数同时存在时，Object只能对应的函数。（不能存在non-const Object 调用 const member function的情况）




# new 和 delete
最后五节课都是讲这些的，没有看完



