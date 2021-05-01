#pragma once
#include <ostream>
#include <array>
#include <map>
#include "City.hpp"

namespace pandemic
{
    class Board
    {
    private:
        std::map<int, std::string> _enum_to_string;

    public:
        Board();
        int &operator[](City city);
        bool is_clean();
        friend std::ostream &operator<<(std::ostream &os, const Board &board);
        bool is_connected(City src, City dst);
        std::array<c_City, NUM_OF_CITIES> _cities;
        std::array<bool, 4> _cures = {false};
    };
}