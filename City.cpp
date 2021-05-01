#include "City.hpp"
using namespace pandemic;


c_City::c_City(Color color, const std::vector<City>& neighbours) : _color(color), _research_station(false), _neighbours(neighbours){//
    // for(City c : neighbours){
    //     this->_neighbours.push_back(c);
    // }
    
}
c_City::c_City(){};
// c_City::c_City(Color color, std::vector<City> neighbours) : _color(color), _research_station(false){
//     for(City i : neighbours){
//         this->_neighbours.push_back(i);
//     }
// }
