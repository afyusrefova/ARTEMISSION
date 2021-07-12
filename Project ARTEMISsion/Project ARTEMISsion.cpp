#include <iostream>
#include <string>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[1;91m" 
#define YELLOW  "\033[1;93m"  
#define GREEN   "\033[1;92m"
#define BLUE    "\033[0;36m"
#define CYAN    "\033[1;96m"
#define PURPLE  "\033[1;95m"
#define GRAY    "\033[1;90m" 
#define WHITE   "\033[4;37m"

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

int checkIfUserDataIsValid()
{
    int value;
    bool validInput = false;
    do {
        cin >> value;
        if (!(validInput = cin.good())) {
            cout << "Incorrect input, please enter a number from 1 to 10" << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            return -1;
        }

    } while (!validInput);
    return value;
}

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
    cout << "Date of arrival (D M Y) " << endl;
    cout << GRAY << "NOTE: please enter the date number with a space between them " << RESET << endl;
    cout << "Enter here: ";
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

void insertDogMenu(DOG* dogs, int& dogCount, int maxSize)
{
    if (dogCount < maxSize)
    {
        int index;
        string gender, condition;

        DOG newDog;

        fillInToInsertDog(newDog, gender, condition);

        cout << endl;
        cout << "Enter the position where you want to place the dog: ";
        cin >> index;

        insertDog(dogs, dogCount, newDog, index);


        genderStringToEnum(dogs, gender, index);
        conditionStringToEnum(dogs, condition, index);

    }
    else
        cout << RED << "Not enough space in the dog shelter" << RESET << endl;
}

int getIndexById(DOG* dogs, int dogCount, int idUser)
{
    int index;
    for (int i = 0; i < dogCount; i++)
    {
        if (dogs[i].id == idUser)
            index = i;
    }

    return index;
}

void removeDog(DOG* dogs, int& dogCount, int index)
{
    for (int i = index; i < (dogCount - 1); i++)
    {
        dogs[i] = dogs[i + 1];
    }
    dogCount--;
}

void removeDogByIdMenu(DOG* dogs, int& dogCount, DOG* adoptedDogs, int& adoptedDogCount)
{
    int id, index;
    cout << "Enter dog's ID: ";
    cin >> id;

    index = getIndexById(dogs, dogCount, id);
    if (dogs[index].condition == condition::BAD)
    {
        cout << RED << "\nA dog that needs medical treatment can't be adopted" << RESET << endl;

    }
    else {
        cout << "\nEnter date of adoption (D M Y)" << endl;
        cout << GRAY << "NOTE: please enter the date number with a space between them " << RESET << endl;
        cout << "Enter here: ";
        cin >> dogs[index].dateOfAdoption.day >> dogs[index].dateOfAdoption.month >> dogs[index].dateOfAdoption.year;
        addDog(adoptedDogs, adoptedDogCount, dogs[index]);
        removeDog(dogs, dogCount, index);
    }



}

void removeDogByIndexMenu(DOG* dogs, int& dogCount, DOG* adoptedDogs, int& adoptedDogCount)
{
    int index;
    cout << "Enter dog's position (index): ";
    cin >> index;
    if (dogs[index].condition == condition::BAD)
    {
        cout << RED << "\nA dog that needs medical treatment can't be adopted" << RESET << endl;

    }
    else
    {
        cout << "\nEnter date of adoption (D M Y) " << endl;
        cout << GRAY << "NOTE: please enter the date number with a space between them " << RESET << endl;
        cout << "Enter here: ";
        cin >> dogs[index].dateOfAdoption.day >> dogs[index].dateOfAdoption.month >> dogs[index].dateOfAdoption.year;

        addDog(adoptedDogs, adoptedDogCount, dogs[index]);
        removeDog(dogs, dogCount, index);
    }

}

void removeDogMenu(DOG* dogs, int& dogCount, DOG* adoptedDogs, int& adoptedDogCount)
{
    int choice;
    cout << "Do you want to remove a dog by: \n";
    cout << endl;
    cout << "1. Its ID\t 2. Its position in the list (index)\n";
    cout << endl;
    cout << "Enter an option: ";
    cin >> choice;
    cout << endl;

    while (choice != 1 && choice != 2)
    {
        cout << RED << "You have entered an incorrection option. Please enter 1 or 2: ";
        cin >> choice;
        cout << endl;
    };

    switch (choice)
    {
    case 1:removeDogByIdMenu(dogs, dogCount, adoptedDogs, adoptedDogCount); break;
    case 2:removeDogByIndexMenu(dogs, dogCount, adoptedDogs, adoptedDogCount); break;
    }

    cout << "\nThe dog will be now added to the list of adopted dogs";
    cout << endl;
}

void editName(DOG* dogs, int index)
{
    string newName;
    cout << "Enter a new name: ";
    cin >> newName;
    dogs[index].name = newName;
}

