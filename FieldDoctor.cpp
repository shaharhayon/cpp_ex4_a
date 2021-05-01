
#include "FieldDoctor.hpp"
using namespace pandemic;

FieldDoctor::FieldDoctor(Board& board, City city) : Player(board, city){}
std::string FieldDoctor::role()
{
    return std::string("Field Doctor");
}

Player& FieldDoctor::treat(City city)
{
    City c = this->_currentCity;
    if (this->_currentCity != city)
    {
        c = city;
        if (!(this->_board.is_connected(this->_currentCity, city)))
        {
            throw std::invalid_argument("Cant treat this city. you need to be at this city or at a connected city to treat it.");
        }
    }
    if (this->_board._cities.at(c)._cubes == 0)
    {
        throw std::invalid_argument("Cant treat this city. there are no disease cubes at this city.");
    }
    if (this->_board._cures.at(this->_board._cities.at(c)._color))
    {
        this->_board[c] = 0;
        return *this;
    }
    this->_board[c]--;
    return *this;
}