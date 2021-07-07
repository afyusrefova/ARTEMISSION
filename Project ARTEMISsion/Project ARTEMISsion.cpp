

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

string conditionEnumToString(DOG* dogs, int i)
{
    string condition;
    if (dogs[i].condition == 0)
    {
        condition = "Good";
    }
    else if (dogs[i].condition == 1)
    {
        condition = "Bad";
    }
    return condition;
}

void showDog(DOG* dogs, int i, string gender, string condition)
{
    cout << "Name: " << animals[i].name << endl;
    cout << "ID: " << animals[i].id << endl;
    cout << "Breed: " << animals[i].breed << endl;
    cout << "Age (in human years): " << animals[i].age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Condition: " << condition << endl;
    cout << "Date of arrival: " << animals[i].dateOfArrival.day << "/" << animals[i].dateOfArrival.month << "/" << animals[i].dateOfArrival.year << endl;
}

void showAdoptedDog(DOG* adoptedDogs, int i, string gender, string condition)
{
    cout << "Name: " << adoptedDogs[i].name << endl;
    cout << "ID: " << adoptedDogs[i].id << endl;
    cout << "Breed: " << adoptedDogs[i].breed << endl;
    cout << "Age (in human years): " << adoptedDogs[i].age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Condition: " << condition << endl;
    cout << "Date of arrival: " << adoptedDogs[i].dateOfArrival.day << "/" << adoptedDogs[i].dateOfArrival.month << "/" << adoptedDogs[i].dateOfArrival.year << endl;
    cout << "Date of adoption: " << adoptedDogs[i].dateOfAdoption.day << "/" << adoptedDogs[i].dateOfAdoption.month << "/" << adoptedDogs[i].dateOfAdoption.year << endl;
}



int main()
{
    cout << "ARTEMISSION" << endl;
}
