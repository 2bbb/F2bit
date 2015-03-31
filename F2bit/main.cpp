//
//  main.cpp
//  F2bit
//
//  Created by ISHII 2bit on 2015/04/01.
//  Copyright (c) 2015年 bufferRenaiss. All rights reserved.
//

#include <iostream>

#include "F2bit.h"

using namespace std;
int main(int argc, char *argv[]) {
    F2bit<62> b1(0b1111), b2(0b1111);
    cout << F2bit<35>::size << endl;
    cout << (b1 + b2) << endl;
    cout << (b1 * b2) << endl;
    
    return 0;
}