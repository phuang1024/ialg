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

#include <string>
#include <termios.h>
#include <unistd.h>

namespace IMath {
namespace Frontend {

namespace Color {
    constexpr char RESET[] = "\033[0m";

    constexpr char BOLD[] = "\033[0;1m";
    constexpr char ITALIC[] = "\033[0;3m";
    constexpr char UNDERLINE[] = "\033[0;4m";

    constexpr char GREEN_DARK[] = "\033[38;2;40;140;60m";
    constexpr char GREEN_LIGHT[] = "\033[38;2;120;220;140m";
}

/**
 * Get window width.
 */
int get_winw();

/**
 * Get window height.
 */
int get_winh();

/**
 * Clear the current terminal line.
 */
void clearline();

/**
 * Read character from stdin without waiting for enter.
 */
char getch();

/**
 * Get input from stdin and save to str.
 * n is the input number.
 * For example, if n is 1, it will prompt
 * In [1]:
 */
bool input(std::string& str, const int n);

}  // namespace Frontend
}  // namespace IMath
