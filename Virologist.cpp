
#include "Virologist.hpp"
using namespace pandemic;

Virologist::Virologist(Board &board, City city) : Player(board, city){};

std::string Virologist::role()
{
    return std::string("Virologist");
}

Player& Virologist::treat(City city)
{
    if (this->_currentCity != city)
    {
        bool deleted = false;
        for (std::vector<City>::iterator i = (this->_cards.end() - 1); i != (this->_cards.begin() - 1); i--)
        {
            if (*i == city)
            {
                this->_cards.erase(i);
                deleted = true;
                break;
            }
        }
        if (!deleted)
        {
            throw std::invalid_argument("Cant treat this city. you need to be at this city to treat it.");
        }
    }
    if (this->_board._cities.at(city)._cubes == 0)
    {
        throw std::invalid_argument("Cant treat this city. there are no disease cubes at this city.");
    }
    if (this->_board._cures.at(this->_board._cities.at(city)._color))
    {
        this->_board[city] = 0;
        return *this;
    }
    this->_board[city]--;
    return *this;
}