#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef bool (*Predicate)(int);

vector<int> reduce(vector<int> a, Predicate checker)
{
    vector<int> result;

    for (int i = 0; i < a.size(); i++)
    {
        if (checker(a[i]))
        {
            result.push_back(a[i]);
        }
    }

    return result;
}

bool isEven(int number)
{
    bool result = number % 2 == 0;
    return result;
}

bool isOdd(int number)
{
    bool result = number % 2 == 1;
    return result;
}

bool isPrime(int number)
{

    bool result = true;

    if (number > 1)
    {
        for (int i = 2; i < number; i++)
        {
            if (number % i == 0)
            {
                result = false;
                break;
            }
        }
    }
    else
    {
        result = false;
    }

    return result;
}

bool isSquare(int number)
{
    bool result = false;

    int i = 0;
    while (i * i <= number)
    {
        if (i * i == number)
        {
            result = true;
            break;
        }
        i += 1;
    }

    return result;
}

bool isSymmetric(int number)
{
    bool result = true;

    string str = to_string(number);
    string reversedStr = str;
    reversedStr.reserve();

    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        if (str[i] != reversedStr[size - 1 - i])
        {
            result = false;
            break;
        }
    }
    
    if(size < 2)
        result = false;
    return result;
}

void print(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> a = {3, 7, 9, 4, 11, 2, 5, 121, 919, 12, 144, 6,
                     36, 15, 89, 32, 20, 51, 49, 97, 20, 80, 44, 2};

    auto sub = reduce(a, isSquare);
    auto sub2 = reduce(a, isSymmetric);
    print(sub);
    print(sub2);

    return 0;
}
