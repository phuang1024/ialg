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

namespace IMath {
namespace Frontend {

namespace Color {
    constexpr char RESET[] = "\033[0m";

    constexpr char BOLD[] = "\033[0;1m";
    constexpr char ITALIC[] = "\033[0;3m";
    constexpr char UNDERLINE[] = "\033[0;4m";

    constexpr char GREEN_DARK[] = "\033[38;2;80;140;100m";
    constexpr char GREEN_LIGHT[] = "\033[38;2;120;180;140m";
}

}  // namespace Frontend
}  // namespace IMath