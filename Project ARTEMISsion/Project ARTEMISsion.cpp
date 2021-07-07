

#include <iostream>
#include <string>
using namespace std;
enum gender {
    MALE, FEMALE
};
enum condition
{
    GOOD, BAD;
};

struct DATE
{
    int day;
    int month;
    int year;
};

struct DOG
{
    string name;
    int id;
    string breed;
    gender gender;
    condition condition;
    DATE dateOfArrival;
    DATE dateOfAdoption;
};
string genderEnumToString(DOG* dogs, int i)
{
    string gender;
    if (dogs[i].gender = 0)
    {
        gender = "Male";

    }
    else if (dog[i].gender == 1)
    {
        gender = "Female";
    }
    return gender;
}


int main()
{
    cout << "ARTEMISSION" << endl;
}
