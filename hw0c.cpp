#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

enum class runType { inc, dec, equal };

int runNum(vector<int> numbers) 
{

    int runs = 1;
    runType type = runType::equal;
    int previousNumber = 0;

    for (int temp = 0; temp < numbers.size(); temp++) 
    {
        int difference = numbers[temp] - previousNumber;

        switch (type) 
        {
            case runType::equal:
            {
                if (difference == 0)
                    break;
            }

            case runType::inc:
            {
                if (difference < 0) 
                {
                    runs++;
                    type = runType::dec;
                }
                break;
            }

            case runType::dec:
            {
                if (difference > 0)
                {
                    runs++;
                    type = runType::inc;
                }
                break;
            }
        }
        previousNumber = numbers[temp];
    }
    return runs;
}

int main()
{
    vector<int> numbers;
    ifstream input("testdata.txt", ios::in);

    int n;
    while (input >> n)
        numbers.push_back(n);

    input.close();

    int runNumber = runNum(numbers);

    cout << "The number of runs is: " << runNumber << "\n";
    
    return 0;
}

