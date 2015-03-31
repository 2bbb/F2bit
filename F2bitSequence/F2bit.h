//
//  F2bit.h
//  F2bit
//
//  Created by ISHII 2bit on 2015/04/01.
//  Copyright (c) 2015年 bufferRenaiss. All rights reserved.
//

#pragma once

#include "Definitions.h"
#include "Utilities.h"

template <int s>
struct F2bit {
    using T = uintN_t<s>;
    using type = typename uintN_t<s>::type;
    static const int size = uintN_t<s>::size;
    
    F2bit(type v) : v(v & T::mask) {};
    
    F2bit &operator=(type v) {
        this->v = v & T::mask;
    }
    
    F2bit operator|(const F2bit &b) { return F2bit(this->v | b.v); }
    F2bit operator|=(const F2bit &b) {
        this->v |= b.v;
        return *this;
    }
    
    F2bit operator^(const F2bit &b) { return F2bit(this->v ^ b.v); }
    F2bit operator^=(const F2bit &b) {
        this->v ^= b.v;
        return *this;
    }
    
    F2bit operator&(const F2bit &b) { return F2bit(this->v & b.v); }
    F2bit operator&=(const F2bit &b) {
        this->v &= b.v;
        return *this;
    }
    
    F2bit operator+(const F2bit &b) { return F2bit(this->v ^ b.v); }
    F2bit &operator+=(const F2bit &b) {
        this->v ^= b;
        return *this;
    }
    
    int operator*(const F2bit &b) { return bit_sum<s>(this->v & b.v); }
    
    operator type() { return v; }
    
    type v;
};