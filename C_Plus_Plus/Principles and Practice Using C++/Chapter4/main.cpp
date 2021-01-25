//
//  main.cpp
//  Chapter4
//
//  Created by 谢逊 on 2020/1/13.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>


using namespace std;

//constexpr double pi = 3.1415926;
//
//int main()
//{
//    char a = 'a';
//    char c = a + 2;
//    cout << a++ << "  " << ++a << " " << c << endl;
//
//    return 0;
//}

//int main() {
//    constexpr double cm_per_inch = 2.54;
//    double length = 1;
//// number of centimeters in // an inch
//// length in inches or // centimeters
//    char unit = 0;
//    cout<< "Please enter a length followed by a unit (c or i):\n"; cin >> length >> unit;
//    if (unit == 'i')
//    {
//        cout << length << "in == " << cm_per_inch*length << "cm\n";
//        cout << "xiexun" << endl;
//    }
//    else if (unit == 'c')
//        cout << length << "cm == " << length/cm_per_inch << "in\n";
//    else
//        cout << "Sorry, I don't know a unit called '" << unit << "'\n";
//
//    return 0;
//}

//int main() {
//    constexpr double cm_per_inch = 2.54;
//    double length = 1;
//
//
//    char unit = 0;
//    cout<< "Please enter a length followed by a unit (c or i):\n";
//    cin >> length >> unit;
//
//
//    switch (unit){
//        case 'i':
//            cout << length << "in == " << cm_per_inch*length << "cm\n";
//            break;
//
//        case 'c':
//            cout << length << "cm == " << length/cm_per_inch << "in\n";
//            break;
//
//        default:
//            cout << "Sorry, I don't know a unit called '" << unit << "'\n";
//            break;
//    }
//
//    return 0;
//}

//int main()
//{
//    cout << "Please enter a digit\n";
//    char a;
//    cin >> a;
//
//    switch (a){
//        case'0': case'2' : case'4': case'6': case '8':
//            cout << "is even\n";
//            break;
//        case '1': case '3': case '5': case '7': case '9':
//            cout << "is odd\n";
//            break;
//        default:
//            cout << "is not a digit\n";
//            break;
//    }
//}

//int main()
//{
//    cout << "Enter the currency you want to convert to dollars: ";
//
//    string currency;
//    double value;
//    cin >> currency;
//
//    cout << "Enter the value you want to convert to dollars: ";
//    cin >> value;
//
//    if (currency == "yen")
//        cout << value << " " << currency << " is euqal to " << value * 0.009104 << " dollars"<< endl;
//    else if (currency == "euros")
//        cout << value << " " << currency << " is euqal to " << value * 1.1123 << " dollars"<< endl;
//    else if (currency == "pounds")
//        cout << value << " " << currency << " is euqal to " << value * 1.2968 << " dollars"<< endl;
//    else
//        cout << "Sorry! Your input is not in working range.";
//
//    return 0;
//}

//int main()
//{
//    cout << "Enter the currency you want to convert to dollars ('y', 'e', 'p' represent yen, euros, pounds separately): ";
//
//    char currency;
//    double value;
//    cin >> currency;
//
//    cout << "Enter the value you want to convert to dollars: ";
//    cin >> value;
//
//    switch (currency){
//        case 'y':
//            cout << value << " " << currency << " is euqal to " << value * 0.009104 << " dollars"<< endl;
//            break;
//        case 'e':
//            cout << value << " " << currency << " is euqal to " << value * 1.1123 << " dollars"<< endl;
//            break;
//        case 'p':
//            cout << value << " " << currency << " is euqal to " << value * 1.2968 << " dollars"<< endl;
//            break;
//        default:
//            cout << "Sorry! Your input is not in working range.";
//            break;
//
//    }
//    return 0;
//}

//int main()
//{
//    int i = 0;
//    while (i < 100){
//        cout <<  i << "\t" << i * i << "\n";
//        i++;
//    }
//}

//int main()
//{
//    char a = 'a';
//
//    while (int(a) < int('z') + 1)
//    {
//        cout << a << "\t" << int(a) << "\n";
//        a++;
//    }
//}

//int main()
//{
//    for (int i = 0; i < 100; i++)
//        cout << i << '\t' << i*i << '\n';
//}

//int main()
//{
//    char a = 'A';
//    for (int i = 0; i<26; i++)
//        cout << char(a+i) << '\t' << a+i << '\n';
//}
//int square(int);
//
//int square(int x)
//{
//    int sum = 0;
//    for (int i = 0; i < x; i++)
//        sum += x;
//    return sum;
//}
//
//int main()
//{
//    cout << square(10) << endl;
//}
//

//int main()
//{
//    vector<int> v;
//    for (int i=0; i<10; ++i)
//        v.push_back(i);
//    for (int x:v)
//        cout << v[x] << '\n';
//}


//int main()
//{
//    vector<double> temps;
//    for (double temp; cin >>temp;)
//        temps.push_back(temp);
//
//    double sum = 0;
//    for (int x: temps) sum += x;
//    cout << "Average temperature is " << sum / temps.size() << endl;
//
//    sort(&temps[0], &temps[temps.size()]);
//    cout << "Median temperature: " << temps[temps.size()/2] << endl;
//}


//int main()
//{
//    vector<string> words;
//    for (string temp; cin>>temp;)
//        words.push_back(temp);
//    cout << "Number of words: " << words.size() << endl;
//
//    sort(&words[0], &words[words.size()]);
//
//    for (int i=0; i < words.size(); ++i)
//        if (i == 0 || words[i-1] != words[i])
//            cout << words[i] << endl;
//}

//int main()
//{
//    vector<string> words;
//    string disliked = "Broccoli";
//
//    for (string temp; cin >> temp;)
//        words.push_back(temp);
//
//    sort(&words[0], &words[words.size()]);
//
//    for (string x: words)
//        if (x == disliked)
//            cout << "I encounter the disliked" << endl;
//}

//int main()
//{
//    double i;
//    string unit;
//
//    cin >> i >> unit;
//    cout << ++i << endl;
//    cout << unit << endl;
//}

int main()
{
    vector<double> v = {3,2,1};
    cout << v.size() << endl;
    sort(&v[0], &v[v.size()]);
    for (double x: v)
        cout << x << endl;
}
