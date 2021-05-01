
#include "OperationsExpert.hpp"
using namespace pandemic;

OperationsExpert::OperationsExpert(Board& board, City city) : Player(board, city){

}
std::string OperationsExpert::role(){
    return std::string("Operations Expert");
}

Player& OperationsExpert::build(){
    if(this->_board._cities.at(this->_currentCity)._research_station){
        throw std::invalid_argument("Cant build research station. this city already has one.");
    }
    this->_board._cities.at(this->_currentCity)._research_station = true;
    return *this;
}