void editBreed(DOG* dogs, int index)
{
    string newBreed;
    cout << "Enter new breed: ";
    cin >> newBreed;
    dogs[index].breed = newBreed;
}

void editAge(DOG* dogs, int index)
{
    int newAge;
    cout << "Enter new age: ";
    cin >> newAge;
    dogs[index].age = newAge;
}

void editGender(DOG* dogs, int index)
{
    string newGender;
    cout << "Enter new gender (male/female): ";
    cin >> newGender;
    genderStringToEnum(dogs, newGender, index);
}

void editCondition(DOG* dogs, int index)
{
    string newCondition;
    cout << "Enter new condition (good/bad): ";
    cin >> newCondition;
    conditionStringToEnum(dogs, newCondition, index);
}

void editDateOfArrival(DOG* dogs, int index)
{
    int newDay, newMonth, newYear;
    cout << "Enter new date of arrival (D M Y) " << endl;
    cout << GRAY << "NOTE: please enter the date number with a space between them " << RESET << endl;
    cout << "Enter here: ";
    cin >> newDay >> newMonth >> newYear;
    dogs[index].dateOfArrival.day = newDay;
    dogs[index].dateOfArrival.month = newMonth;
    dogs[index].dateOfArrival.year = newYear;
}

void selectEdit(DOG* dogs, int index)
{
    int choice;
    cout << "\n What do you want to edit? \n";
    cout << "\n1. Name";
    cout << "\n2. Breed";
    cout << "\n3. Age";
    cout << "\n4. Gender";
    cout << "\n5. Condition";
    cout << "\n6. Date of arrival (D/M/Y) \n";
    
    cout << "\nEnter an option: ";
    cin >> choice;

    while (choice < 1 or choice>6) {
        cout << "\nYou have entered an incorrect option. Please enter a number between 1 and 6: ";
        cin >> choice;
        cout << endl;
    }
    cout << endl;
    cout << endl;

    switch (choice)
    {
    case 1:editName(dogs, index); break;
    case 2:editBreed(dogs, index); break;
    case 3:editAge(dogs, index); break;
    case 4:editGender(dogs, index); break;
    case 5:editCondition(dogs, index); break;
    case 6:editDateOfArrival(dogs, index); break;
    }
}

void editDogByIdMenu(DOG* dogs, int dogCount)
{
    int id, index;
    cout << "Enter dog's ID: ";
    cin >> id;

    index = getIndexById(dogs, dogCount, id);
    selectEdit(dogs, index);
}

void editDogByIndexMenu(DOG* dogs)
{
    int index;
    cout << "Enter dog's position (index): ";
    cin >> index;
    selectEdit(dogs, index);
}

void editDogMenu(DOG* dogs, int dogCount)
{
    int choice;
    cout << "Do you want to select an dog by: \n";
    cout << "1. Its ID\t 2. Its position on the list (index)\n" << endl;
    cout << "Enter an option: ";
    cin >> choice;
    cout << endl;

    while (choice != 1 && choice != 2)
    {
        cout << RED << "You have entered an incorrection option. Please enter 1 or 2: ";
        cin >> choice;
        cout << endl;
    };
    cout << endl;

    switch (choice)
    {
    case 1:editDogByIdMenu(dogs, dogCount); break;
    case 2:editDogByIndexMenu(dogs); break;
    }
}

