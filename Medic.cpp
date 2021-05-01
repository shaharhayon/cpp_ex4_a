
#include "Medic.hpp"
using namespace pandemic;

Medic::Medic(Board& board, City city) : Player(board, city){};

std::string Medic::role()
{
    return std::string("Medic");
}

Player& Medic::drive(City city)
{
    this->default_cure();
    Player::drive(city);
    this->default_cure();
    return *this;
}

Player& Medic::fly_direct(City city)
{
    this->default_cure();
    Player::fly_direct(city);
    this->default_cure();
    return *this;
}

Player& Medic::fly_charter(City city)
{
    this->default_cure();
    Player::fly_charter(city);
    this->default_cure();
    return *this;
}

Player& Medic::fly_shuttle(City city)
{
    this->default_cure();
    Player::fly_shuttle(city);
    this->default_cure();
    return *this;
}

Player& Medic::build()
{
    Player::build();
    this->default_cure();
    return *this;
}

Player& Medic::discover_cure(Color color)
{
    Player::discover_cure(color);
    this->default_cure();
    return *this;
}

Player& Medic::treat(City city)
{
    if (this->_currentCity != city)
    {
        throw std::invalid_argument("Cant treat this city. you need to be at this city to treat it.");
    }
    if (this->_board._cities.at(this->_currentCity)._cubes == 0)
    {
        throw std::invalid_argument("Cant treat this city. there are no disease cubes at this city.");
    }
    this->_board[this->_currentCity] = 0;
    return *this;
}

void Medic::default_cure()
{
    if (this->_board._cures.at(this->_board._cities.at(this->_currentCity)._color))
    {
        this->_board[this->_currentCity] = 0;
    }
}