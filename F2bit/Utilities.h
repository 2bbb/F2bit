//
//  Utilities.h
//  F2bit
//
//  Created by ISHII 2bit on 2015/04/01.
//  Copyright (c) 2015年 bufferRenaiss. All rights reserved.
//

#pragma once

#include "Definitions.h"

template <int size> struct uintN_t;
template <> struct uintN_t<0>;

template <int size>
struct size_calculator {
    static const int value = size <= 8 ? 8 : (size <= 16 ? 16 : (size <= 32 ? 32 : (size <= 64 ? 64 : 0)));
};

template <int size>
struct uintN_t : uintN_t<size_calculator<size>::value> {
    static const typename uintN_t<size_calculator<size>::value>::type mask = (0x1 << size) - 1;
};

template <>
struct uintN_t<8> {
    using type = uint8_t;
    static const int size = 8;
    static const type mask = 0xFF;
};

template <>
struct uintN_t<16> {
    using type = uint16_t;
    static const int size = 16;
    static const type mask = 0xFFFF;
};

template <>
struct uintN_t<32> {
    using type = uint32_t;
    static const int size = 32;
    static const type mask = 0xFFFFFFFF;
};

template <>
struct uintN_t<64> {
    using type = uint64_t;
    static const int size = 64;
    static const type mask = 0xFFFFFFFFFFFFFFFF;
};

template <int size>
uint8_t bit_sum(typename uintN_t<size>::type b) {
    return bit_sum<uintN_t<size>::size>(static_cast<typename uintN_t<size>::type>(b));
}

template <>
uint8_t bit_sum<8>(uint8_t b) {
    b = ((b & 0xAA) >> 1) + (b & 0x55);
    b = ((b & 0xCC) >> 2) + (b & 0x33);
    b = ((b & 0xF0) >> 4) + (b & 0x0F);
    return b & 1;
}

template <>
uint8_t bit_sum<16>(uint16_t b) {
    b = ((b & 0xAAAA) >> 1) + (b & 0x5555);
    b = ((b & 0xCCCC) >> 2) + (b & 0x3333);
    b = ((b & 0xF0F0) >> 4) + (b & 0x0F0F);
    b = ((b & 0xFF00) >> 8) + (b & 0x00FF);
    return b & 1;
}

template <>
uint8_t bit_sum<32>(uint32_t b) {
    b = ((b & 0xAAAAAAAA) >>  1) + (b & 0x55555555);
    b = ((b & 0xCCCCCCCC) >>  2) + (b & 0x33333333);
    b = ((b & 0xF0F0F0F0) >>  4) + (b & 0x0F0F0F0F);
    b = ((b & 0xFF00FF00) >>  8) + (b & 0x00FF00FF);
    b = ((b & 0xFFFF0000) >> 16) + (b & 0x0000FFFF);
    return b & 1;
}

template <>
uint8_t bit_sum<64>(uint64_t b) {
    b = ((b & 0xAAAAAAAAAAAAAAAA) >>  1) + (b & 0x5555555555555555);
    b = ((b & 0xCCCCCCCCCCCCCCCC) >>  2) + (b & 0x3333333333333333);
    b = ((b & 0xF0F0F0F0F0F0F0F0) >>  4) + (b & 0x0F0F0F0F0F0F0F0F);
    b = ((b & 0xFF00FF00FF00FF00) >>  8) + (b & 0x00FF00FF00FF00FF);
    b = ((b & 0xFFFF0000FFFF0000) >> 16) + (b & 0x0000FFFF0000FFFF);
    b = ((b & 0xFFFFFFFF00000000) >> 32) + (b & 0x00000000FFFFFFFF);
    return b & 1;
}
