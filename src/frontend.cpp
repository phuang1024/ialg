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

namespace IMath {
namespace Frontend {

bool input(std::string& str, const int n) {
    std::cout << Color::GREEN_DARK << "In [";
    std::cout << Color::GREEN_LIGHT << n;
    std::cout << Color::GREEN_DARK << "]: ";
    std::cout << Color::RESET << std::flush;

    return (bool)getline(std::cin, str);
}

}  // namespace Frontend
}  // namespace IMath
