
#include "Board.hpp"


using namespace std;
using namespace pandemic;

c_City::c_City(Color color, const std::vector<City>& neighbours) : _color(color), _cubes(0), _research_station(false), _neighbours(neighbours){}
c_City::c_City(){}


Board::Board()
{
    this->_cities.at(City::Algiers) = c_City(Color::Black, std::vector<City>{City::Madrid, City::Paris, City::Istanbul, City::Cairo});
    this->_cities.at(City::Atlanta) = c_City(Color::Blue, std::vector<City>{City::Chicago, City::Miami, City::Washington});
    this->_cities.at(City::Baghdad) = c_City(Color::Black, std::vector<City>{City::Tehran, City::Istanbul, City::Cairo, City::Riyadh, City::Karachi});
    this->_cities.at(City::Bangkok) = c_City(Color::Red, std::vector<City>{City::Kolkata, City::Chennai, City::Jakarta, City::HoChiMinhCity, City::HongKong});
    this->_cities.at(City::Beijing) = c_City(Color::Red, std::vector<City>{City::Shanghai, City::Seoul});
    this->_cities.at(City::Bogota) = c_City(Color::Yellow, std::vector<City>{City::MexicoCity, City::Lima, City::Miami, City::SaoPaulo, City::BuenosAires});
    this->_cities.at(City::BuenosAires) = c_City(Color::Yellow, std::vector<City>{City::Bogota, City::SaoPaulo});
    this->_cities.at(City::Cairo) = c_City(Color::Black, std::vector<City>{City::Algiers, City::Istanbul, City::Baghdad, City::Khartoum, City::Riyadh});
    this->_cities.at(City::Chennai) = c_City(Color::Black, std::vector<City>{City::Mumbai, City::Delhi, City::Kolkata, City::Bangkok, City::Jakarta});
    this->_cities.at(City::Chicago) = c_City(Color::Blue, std::vector<City>{City::SanFrancisco, City::LosAngeles, City::MexicoCity, City::Atlanta, City::Montreal});
    this->_cities.at(City::Delhi) = c_City(Color::Black, std::vector<City>{City::Tehran, City::Karachi, City::Mumbai, City::Chennai, City::Kolkata});
    this->_cities.at(City::Essen) = c_City(Color::Blue, std::vector<City>{City::London, City::Paris, City::Milan, City::StPetersburg});
    this->_cities.at(City::HoChiMinhCity) = c_City(Color::Red, std::vector<City>{City::Jakarta, City::Bangkok, City::HongKong, City::Manila});
    this->_cities.at(City::HongKong) = c_City(Color::Red, std::vector<City>{City::Bangkok, City::Kolkata, City::HoChiMinhCity, City::Shanghai, City::Manila, City::Taipei});
    this->_cities.at(City::Istanbul) = c_City(Color::Black, std::vector<City>{City::Milan, City::Algiers, City::StPetersburg, City::Cairo, City::Baghdad, City::Moscow});
    this->_cities.at(City::Jakarta) = c_City(Color::Red, std::vector<City>{City::Chennai, City::Bangkok, City::HoChiMinhCity, City::Sydney});
    this->_cities.at(City::Johannesburg) = c_City(Color::Yellow, std::vector<City>{City::Kinshasa, City::Khartoum});
    this->_cities.at(City::Karachi) = c_City(Color::Black, std::vector<City>{City::Tehran, City::Baghdad, City::Riyadh, City::Mumbai, City::Delhi});
    this->_cities.at(City::Khartoum) = c_City(Color::Yellow, std::vector<City>{City::Cairo, City::Lagos, City::Kinshasa, City::Johannesburg});
    this->_cities.at(City::Kinshasa) = c_City(Color::Yellow, std::vector<City>{City::Lagos, City::Khartoum, City::Johannesburg});
    this->_cities.at(City::Kolkata) = c_City(Color::Black, std::vector<City>{City::Delhi, City::Chennai, City::Bangkok, City::HongKong});
    this->_cities.at(City::Lagos) = c_City(Color::Yellow, std::vector<City>{City::SaoPaulo, City::Khartoum, City::Kinshasa});
    this->_cities.at(City::Lima) = c_City(Color::Yellow, std::vector<City>{City::MexicoCity, City::Bogota, City::Santiago});
    this->_cities.at(City::London) = c_City(Color::Blue, std::vector<City>{City::NewYork, City::Madrid, City::Essen, City::Paris});
    this->_cities.at(City::LosAngeles) = c_City(Color::Yellow, std::vector<City>{City::SanFrancisco, City::Chicago, City::MexicoCity, City::Sydney});
    this->_cities.at(City::Madrid) = c_City(Color::Blue, std::vector<City>{City::London, City::NewYork, City::Paris, City::SaoPaulo, City::Algiers});
    this->_cities.at(City::Manila) = c_City(Color::Red, std::vector<City>{City::Taipei, City::SanFrancisco, City::HoChiMinhCity, City::Sydney});
    this->_cities.at(City::MexicoCity) = c_City(Color::Yellow, std::vector<City>{City::LosAngeles, City::Chicago, City::Miami, City::Lima, City::Bogota});
    this->_cities.at(City::Miami) = c_City(Color::Yellow, std::vector<City>{City::Atlanta, City::MexicoCity, City::Washington, City::Bogota});
    this->_cities.at(City::Milan) = c_City(Color::Blue, std::vector<City>{City::Essen, City::Paris, City::Istanbul});
    this->_cities.at(City::Montreal) = c_City(Color::Blue, std::vector<City>{City::Chicago, City::Washington, City::NewYork});
    this->_cities.at(City::Moscow) = c_City(Color::Black, std::vector<City>{City::StPetersburg, City::Istanbul, City::Tehran});
    this->_cities.at(City::Mumbai) = c_City(Color::Black, std::vector<City>{City::Karachi, City::Delhi, City::Chennai});
    this->_cities.at(City::NewYork) = c_City(Color::Blue, std::vector<City>{City::Montreal, City::Washington, City::London, City::Madrid});
    this->_cities.at(City::Osaka) = c_City(Color::Red, std::vector<City>{City::Taipei, City::Tokyo});
    this->_cities.at(City::Paris) = c_City(Color::Blue, std::vector<City>{City::Algiers, City::Essen, City::Madrid, City::Milan, City::London});
    this->_cities.at(City::Riyadh) = c_City(Color::Black, std::vector<City>{City::Baghdad, City::Cairo, City::Karachi});
    this->_cities.at(City::SanFrancisco) = c_City(Color::Blue, std::vector<City>{City::LosAngeles, City::Chicago, City::Tokyo, City::Manila});
    this->_cities.at(City::Santiago) = c_City(Color::Yellow, std::vector<City>{City::Lima});
    this->_cities.at(City::SaoPaulo) = c_City(Color::Yellow, std::vector<City>{City::Bogota, City::BuenosAires, City::Lagos, City::Madrid});
    this->_cities.at(City::Seoul) = c_City(Color::Red, std::vector<City>{City::Beijing, City::Shanghai, City::Tokyo});
    this->_cities.at(City::Shanghai) = c_City(Color::Red, std::vector<City>{City::Beijing, City::HongKong, City::Taipei, City::Seoul, City::Tokyo});
    this->_cities.at(City::StPetersburg) = c_City(Color::Blue, std::vector<City>{City::Essen, City::Istanbul, City::Moscow});
    this->_cities.at(City::Sydney) = c_City(Color::Red, std::vector<City>{City::Jakarta, City::Manila, City::LosAngeles});
    this->_cities.at(City::Taipei) = c_City(Color::Red, std::vector<City>{City::Shanghai, City::HongKong, City::Osaka, City::Manila});
    this->_cities.at(City::Tehran) = c_City(Color::Black, std::vector<City>{City::Baghdad, City::Moscow, City::Karachi, City::Delhi});
    this->_cities.at(City::Tokyo) = c_City(Color::Red, std::vector<City>{City::Seoul, City::Shanghai, City::Osaka, City::SanFrancisco});
    this->_cities.at(City::Washington) = c_City(Color::Blue, std::vector<City>{City::Atlanta, City::NewYork, City::Montreal, City::Miami});

    std::array<std::string, NUM_OF_CITIES> cities_list = {
        string("Algiers"),
        string("Atlanta"),
        string("Baghdad"),
        string("Bangkok"),
        string("Beijing"),
        string("Bogota"),
        string("BuenosAires"),
        string("Cairo"),
        string("Chennai"),
        string("Chicago"),
        string("Delhi"),
        string("Essen"),
        string("HoChiMinhCity"),
        string("HongKong"),
        string("Istanbul"),
        string("Jakarta"),
        string("Johannesburg"),
        string("Karachi"),
        string("Khartoum"),
        string("Kinshasa"),
        string("Kolkata"),
        string("Lagos"),
        string("Lima"),
        string("London"),
        string("LosAngeles"),
        string("Madrid"),
        string("Manila"),
        string("MexicoCity"),
        string("Miami"),
        string("Milan"),
        string("Montreal"),
        string("Moscow"),
        string("Mumbai"),
        string("NewYork"),
        string("Osaka"),
        string("Paris"),
        string("Riyadh"),
        string("SanFrancisco"),
        string("Santiago"),
        string("SaoPaulo"),
        string("Seoul"),
        string("Shanghai"),
        string("StPetersburg"),
        string("Sydney"),
        string("Taipei"),
        string("Tehran"),
        string("Tokyo"),
        string("Washington")};


    for (unsigned long i = 0; i < NUM_OF_CITIES; i++)
    {
        this->_enum_to_string.insert(std::pair<int, string>{i, cities_list.at(i)}); //(i) = cities_list.at(i);
    }
}

int &Board::operator[](City city)
{
    int &res = this->_cities.at(city)._cubes;
    return res;
}

bool Board::is_clean()
{
    for (c_City& city : this->_cities)
    {
        if (city._cubes != 0)
        {
            return false;
        }
    }
    return true;
}

bool Board::is_connected(City src, City dst)
{
    std::vector<City> &list = this->_cities.at(src)._neighbours;
    for (City &city : list)
    {
        if (city == dst)
        {
            return true;
        }
    }
    return false;
}

ostream &pandemic::operator<<(ostream &os, const Board& board)
{

    for (unsigned long i = 0; i<NUM_OF_CITIES; i++)
    {
        os << board._enum_to_string.at(i) << ": [" << board._cities.at(i)._cubes << "], Research station: " << board._cities.at(i)._research_station << endl;
    }
    os << "Cures: " << endl;
    os << "\t" << "Blue: " << board._cures.at(Color::Blue) << endl;
    os << "\t" << "Yellow: " << board._cures.at(Color::Yellow) << endl;
    os << "\t" << "Red: " << board._cures.at(Color::Red) << endl;
    os << "\t" << "Black: " << board._cures.at(Color::Black) << endl;
    return os;
}