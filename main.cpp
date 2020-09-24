#include <iostream>
#include <string>
using namespace std;
 
class Address
{
public:
    string city;
    string street;
    int house;
    int apartment_num;
    bool equal(Address *adr_compare){
        if(adr_compare->city == this->city && adr_compare->street == this->street && adr_compare->house == this->house && adr_compare->apartment_num == this->apartment_num){
            return true;
        }
        return false;
    }
    bool isCity(string city){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        if(this->city == city){
            return true;
        }
        return false;
    }
    bool isStreet(string street){
        transform(street.begin(), street.end(), street.begin(), ::tolower);
        if(this->street == street){
            return true;
        }
        return false;
    }
    bool neighbor(Address *adr_compare){
        if(adr_compare->city == this->city && adr_compare->street == this->street){

            if((this->house+1) == adr_compare->house || (this->house-1) == adr_compare->house){
                return true;
            }
        }
        return false;
    }
};
string toString(Address *adr){
    return adr->city + ", " + adr->street + ", house " + to_string(adr->house) + ", apartment " + to_string(adr->apartment_num);
}
int main()
{
    Address adr1;
    Address adr2;
    string city_to_compare;
    string street_to_compare;
    cin >> adr1.city >> adr1.street >> adr1.house >> adr1.apartment_num;
    cin >> adr2.city >> adr2.street >> adr2.house >> adr2.apartment_num;
    cin >> city_to_compare >> street_to_compare;

    transform(adr1.city.begin(), adr1.city.end(), adr1.city.begin(), ::tolower);
    transform(adr1.street.begin(), adr1.street.end(), adr1.street.begin(), ::tolower);
    transform(adr2.city.begin(), adr2.city.end(), adr2.city.begin(), ::tolower);
    transform(adr2.street.begin(), adr2.street.end(), adr2.street.begin(), ::tolower);
    cout << boolalpha <<"\'"+toString(&adr1)+"\'"<<" - aдрес города " << city_to_compare << "? - " << adr1.isCity(city_to_compare) <<"\n";
    cout << boolalpha <<"\'"+toString(&adr2)+"\'"<<" - aдрес города " << city_to_compare << "? - " << adr2.isCity(city_to_compare) <<"\n";
    cout << boolalpha <<"\'"+toString(&adr1)+"\'"<<" - aдрес улицы " << street_to_compare << "? - " << adr1.isStreet(street_to_compare) <<"\n";
    cout << boolalpha <<"\'"+toString(&adr2)+"\'"<<" - aдрес улицы " << street_to_compare << "? - " << adr2.isStreet(street_to_compare) <<"\n";
    cout << boolalpha << "Являются ли данные адреса одинаковыми? -  " << adr2.equal(&adr1) << "\n";
    cout << boolalpha << "Являются ли данные адреса соседскими? -  " << adr2.neighbor(&adr1) << "\n";
    return 0;
}