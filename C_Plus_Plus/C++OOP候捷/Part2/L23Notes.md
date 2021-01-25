# conversion function
函数形式
operator type() const

1. 没有返回类型，返回的类型就是type，但是不用显式写出来返回类型了
2. 通常加const，除非内部改变了data members！
3. 编译器会在任何需要将Object转换为type类型时，会自动调用 operator type函数进行转换





# non-explicit-one-argument-constructor
1. 因为non-explicit，可以在发生构造时的，隐式转换
2. 组合重载运算符 （+， - etc.）。可以实现出conversion function的功能！但是调用了两个function。第一步先查找对应的operator function，然后发现第二个参数是built-in type，可以利用 constructor隐式转换为 class Object 进行计算！！！
#### 小重点！上述两个function不能同时共存，因为程序产生了二义性。解决办法是给constructor 加上 explicit 关键字取消隐式转换！！！或者取消掉conversion function（不推荐）
3. 一般explicit关键字用在构造函数的前面（其他特殊情况，在模版里会有一个小例子使用）







