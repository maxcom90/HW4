#include <iostream>
#include <fstream>
#include <string>
class house_address
{
private:
    std::string city;
    std::string street;
    std::string house_number;
    std::string apart_number;
public:
    house_address()
    {
        city = "0";
        street = "0";
        house_number = "0";
        apart_number = "0";
    }
    house_address(std::string city, std::string street, std::string house_number, std::string apart_number)
    {
        this->city = city;
        this->street = street;
        this->house_number = house_number;
        this->apart_number = apart_number;
    }
    std::string get_city()
    {
        return city;
    }
    std::string get_street()
    {
        return street;
    }
    std::string get_house_number()
    {
        return house_number;
    }
    std::string get_apart_number()
    {
        return apart_number;
    }
    
};

int main(int argc, char** argv)
{

    setlocale(LC_ALL, "RUS");
    std::ifstream fin("in.txt");
    std::ofstream fout("out.txt");
    std::string a, b, c, d, e;
    int numb_address;
    int numb_elements = 4;
    std::string city;
    std::string street;
    std::string house_number;
    std::string apart_number;
    int counter = 1;

    if (fin.is_open())
    {
        fin >> a;
        int numb_address = std::stoi(a);
        int numb_elements = 4;

        house_address* address = new house_address[numb_address];

        for (int i = 0; i < numb_address; i++)
        {
            fin >> b;
            fin >> c;
            fin >> d;
            fin >> e;

            address[i] = house_address(b, c, d, e);
        }
        fout << numb_address << std::endl;
        //---------------------------------------------------------
        for (int i = 0; i < numb_address; i++)
        {
            for (int i = numb_address - 1; i > 0; i--)
            {
                if (address[i].get_city().compare(address[i - 1].get_city()) == 1)
                {
                    std::swap(address[i], address[i - 1]);

                }
            }
        }
        //---------------------------------------------------------
        for (int i = numb_address - 1; i >= 0; i--)
        {            
            fout << address[i].get_city();
            fout << ", ";
            fout << address[i].get_street();
            fout << ", ";
            fout << address[i].get_house_number();
            fout << ", ";
            fout << address[i].get_apart_number();

            if (i != 0)
            {
                fout << std::endl;
            }
        }
        delete[] address;
    }
    fout.close();
    fin.close();
}