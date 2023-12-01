#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Address {
public:
    Address() {}

    Address(std::string city, std::string str, int house, int apart) {
        this->city = city;
        this->street = str;
        this->houseNumb = house;
        this->apartNumb = apart;
    }

    // Setters
    void setCity(std::string city) {
        this->city = city;
    }

    void setStreet(std::string street) {
        this->street = street;
    }

    void setHouse(int house) {
        this->houseNumb = house;
    }

    void setApart(int apart) {
        this->apartNumb = apart;
    }

    // Getters
    std::string getCity() {
        return this->city;
    }

    std::string getStreet() {
        return this->street;
    }

    int getHouse() {
        return this->houseNumb;
    }

    int getApart() {
        return this->apartNumb;
    }

    friend void sortAddresses(Address* addresses, int size);

private:
    std::string city;
    std::string street;
    int houseNumb;
    int apartNumb;
};

void sortAddresses(Address* addresses, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size; ++j)
        {
            if (strcmp(addresses[i].getCity().c_str(), (addresses[j].getCity().c_str())) > 0)
            {
                std::swap(addresses[i], addresses[j]);
            }
        }
    }
}

int main()
{
    std::ifstream inputFile("in.txt");
    if (inputFile.is_open())
    {
        std::string temp = "";
        int size = 0, strCount = 4;
        if (inputFile >> temp)
        {
            size = std::stoi(temp);
        }
        else
        {
            std::cout << "Error in in.txt file!" << std::endl;
            return 1;
        }

        Address* addr = new Address[size];
        int count = size;

        for (int i = 0; i < strCount; ++i)
        {
            if (inputFile >> temp && count > 0)
            {
                switch (i)
                {
                case 0:
                    addr[count - 1].setCity(temp);
                    break;
                case 1:
                    addr[count - 1].setStreet(temp);
                    break;
                case 2:
                    addr[count - 1].setHouse(std::stoi(temp));
                    break;
                case 3:
                    addr[count - 1].setApart(std::stoi(temp));
                    i = -1;
                    --count;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        inputFile.close();

        sortAddresses(addr, size);

        std::ofstream outputFile("out.txt");
        outputFile << size << "\n";
        for (int i = 0; i < size; ++i)
        {
            outputFile << addr[i].getCity() << ", ";
            outputFile << addr[i].getStreet() << ", ";
            outputFile << addr[i].getHouse() << ", ";
            outputFile << addr[i].getApart() << "\n";
        }
        outputFile.close();

        delete[] addr;
    }

    return 0;
}

