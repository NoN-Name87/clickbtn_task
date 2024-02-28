#include <iostream>
#include <map>
#include <cstring>
#include <iterator>
#include <sstream>

std::map<int, int> get_btn_margin(int num_btns)
{
    if(num_btns < 1 || num_btns > 100)
        throw std::logic_error("Num of buttons must be from 1 to 100");
    
    std::map<int, int> btns;
    std::string temp;
    int counter{1};
    while(counter != num_btns + 1 && std::getline(std::cin, temp))
    {
        std::stringstream line(temp);
        std::istream_iterator<std::string> begin(line);
        std::istream_iterator<std::string> end;
        while(counter != num_btns + 1 && begin != end)
        {
            int num = std::stoi(*begin++);
            if(num < 1 || num > 100000)
                throw std::logic_error("Button margin must be from 1 to 100000");
            btns[counter++] = num; 
        }
    }
    return btns;
}

void click(std::map<int, int> & btns, int clicks)
{
    if(clicks < 1 || clicks > 100000)
        throw std::logic_error("Total num clicks must be from 1 to 100000");
    
    std::string temp;
    while(clicks != 0 && std::getline(std::cin, temp))
    {
        std::stringstream line(temp);
        std::istream_iterator<std::string> begin(line);
        std::istream_iterator<std::string> end;
        while(clicks != 0 && begin != end)
        {
            int num = std::stoi(*begin++);
            btns.at(num)--;
            clicks--;
        }
    }
}

int main(int argc, char **argv)
{
    try
    {
        int num_btn{0};
        int clicks{0};
        std::cout << "Enter num of buttons:\n";
        std::cin >> num_btn;
        auto btns = get_btn_margin(num_btn);
        std::cout << "Enter num of clicks:\n";
        std::cin >> clicks;
        click(btns, clicks);
        for(const auto & i : btns)
        {
            std::cout << (i.second < 0 ? "yes\n" : "no\n");
        }
    }
    catch(const std::exception & except)
    {
        std::cout << "ERROR: " << except.what() << "\n";
    }
}