void showDog(DOG* dogs, int i, string gender, string condition)
{
    cout << "Name: " << dogs[i].name << endl;
    cout << "ID: " << dogs[i].id << endl;
    cout << "Breed: " << dogs[i].breed << endl;
    cout << "Age (in human years): " << dogs[i].age << endl;
    cout << "Gender: " << gender << endl;
    cout << "Condition: " << condition << endl;
    cout << "Date of arrival (D/M/Y): " << dogs[i].dateOfArrival.day << "/" << dogs[i].dateOfArrival.month << "/" << dogs[i].dateOfArrival.year << endl;
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


int SelectBetweenTwo() {
    int choice;

    cout << "Which do you want to see \n";
    cout << "1. Dogs in the shelter \t 2. Adopted dogs\n";
    cout << "\nEnter an option: ";
    cin >> choice;

    while (choice != 1 and choice != 2) {
        cout << "You have entered an incorrect option. Please enter either 1 or 2: ";
        cin >> choice;
        cout << endl;
    }
    return choice;
}

void showByBreed(DOG* dogs, int dogCount, string breedUser, int selected_array)
{
    string gender, condition;

    for (int i = 0; i < dogCount; i++)
    {
        gender = genderEnumToString(dogs, i);
        condition = conditionEnumToString(dogs, i);
        if (dogs[i].breed == breedUser)
        {
            if (selected_array == 1)
                showDog(dogs, i, gender, condition);
            else
                printAdoptedDogs(dogs, i, gender, condition);
            cout << endl;
        }
    }
    cout << endl;

}

void showByBreedMenu(DOG* dogs, int dogCount, DOG* adoptedDogs, int adoptedDogCount)
{
    string breedUser;
    int selected_array = SelectBetweenTwo();
    cout << "Enter breed: ";
    cin >> breedUser;
    cout << endl;

    if (selected_array == 1)
        showByBreed(dogs, dogCount, breedUser, selected_array);
    else
        showByBreed(adoptedDogs, adoptedDogCount, breedUser, selected_array);
}

void showById(DOG* dogs, int dogCount, int IdUser, int selected_array)
{

    string gender, condition;

    for (int i = 0; i < dogCount; i++)
    {
        gender = genderEnumToString(dogs, i);
        condition = conditionEnumToString(dogs, i);
        if (dogs[i].id == IdUser)
        {
            if (selected_array == 1)
                showDog(dogs, i, gender, condition);
            else
                printAdoptedDogs(dogs, i, gender, condition);
        }
    }
    cout << endl;

}

void showByIdMenu(DOG* dogs, int dogCount, DOG* adoptedDogs, int adoptedDogCount)
{
    int IdUser;
    int selected_array = SelectBetweenTwo();
    cout << "Enter ID: ";
    cin >> IdUser;
    cout << endl;
    if (selected_array == 1)
        showById(dogs, dogCount, IdUser, selected_array);
    else
        showById(adoptedDogs, adoptedDogCount, IdUser, selected_array);

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

void mainMenu(DOG* dogs, int& dogCount, DOG* adoptedDogs, int& adoptedDogCount, int maxSize)
{


    cout << endl;
    cout << "We rescued a new dog (add new dog to the registry):" << endl;
    cout << "1. Add to the end of the list" << endl;
    cout << "2. Add to a specific position on the list" << endl;
    cout << "3. A dog got adopted" << endl;
    //3. (remove dog from the list of current dogs and add to the adopted dogs list)
    cout << "4. Update a dog's profile" << endl;
    cout << "5. Show all dogs in the shelter" << endl;
    cout << "6. Show all dogs that have been adopted" << endl;
    cout << "7. Show a dog by ID number" << endl;
    cout << "8. Show all dogs of specific breed(small caps)" << endl;
    cout << "9. Show all dogs that need medical treatment" << endl;
    cout << "10. EXIT" << endl;

    cout << endl;

    cout << "Choose an option: ";




    switch (checkIfUserDataIsValid())
    {
    case 1:addDogMenu(dogs, dogCount); break;
    case 2:insertDogMenu(dogs, dogCount, maxSize); break;
    case 3:removeDogMenu(dogs, dogCount, adoptedDogs, adoptedDogCount); break;
    case 4:editDogMenu(dogs, dogCount); break;
    case 5:showDogsInShelter(dogs, dogCount); break;
    case 6:showAdoptedDogs(adoptedDogs, adoptedDogCount); break;
    case 7:showByIdMenu(dogs, dogCount, adoptedDogs, adoptedDogCount); break;
    case 8:showByBreedMenu(dogs, dogCount, adoptedDogs, adoptedDogCount); break;
    case 9:showBadConditionDogs(dogs, dogCount); break;
    case 10: exit(0); break;
    case -1:  mainMenu(dogs, dogCount, adoptedDogs, adoptedDogCount, maxSize); break;
    default: cout << "Incorrect input, please enter a number from 1 to 10" << endl;
        mainMenu(dogs, dogCount, adoptedDogs, adoptedDogCount, maxSize);
        break;
    }
}

int main()
{
    bool continueMenu = true;
    int dogCount = 6;
    int adoptedDogCount = 1;
    int maxSize = 80;

    DOG dogs[200] = {
        {"Bark", 1, "husky", 2,gender::MALE,condition::GOOD,{22, 3, 2021}},
        {"Maya", 2, "labrador", 1, gender::FEMALE, condition::GOOD, {18, 4, 2021}},
        {"Corny", 3, "french bulldog", 3, gender::MALE, condition::BAD, {03, 7, 2021}},
        {"Zeus", 4, "golden retriever", 10, gender::MALE, condition::GOOD, {22, 9, 2020}},
        {"Lilly", 5, "pomeranian", 1, gender::FEMALE, condition::GOOD, {01, 4 , 2021}},
        {"Steve", 6, "pug", 3, gender::MALE, condition::GOOD, {02, 2, 2021}}
    };

    DOG adoptedDogs[200] = {
        {"Sara", 13, "golden retriever", 1, gender::FEMALE, condition::GOOD, {1,3,2020}}
    };

    cout << "Hello! We are team ARTEMISSION" << endl;
    cout << endl;
    cout << endl;
    cout << "Welcome to our program!\nHow may we assist you today?" << endl;

    do {
        mainMenu(dogs, dogCount, adoptedDogs, adoptedDogCount, maxSize);
    } while (continueMenu == true);


}