//
//  main.cpp
//  Chapter3
//
//  Created by 谢逊 on 2020/1/13.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

//int main()
//{
//    cout << "Please enter your first name and your age: ";
//    string first = "???";
//    double age = -1;
//    cin >> first >> age;
//    cout <<"Hello, " << first << "(age month " << age*12 << ")" << endl;
//}


//int main()
//{
//    int a = 5;
//    int b = 7;
//
//    if (a > 4)
//        cout << b;
//
//}

//int main()
//{
//    string previous = " ";
//    string current;
//    while (cin >> current)
//    {
//        if (current == previous)
//            cout << "You print same word twice: " << current << endl;
//    previous = current;
//    }
//
//    return 0;
//}


//int main() {
//    string s = "Goodbye, cruel world! ";
//    cout << s << '\n';
//
//    return 0;
//}


int main() {
    double d = 0;
    while (cin>>d) {
        int i = d;
        char c = i;
        int i2 = c;
        bool B = i2;
        cout << "d==" << d // the original double
                << " i=="<< i
                << " i2==" << i2
                << " char(" << c << ") "
                << "bool(" << B << ")\n";
    }
}
