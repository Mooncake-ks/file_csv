#include <iostream>
#include <string>
#include <Vector>
#include <fstream>

void add_data(std::vector<int>& x, std::vector<int>& y,std::ifstream& data, const std::string& adres);
void show(const std::vector<int>& x, const std::vector<int>& y);

int main()
{
   
    try
    {
        std::ifstream  data;
        std::vector<int> x, y;
        data.exceptions(std::ifstream::badbit | std::ifstream::failbit);
        add_data(x, y, data, "C:/Users/User/source/repos/work_csv/coordinates.csv");
        show(x, y);
    }
    catch (const std::ifstream::failure& ex)
    {
        std::cout << ex.what() << " Error" << std::endl;
    }
  
   
    return 0;
}

void add_data(std::vector<int>& x, std::vector<int>& y, std::ifstream& data,const std::string& adres)
{
    std::string data_x, data_y;
    data.open(adres);
    while (data.good())
    {
        std::getline(data, data_x, ';');
        x.push_back(stoi(data_x));
        std::getline(data, data_y, '\n');

        y.push_back(stoi(data_y));
        data_x.clear();
        data_y.clear();
    }
    data.close();
}

void show(const std::vector<int>& x, const std::vector<int>& y)
{
    for (int i{ 0 }; i < x.size(); ++i)
    {
        std::cout << "(" << x[i] << "," << y[i] << ")" << std::endl;
    }
}
