#include <iostream>
#include <string>
using namespace std;

enum condition
{
    GOOD, BAD
};

enum gender {
    MALE, FEMALE
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
    float age;
    gender gender;
    condition condition;
    DATE dateOfArrival;
    DATE dateOfAdoption;
};

string genderEnumToString(DOG* dogs, int i)
{
    string gender;
    if (dogs[i].gender == 0)
    {
        gender = "Male";

    }
    else if (dogs[i].gender == 1)
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

void fillInToInsertDog(DOG& newDog, string& gender, string& condition)
{
    cout << "Fill in the information about the dog" << endl;
    cout << endl;
    cout << "Name: ";
    cin >> newDog.name;
    cout << "Breed: ";
    cin >> newDog.breed;
    cin.ignore();
    cout << "Age (Years): ";
    cin >> newDog.age;
    cout << "Gender (male/female): ";
    cin >> gender;
    cout << "Condition (good/bad): ";
    cin >> condition;
    cout << "Date of arrival (D/M/Y): ";
    cin >> newDog.dateOfArrival.day >> newDog.dateOfArrival.month >> newDog.dateOfArrival.year;
}


void genderStringToEnum(DOG* dogs, string gender, int i)
{
    if (gender == "male")
    {
        dogs[i].gender = gender::MALE;

    }
    else if (gender == "female")
    {
        dogs[i].gender = gender::FEMALE;
    }
}

void conditionStringToEnum(DOG* dogs, string condition, int i)
{
    if (condition == "good")
    {
        dogs[i].condition = condition::GOOD;

    }
    else if (condition == "bad")
    {
        dogs[i].condition = condition::BAD;
    }
}

void addDog(DOG* dogs, int& dogCount, DOG newDog)
{
    dogs[dogCount] = newDog;
    dogs[dogCount].id = dogCount + 1;
    dogCount++;
}


void addDogMenu(DOG* dogs, int& dogCount)
{
    string gender, condition;
    DOG newDog;
    fillInToInsertDog(newDog, gender, condition);
    addDog(dogs, dogCount, newDog);

    genderStringToEnum(dogs, gender, (dogCount - 1));
    conditionStringToEnum(dogs, condition, dogCount - 1);
}

void insertDog(DOG* dogs, int& dogCount, DOG newDog, int index)
{
    for (int i = dogCount; i > index; i--)
    {
        dogs[i] = dogs[i - 1];
    }
    dogs[index] = newDog;
    dogs[index].id = dogCount + 1;
    dogCount++;
}

void insertDogMenu(DOG* dogs, int& dogCount)
{
    int index;
    string gender, condition;

    DOG newDog;

    fillInToInsertDog(newDog, gender, condition);

    cout << endl;
    cout << "Enter the position where you want to place the dog: ";
    cin >> index;

    insertDog(dogs, dogCount, newDog, index);

    /* NOT NECCESSERY?!?
      genderStringToEnum(dogs, gender, index);
      conditionStringToEnum(dogs, condition, index);
      */
}

void showDog(DOG* dogs, int i, string gender, string condition)
{
    cout << "Name: " << dogs[i].name << endl;
    cout << "ID: " << dogs[i].id << endl;
    cout << "Breed: " << dogs[i].breed << endl;
    cout << "Age (in human years): " << dogs[i].age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Condition: " << condition << endl;
    cout << "Date of arrival: " << dogs[i].dateOfArrival.day << "/" << dogs[i].dateOfArrival.month << "/" << dogs[i].dateOfArrival.year << endl;
}

void printAdoptedDogs(DOG* adoptedDogs, int i, string gender, string condition)
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

void showDogsInShelter(DOG* dogs, int dogCount)
{
    string gender, condition;

    for (int i = 0; i < dogCount; i++)
    {
        gender = genderEnumToString(dogs, i);
        condition = conditionEnumToString(dogs, i);
        showDog(dogs, i, gender, condition);
        cout << endl;
    }
    cout << endl;

}

void showAdoptedDogs(DOG* adoptedDogs, int adoptedDogCount)
{
    string gender, condition;

    for (int i = 0; i < adoptedDogCount; i++)
    {
        gender = genderEnumToString(adoptedDogs, i);
        condition = conditionEnumToString(adoptedDogs, i);
        printAdoptedDogs(adoptedDogs, i, gender, condition);
    }
    cout << endl;
}

void showByBreed(DOG* dogs, int dogCount, string breedUser)
{
    string gender, condition;

    for (int i = 0; i < dogCount; i++)
    {
        gender = genderEnumToString(dogs, i);
        condition = conditionEnumToString(dogs, i);
        if (dogs[i].breed == breedUser)
        {
            showDog(dogs, i, gender, condition);
        }
    }
    cout << endl;
}

void showByBreedMenu(DOG* dogs, int dogCount)
{
    string breedUser;
    cout << "Enter breed: ";
    cin >> breedUser;
    cout << endl;
    showByBreed(dogs, dogCount, breedUser);
}

void showById(DOG* dogs, int dogCount, int IdUser)
{
    string gender, condition;

    for (int i = 0; i < dogCount; i++)
    {
        gender = genderEnumToString(dogs, i);
        condition = conditionEnumToString(dogs, i);
        if (dogs[i].id == IdUser)
        {
            showDog(dogs, i, gender, condition);
        }
    }
    cout << endl;
}

void showByIdMenu(DOG* dogs, int dogCount)
{
    int IdUser;
    cout << "Enter ID: ";
    cin >> IdUser;
    cout << endl;
    showById(dogs, dogCount, IdUser);
}

void showBadConditionDogs(DOG* dogs, int dogCount)
{
    string gender, condition;

    for (int i = 0; i < dogCount; i++)
    {
        gender = genderEnumToString(dogs, i);
        condition = conditionEnumToString(dogs, i);

        if (dogs[i].condition == condition::BAD)
        {
            showDog(dogs, i, gender, condition);
        }
    }
    cout << endl;
}

void mainMenu(DOG* dogs, int& dogCount, DOG* adoptedDogs, int& adoptedDogCount)
{
    int choice;

    cout << endl;
    cout << "We rescued a new dog (add new dog to the registry:" << endl;
    cout << "1. Add to the end of the list" << endl;
    cout << "2. Add to a specific position on the list)" << endl;
    cout << "3. An dog got adopted (remove dog from the list of current dogs and add to the adopted dogs list)" << endl;
    cout << "4. Update an dog's profile" << endl;
    cout << "5. Show all dogs in the shelter" << endl;
    cout << "6. Show all dogs that have been adopted" << endl;
    cout << "7. Show dog by ID number" << endl;
    cout << "8. Show all dogs of specific species" << endl;
    cout << "9. Show all dogs that need medical treatment" << endl;
    cout << "10. EXIT" << endl;

    cout << endl;

    cout << "Choose an option: ";

    cin >> choice;

    cout << endl;

    switch (choice)
    {
    case 1:addDogMenu(dogs, dogCount); break;
    case 2:insertDogMenu(dogs, dogCount); break;
        /*
    case 3:removeDog(); break;
    case 4:updateDog(); break;*/
    case 5:showDogsInShelter(dogs, dogCount); break;
    case 6:showAdoptedDogs(adoptedDogs, adoptedDogCount); break;
    case 7:showByIdMenu(dogs, dogCount); break;
    case 8:showByBreedMenu(dogs, dogCount); break;
    case 9:showBadConditionDogs(dogs, dogCount); break;
    case 10: exit(0); break;
    }
}

int main()
{
    bool continueMenu = true;
    int dogCount = 5;
    int adoptedDogCount = 1;

    DOG dogs[200] = {
        {"Bark", 1, "Husky", 2,gender::MALE,condition::GOOD,{22, 3, 2021}},
        {"Maya", 2, "Labrador", 1, gender::FEMALE, condition::GOOD, {18, 4, 2021}},
        {"Corny", 3, "French bulldog", 3, gender::MALE, condition::BAD, {03, 7, 2021}},
        {"Zeus", 4, "Golden retriever", 10, gender::MALE, condition::GOOD, {22, 9, 2020}},
        {"Lilly", 5, "Pomeranian", 1, gender::FEMALE, condition::GOOD, {01, 4 , 2021}},
        {"Steve", 6, "Pug", 3, gender::MALE, condition::GOOD, {02, 2, 2021}}
    };

    DOG adoptedDogs[200] = {
        {"Sara", 13, "Golden retriever", 1, gender::FEMALE, condition::GOOD, {1,3,2020}}
    };

    cout << "Hello! We are team ARTEMISSION and welcome to our program! \nHow may we assist you today?" << endl;

    do {
        mainMenu(dogs, dogCount, adoptedDogs, adoptedDogCount);
    } while (continueMenu == true);


}