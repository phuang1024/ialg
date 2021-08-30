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

#include <vector>
#include <string>
#include "utils.hpp"

namespace IAlg {
namespace Number {

/**
 * Unbounded integer.
 * Most modifier methods (add, subtract) modify the object in place.
 * To create a new object, declare one and use the copy method.
 */
class Integer {
public:
    ~Integer();
    Integer();
    Integer(int n);
    Integer(LL n);
    Integer(ULL n);

    /**
     * Deepcopy this to destination.
     * @param dest destination integer pointer.
     */
    void copy(Integer& dest);

    /**
     * Get the base 10 string representation.
     * @param dest destination std::string pointer.
     */
    void base10(std::string& dest);

    /**
     * Get a pointer to the first element of the internal byte array.
     */
    UCH* bytes();

    /**
     * Number of bytes in the byte array.
     */
    int size();

    /**
     * Set byte array to data from data pointer for size bytes.
     */
    void set(const void* data, const int size);

    /**
     * Add a Number to this object.
     */
    void add(Integer& num);

private:
    /**
     * Resize internal byte array to at least this size.
     * Fills new bytes with 0.
     * Truncates existing bytes if shrinking.
     */
    void _resize(const int size);

    bool _sign;
    std::vector<UCH> _bytes;
};

}  // namespace Number
}  // namespace IAlg
