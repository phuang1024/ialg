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

#include <iostream>
#include <string>
#include "utils.hpp"
#include "frontend.hpp"


void print_info() {
    std::cout << "IAlg " << VERSION << "\n";
    std::cout << "Built " << __DATE__ << ", " << __TIME__ << "\n";
    std::cout << std::endl;

    #if defined(_WIN32) || defined(_WIN64)
        #warning "You are using an OS (Windows) which contains malware."
        #warning "See https://www.gnu.org/proprietary/malware-microsoft.html"
        std::cout << "WARNING: You are using an OS (Windows) which contains malware." << std::endl;
        std::cout << "See https://www.gnu.org/proprietary/malware-microsoft.html" << std::endl;
    #endif

    #if defined(__APPLE__) || defined(__MACH__)
        #warning "You are using an OS (MacOS) which contains malware."
        #warning "See https://www.gnu.org/proprietary/malware-apple.html"
        std::cout << "WARNING: You are using an OS (MacOS) which contains malware." << std::endl;
        std::cout << "See https://www.gnu.org/proprietary/malware-apple.html" << std::endl;
    #endif
}


void loop() {
    // while (true) {
    //     char a = IAlg::Frontend::getch();
    //     std::cout << "You typed: " << +a << std::endl;
    // }

    int input_num = 0;

    while (true) {
        std::cout << std::endl;

        std::string str;
        if (!IAlg::Frontend::input(str, input_num))
            break;

        if (str.size() > 0) {
            std::cout << str << std::endl;

            input_num++;
        }
    }

    std::cout << std::endl;
}


// #include "number.hpp"
// using IAlg::Number::Integer;

// void int_test() {
//     Integer x(18446744073709551615ULL);
//     Integer y(0);
//     printint(x);
//     printint(y);
//     x.add(y);
//     printint(x);
// }

// void printint(Integer& num) {
//     std::cout << "size: " << num.size() << std::endl;
//     std::cout << "bytes: ";
//     for (int i = 0; i < num.size(); i++)
//         std::cout << +num.bytes()[i] << " ";
//     std::cout << std::endl;
// }


int main() {
    print_info();
    loop();
}
