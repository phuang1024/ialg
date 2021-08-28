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
#include <sys/ioctl.h>
#include "frontend.hpp"

using namespace IMath::Frontend::Color;

namespace IMath {
namespace Frontend {

int get_winw() {
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_col;
}

int get_winh() {
    winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    return w.ws_row;
}

void clearline() {
    const int width = get_winw();
    std::cout << "\r";
    for (int i = 0; i < width; i++)
        std::cout << " ";
    std::cout << "\r" << std::flush;
}

char getch() {
    char buf = 0;
    struct termios old = {0};
    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");

    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");

    if (read(0, &buf, 1) < 0)
        perror ("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror ("tcsetattr ~ICANON");

    return buf;
}

bool input(std::string& str, const int n) {
    str.resize(0);
    str.reserve(100);

    bool ctrl_d = false;
    while (true) {
        clearline();

        std::cout << RESET << GREEN_DARK << "In [";
        std::cout << RESET << BOLD << GREEN_LIGHT << n;
        std::cout << RESET << GREEN_DARK << "]: ";
        std::cout << RESET;

        std::cout << str << std::flush;

        const char ch = getch();
        if (ch == 10) {
            break;
        } else if (ch == 4) {
            ctrl_d = true;
            break;
        } else if (ch == 127) {
            if (str.size() > 0)
                str.resize(str.size()-1);
        } else {
            str.push_back(ch);
        }
    }

    std::cout << std::endl;
    return !ctrl_d;
}

}  // namespace Frontend
}  // namespace IMath
