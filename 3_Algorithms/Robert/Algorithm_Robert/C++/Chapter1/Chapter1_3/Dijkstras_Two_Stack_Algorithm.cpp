#include "INCLUDE.hpp"

// Page 129
double evaluate(string & str);

int main()
{
    // 必须是完全带括号的，不然最后几个符号无法遇见右括号进行返回计算
    string expression("( ( 3 + 4 ) * 5 )");
    double result = evaluate(expression);
    
    cout << result << endl;

    string expression1("( sqrt ( ( 7 * 7 ) ) * 5 )");
    double result1 = evaluate(expression1);

    cout << result1 << endl;

    return 0;    
}

double evaluate(string & str)
{
    stack<string> ops;
    stack<double> vals;

    stringstream read_word(str);
    string word;
    vector<string> operators = {"+", "-", "*", "/", "sqrt"};

    while (read_word >> word)
    {
        if ( word == "(" ) ;
        else if ( find( operators.cbegin(), operators.cend() ,word) != operators.cend() ) ops.push(word);
        else if (word == ")" )
        {
            // C++ stack 只能取得top的reference，然后pop只能删除，分开使用
            // 尽管一赋值就进行了 pop操作，但是值没有被释放空间，还可以使用
            // 加深C++ reference的理解，这里的两个定义 都没有！加& reference声明符号
            // 所以我们是使用了 string 和 double 直接存储了两个stack top索引所指向的值
            // 就是进行了赋值操作，而不是进行了reference assignment操作。所以pop 不会删除op和val的值
            string op = ops.top(); ops.pop();
            double val = vals.top(); vals.pop();
            if (op == "+") vals.top() += val;
            else if ( op == "-" ) vals.top() -= val;
            else if ( op == "*" ) vals.top() *= val;
            else if ( op == "/" ) vals.top() /= val;

            // 因为C++ stack.top() 可以直接索引，进行修改。所以上述代码与书中不一样，因此缺少了一个push
            // 所以特别关注 sqrt 需要 push 回去这个取出来的值
            else if ( op == "sqrt" ) { vals.push( sqrt(val) ); }
        }
        else
            vals.push(stod(word));
    }

    return vals.top();
}