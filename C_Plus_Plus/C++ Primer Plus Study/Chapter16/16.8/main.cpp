//
//  main.cpp
//  16.8
//
//  Created by 谢逊 on 2020/1/17.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Review
{
    string title;
    int rating;
};

bool FillReview(Review & rr);
void ShowReview(const Review & rr);

int main()
{
    Review temp;
    vector<Review> books;
    while (FillReview(temp))
        books.push_back(temp);
    int num = books.size();
    if (num > 0)
    {
        cout << "Thank you. You entered the following:\n" << "Rating\tBook\n";
        
        for (int i = 0; i < num; i++)
            ShowReview(books[i]);
        cout << "Reprising: \n" << "Rating\tBook\n";
        vector<Review>::iterator pr;
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
        vector<Review> oldlist(books);
        
        if ( num > 3)
        {
            books.erase(books.begin() + 1, books.begin() + 2);
            cout << "After erasure:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
            books.insert(books.begin()+1, oldlist.begin(), oldlist.begin() + 2);
            cout << "After insertion:\n";
            for (pr = books.begin(); pr != books.end(); pr++)
                ShowReview(*pr);
        }
        books.swap(oldlist);
        cout << "Swapping oldlist with books:\n";
        for (pr = books.begin(); pr != books.end(); pr++)
            ShowReview(*pr);
    }
    else
        cout << "Nothing entered, nothing gained.\n";
    
    return 0;
}

bool FillReview(Review & rr)
{
    cout << "Enter boook title (quit to quit): ";
    getline(cin, rr.title);
    if (rr.title == "quit")
        return false;
    cout << "Enter book rating: ";
    cin >> rr.rating;
    if (!cin)
        return false;
    while (cin.get() != '\n')
        continue;
    return true;
}

void ShowReview(const Review & rr)
{
    cout << rr.rating << '\t' << rr.title << endl;
}
