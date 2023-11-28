#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <cmath>

template <typename T>
void PrintVector(const std::vector<T> vector, std::string start = "")
{
    std::cout << start << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    
    std::cout << "String Exercise 1: " << std::endl;

    std::sort(colours.begin(), colours.end());

    auto purpleIterator = std::find(colours.begin(), colours.end(), "purple");
    std::vector<std::string> prePurpleVector;
    std::vector<std::string> postPurpleVector;

    for (auto it = colours.begin(); it != colours.end(); ++it)
    {
        if (std::distance(it, purpleIterator) > 0) { prePurpleVector.push_back(*it); }
        else if (it != purpleIterator) { postPurpleVector.push_back(*it); }
    }

    PrintVector(prePurpleVector, "Pre Purple: ");
    PrintVector(postPurpleVector, "Post Purple: ");

    {
        std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        // 2) alle elementen UPPERCASE te maken.

        std::cout << std::endl << "String Exercise 2: " << std::endl;
        std::transform(colours.begin(), colours.end(), colours.begin(),
            [](std::string& string)
            {
                string[0] = std::toupper(string[0]);
                return string;
            }
        );

        PrintVector(colours);
    }
    {
        std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        // 3) alle dubbele te verwijderen

        std::cout << std::endl << "String Exercise 3: " << std::endl;
        std::set<std::string> set(colours.begin(), colours.end());
        colours.assign(set.begin(), set.end());

        PrintVector(colours);
    }

    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    {
        std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        // 1) alle negatieve elementen te verwijderen

        std::cout << std::endl << "Number Exercise 1: " << std::endl;
        std::remove_if(numbers.begin(), numbers.end(),
            [](double number)
            {
                return number < 0;
            }
        );

        PrintVector(colours);
    }

    {
        std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        // 2) voor alle elementen te bepalen of ze even of oneven zijn

        std::cout << std::endl << "Number Exercise 2: " << std::endl;

        std::for_each(numbers.begin(), numbers.end(), 
            [](const double& number)
            {
                if ((int)number % 2 == 0)
                {
                    std::cout << std::setprecision(2) << std::fixed << number << ": " << "is even" << std::endl;
                }
                else
                {
                    std::cout << std::setprecision(2) << std::fixed << number << ": " << "is uneven" << std::endl;
                }
            }
        );

    }

    {
        std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
        
        std::cout << std::endl << "Number Exercise 3: " << std::endl;

        double sum = 0.0;

        for(auto it = numbers.begin(); it != numbers.end(); ++it)
        {
            sum += *it;
        }

        std::cout << std::setprecision(2) << std::fixed << "Sum is: " << sum << std::endl;

        double average = sum / (double)numbers.size();

        std::cout << std::setprecision(2) << std::fixed << "Average is: " << average << std::endl;

        double product = 1.0;

        for(auto it = numbers.begin(); it != numbers.end(); ++it)
        {
            product *= *it;
        }

        std::cout << std::setprecision(2) << std::fixed << "Product is: " << product << std::endl;

    }

    return 0;
}