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

#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace IMath {
namespace Lexer {

const std::vector<char> STRING = {'\"'};
const std::vector<char> BACKSLASH = {'\"', '\'', '\\', 'n', 'b'};   // backslash escapes

/**
 * Dump colored text to out.
 */
void dump(std::ostream& out, std::string str);

}  // namespace Lexer
}  // namespace IMath
