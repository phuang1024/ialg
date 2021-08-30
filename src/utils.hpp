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

#pragma once

#define  VERSION  "0.0.1"

#include <vector>

typedef  unsigned char  UCH;
typedef  unsigned int  UINT;
typedef  unsigned short  USH;
typedef  long long  LL;
typedef  unsigned long long  ULL;

/**
 * Check if a target is inside a vector.
 * This uses a vector to prevent size mismatch bugs.
 * @param elements vector of elements.
 * @param target target element.
 */
template<class T>
bool contains(const std::vector<T>& elements, const T& target) {
    for (int i = 0; i < (int)elements.size(); i++) {
        if (elements[i] == target)
            return true;
    }
    return false;
}
