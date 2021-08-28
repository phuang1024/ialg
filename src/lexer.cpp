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

#include <iostream>
#include <string>
#include "frontend.hpp"
#include "lexer.hpp"
#include "utils.hpp"

using namespace IMath::Frontend;

namespace IMath {
namespace Lexer {

void dump(std::ostream& out, std::string str) {
    const int size = str.size();

    bool in_string = false;
    int i = 0;

    while (i < size) {
        std::cout << Color::RESET;
        const char ch = str[i];

        if (contains<char>(STRING, ch)) {
            in_string = !in_string;
            std::cout << Color::STRING << ch;
        } else if (in_string && ch == '\\') {
            if (i < size-1 && contains<char>(BACKSLASH, str[i+1])) {
                std::cout << Color::BOLD << Color::STRING;
                std::cout << ch << str[i+1];
                i++;
            } else {
                std::cout << Color::STRING << ch;
            }
        } else {
            std::cout << (in_string ? Color::STRING : Color::RESET);
            std::cout << ch;
        }

        i++;
    }

    std::cout << std::flush;
}

}  // namespace Lexer
}  // namespace IMath
