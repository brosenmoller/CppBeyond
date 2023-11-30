#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <cmath>
#include <numeric>

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
    std::vector<std::string> prePurpleVector(colours.begin(), purpleIterator);
    std::vector<std::string> postPurpleVector(purpleIterator, colours.end());

    PrintVector(prePurpleVector, "Pre Purple: ");
    PrintVector(postPurpleVector, "Post Purple: ");

    {
        std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        // 2) alle elementen UPPERCASE te maken.

        std::cout << std::endl << "String Exercise 2: " << std::endl;
        std::transform(colours.begin(), colours.end(), colours.begin(),
            [](std::string& string)
            {
                std::transform(string.begin(), string.end(), string.begin(), toupper);
                return string;
            }
        );

        PrintVector(colours);
    }
    {
        std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
        // 3) alle dubbele te verwijderen

        std::cout << std::endl << "String Exercise 3: " << std::endl;
        auto duplicatesIterator = std::unique(colours.begin(), colours.end());
        colours.erase(duplicatesIterator, colours.end());

        PrintVector(colours);
    }

    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    {
        std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
        // 1) alle negatieve elementen te verwijderen

        std::cout << std::endl << "Number Exercise 1: " << std::endl;

        std::erase_if(numbers,
            [](double number) -> bool
            {
                return number < 0;
            }
        );

        PrintVector(numbers);
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

        double sum = std::accumulate(numbers.begin(), numbers.end(), 0.0);

        std::cout << std::setprecision(2) << std::fixed << "Sum is: " << sum << std::endl;

        double average = sum / (double)numbers.size();

        std::cout << std::setprecision(2) << std::fixed << "Average is: " << average << std::endl;

        double product = std::accumulate(numbers.begin(), numbers.end(), 1.0, std::multiplies<double>());

        std::cout << std::setprecision(2) << std::fixed << "Product is: " << product << std::endl;
    }

    return 0;
}