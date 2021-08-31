//
//  IAlg
//  Interactive mathematical computing.
//  Copyright Patrick Huang 2021
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#include <algorithm>
#include <cstring>
#include <iostream>
#include "number.hpp"

/**
 * Add two base10 vector chars and store result in first.
 * Used by Integer::base10
 */
void add_base10(std::vector<char>& v1, std::vector<char>& v2) {
    const int other_size = v2.size();
    const int curr_size = v1.size();
    const int new_size = std::max(other_size, curr_size) + 1;
    if (new_size > curr_size)
        v1.resize(new_size, 0);

    int remain = 0;
    for (int i = 0; i < new_size-1; i++) {
        const UCH other_byte = (i < other_size) ? v2[i] : 0;
        const int sum = other_byte + v1[i] + remain;
        v1[i] = sum % 10;
        remain = sum / 10;
    }

    if (remain != 0)
        v1[new_size-1] = remain;
}

namespace IAlg {
namespace Number {

Integer::~Integer() {
}

Integer::Integer() {
    _bytes.resize(1);
    _bytes[0] = 0;
}

Integer::Integer(int n) {
    set(&n, sizeof(n));
}

Integer::Integer(LL n) {
    set(&n, sizeof(n));
}

Integer::Integer(ULL n) {
    set(&n, sizeof(n));
}

void Integer::copy(Integer& dest) {
    dest._sign = _sign;

    const int size = _bytes.size();
    dest._bytes.resize(size);
    memcpy(&dest._bytes[0], &_bytes[0], sizeof(UCH) * size);
}

void Integer::shrink() {
    int pos = size() - 1;   // Position of last nonzero byte.
    while (_bytes[pos] == 0)
        pos--;

    _resize(pos+1);
}

void Integer::base10(std::string& dest) {
    dest.resize(0);

    // std::vector<char> total = {0};
    // std::vector<char> multiplier = {1};

    // for (int i = 0; i < size(); i++) {
    //     // Multiply the multiplier by 256 each iter.
    //     std::vector<char> prev = multiplier;
    //     for (int k = 0; k < 256; k++)
    //         add_base10(multiplier, prev);
    // }
}

UCH* Integer::bytes() {
    return &_bytes[0];
}

int Integer::size() {
    return _bytes.size();
}

void Integer::set(const void* data, const int size, const int offset) {
    _resize(size);
    memcpy(&_bytes[offset], data, size);
}

void Integer::add(Integer& num) {
    const int other_size = num._bytes.size();
    const int curr_size = _bytes.size();
    const int new_size = std::max(other_size, curr_size) + 1;
    if (new_size > curr_size)
        _resize(new_size);

    int remain = 0;
    for (int i = 0; i < new_size-1; i++) {
        const UCH other_byte = (i < other_size) ? num._bytes[i] : 0;
        const int sum = other_byte + _bytes[i] + remain;
        _bytes[i] = sum & 255;
        remain = sum >> 8;
    }

    if (remain != 0)
        _bytes[new_size-1] = remain;
}

void Integer::_resize(const int size) {
    _bytes.resize(size, 0);
}

}  // namespace Number
}  // namespace IAlg
