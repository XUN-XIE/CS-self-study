//
//  studentc.cpp
//  14.1
//
//  Created by 谢逊 on 2020/1/21.
//  Copyright © 2020 谢逊. All rights reserved.
//

#include "studentc.hpp"

double Student::Average() const
{
    if (socres.size() > 0)
        return scores.sum() / scores.size();
    else
        return 0;
}

const string & Student::Name() const
{
    return name;
}

double & Student::operator[] (int i)
{
    return scores[i];
}
