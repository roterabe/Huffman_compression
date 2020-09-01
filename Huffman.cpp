#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

void printv(std::vector<char> c)
{
    for (auto e : c)
        std::cout << e << " ";
    std::cout << std::endl;
}

void printm(std::map<char, int> m)
{
    for (auto e : m)
        std::cout << e.first << " " << e.second << "\n";
    std::cout << std::endl;
}

int main()
{
    std::string word = "";
    std::vector<char> data = std::vector<char>();
    std::map<char, int> occurance;

    std::cout << "Please input text to compress:"
              << "\n";
    std::getline(std::cin, word);
    std::cout << "Calculating...."
              << "\n";

    for (int i = 0; i < word.size(); i++)
    {
        data.push_back(word[i]);
        occurance.insert(std::pair<char, int>(word[i], 0));
    }

    for (int i = 0; i < word.size(); i++)
    {
        int num = count(data.begin(), data.end(), word[i]);
        std::map<char, int>::iterator it = occurance.find(word[i]);
        it->second = num;
    }

    printv(data);
    printm(occurance);
    std::cout << word << "\n";

    return 0;
}
