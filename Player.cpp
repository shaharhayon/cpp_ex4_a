
#include "Player.hpp"
using namespace pandemic;
Player::Player(Board& board, City city) : _board(board), _currentCity(city) {}

Player& Player::take_card(City city)
{
    this->_cards.push_back(city);
    return *this;
}

Player& Player::drive(City city)
{
    if (_board.is_connected(this->_currentCity, city))
    {
        this->_currentCity = city;
        return *this;
    }
    throw std::invalid_argument("These cities are not connected.");
}

Player& Player::fly_direct(City city)
{
    for (std::vector<City>::iterator i = this->_cards.begin(); i != this->_cards.end(); i++)
    {
        if (*i == city)
        {
            this->_currentCity = city;
            this->_cards.erase(i);
            return *this;
        }
    }
    throw std::invalid_argument("Cant fly directly to the requested city, missing destination city card.");
}

Player& Player::fly_charter(City city)
{
    for (std::vector<City>::iterator i = this->_cards.begin(); i != this->_cards.end(); i++)
    {
        if (*i == this->_currentCity)
        {
            this->_currentCity = city;
            this->_cards.erase(i);
            return *this;
        }
    }
    throw std::invalid_argument("Cant fly charter to the requested city, missing current city card.");
}

Player& Player::fly_shuttle(City city){
        if (this->_board._cities.at(this->_currentCity)._research_station && 
            this->_board._cities.at(city)._research_station)
        {
            this->_currentCity = city;
            return *this;
        }
    throw std::invalid_argument("Cant fly shuttle to the requested city, source or destination city doesnt have a research station.");
}

Player& Player::build(){
    if(this->_board._cities.at(this->_currentCity)._research_station){
        throw std::invalid_argument("Cant build research station. this city already has one.");
        return *this;
    }
    for (std::vector<City>::iterator i = this->_cards.begin(); i != this->_cards.end(); i++){
        if(*i == this->_currentCity){
            this->_board._cities.at(this->_currentCity)._research_station = true;
            this->_cards.erase(i);
            return *this;
        }
    }
    throw std::invalid_argument("Cant build research station. you dont have the required card.");
}

Player& Player::discover_cure(Color color){
    if(!(this->_board._cities.at(this->_currentCity)._research_station)){
        throw std::invalid_argument("Cant discover cure for this city. this city doesn't have a research station.");
    }
    if(this->num_of_cards(color) < 5){
        throw std::invalid_argument("Cant discover cure for this city. you dont have enough cards of this color.");
    }
    int removed = 0;
    for (std::vector<City>::iterator i = (this->_cards.end() - 1); i != (this->_cards.begin() - 1); i--)
    {
        if (this->_board._cities.at(*i)._color == color)
        {
            this->_cards.erase(i);
            removed++;
        }
        if(removed == 5){
            break;
        }
    }
    this->_board._cures.at(color) = true;
    return *this;
}

Player& Player::treat(City city){
    if(this->_currentCity != city){
        throw std::invalid_argument("Cant treat this city. you need to be at this city to treat it.");
    }
    if(this->_board._cities.at(this->_currentCity)._cubes == 0){
        throw std::invalid_argument("Cant treat this city. there are no disease cubes at this city.");
    }
    if(this->_board._cures.at(this->_board._cities.at(city)._color)){
        this->_board[this->_currentCity] = 0;
        return *this;
    }
    this->_board[this->_currentCity]--;
    return *this;
}


int Player::num_of_cards(Color color){
    int count = 0;
    for(City card : this->_cards){
        if(this->_board._cities.at(card)._color == color){
            count++;
        }
    }
    return count;
}