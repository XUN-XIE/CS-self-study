# reference
1. JAVA里面所有的变量都是reference
2. reference在第一次被赋值为一个对象的引用后，后续的赋值都是当作别名，来修改第一次引用的对象的内容。所以reference的后续赋值和第一次赋值要区分！！！只能引用第一个对象
3. 对reference取地址，得到的就是别名对象的地址
4. reference本质就是一个漂亮的指针
5. reference一般用在参数和返回值的传递上！一般不会再外部声明reference类型！！！
6. 出现一个小问题，就是传递参数时，如果重载一个函数，两个参数列表，一个列表使用pass by reference，一个pass by value。这两者对于编译器是二义性的，ambiguity
7. member function 尾部的const关键字属不属于函数签名的一部分（对编译器用来识别不同的函数重载）？答案是：是的！











