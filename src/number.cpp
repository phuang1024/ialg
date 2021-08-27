//
//  IMath
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
#include "number.hpp"

namespace IMath {
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

void Integer::copy(Integer* dest) {
    dest->_sign = _sign;

    const int size = _bytes.size();
    dest->_bytes.resize(size);
    memcpy(&dest->_bytes[0], &_bytes[0], sizeof(UCH) * size);
}

void Integer::base10(std::string* dest) {
    Integer copied;
    copy(&copied);

    dest->resize(0);
}

UCH* Integer::bytes() {
    return &_bytes[0];
}

int Integer::size() {
    return _bytes.size();
}

void Integer::set(const void* data, const int size) {
    _resize(size);
    memcpy(&_bytes[0], data, size);
}

void Integer::add(Integer* num) {
    const int curr_size = _bytes.size();
    const int new_size = std::max((int)num->_bytes.size(), curr_size);
    if (new_size > curr_size)
        _resize(new_size+1);

    int remain = 0;
    for (int i = 0; i < new_size; i++) {
        const int sum = num->_bytes[i] + _bytes[i] + remain;
        _bytes[i] = sum & 255;
        remain = sum >> 8;
    }

    if (remain != 0)
        _bytes[new_size-1] = remain;
}

void Integer::_resize(const int size) {
    const int current = _bytes.size();

    _bytes.resize(size);
    if (current < size)
        memset((void*)(&_bytes[0]+current), 0, size-current);
}

}  // namespace Number
}  // namespace IMath
