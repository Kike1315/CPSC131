//
//  main.cpp
//  Project1
//
//  Created by Enrique  on 1/23/15.
//  Copyright (c) 2015 Enrique . All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

void rowStar();
void displayMenu();
void calToJul(int date[]);
void julToCal(int date[]);
void exit();

int main() {
    
    int userChoice = 0;
    int Date[13];
    Date[0] = 0;
    Date[1] = 31;
    Date[2] = 59;
    Date[3] = 90;
    Date[4] = 120;
    Date[5] = 151;
    Date[6] = 181;
    Date[7] = 212;
    Date[8] = 243;
    Date[9] = 273;
    Date[10] = 304;
    Date[11] = 334;
    Date[12] = 365;


    displayMenu();
    cin >> userChoice;
    while(userChoice > 0) {
        if(userChoice == 1) {
            calToJul(Date);
            userChoice = -1;
        }
        else if (userChoice == 2) {
            julToCal(Date);
            userChoice = -1;
        }
        else if (userChoice == 3) {
            exit();
            userChoice = -1;
        }
        else {
            cout << "Please enter a number from the menu above.\n";
            cin >> userChoice;
        }
    }
    return 0;
}

void rowStar() {
    for(int i = 0; i < 50; i++) {
        cout << '*';
    }
    cout << endl;
}

void calToJul(int date[]) {
    int mm, dd, yyyy, ddd, julian = 0;
    
    do {
        cout << "Enter a valid year (Valid year = 1 - 9999): ";
        cin >> yyyy;
        if (yyyy > 0 && yyyy < 10000)
            break;
    } while (true);
    do {
        cout << "Enter a valid month (Valid month = 1 - 12): ";
        cin >> mm;
        if (mm < 13 && mm > 0)
            break;
    } while (true);
    int flag = 1;
    do {
        switch(mm) {
            default: cout << "Enter a valid day (Valid day = 1 - 31): ";
                cin >> dd;
                if (dd > 0 && dd < 32)
                    flag = 0;
                break;
            case 2:
                if(yyyy % 4 == 0) {
                    cout << "Enter a valid day (Valid day = 1 - 29): ";
                    cin >> dd;
                    if(dd > 0 && dd < 30)
                        flag = 0;
                }
                else {
                    cout << "Enter a valid day (Valid day = 1 - 28): ";
                    cin >> dd;
                    if (dd > 0 && dd < 29)
                        flag = 0;
                }
                break;
            case 4: case 6: case 9: case 11:
                cout << "Enter a valid day (Valid day = 1 - 30): ";
                cin >> dd;
                if (dd > 0 && dd < 31)
                    flag = 0;
                break;
        }
    } while (flag > 0);
    
    ddd = date[mm-1];
    ddd += dd;
    if (mm == 3 && yyyy % 4 == 0 && dd < 15)
        ddd++;
    yyyy *= 1000;
    julian = yyyy + ddd;
    if (yyyy % 4 == 0)
        julian++;
    cout << "Julian form is: " << julian << endl;
}

void julToCal(int date[]) {
    int mm = 0, dd, ddd, yyyy, julian = 0;
    
    do {
        cout << "Enter valid Julian form (Valid Julian form = 1 - 9999999): ";
        cin >> julian;
        if (julian > 0 && julian < 10000000)
            break;
    } while(true);
 
    yyyy = julian / 1000;
    ddd = julian % 1000;
    if (yyyy % 4 == 0)
        ddd--;
    
    for(int i = 0; i < 13; i++) {
            if(date[i] + 1 > ddd) {
                if (i == 3 && yyyy % 4 == 0 && ddd == 60)
                    mm = i - 1;
                else
                    mm = i;
                i = 13;
            }
    }
    dd = ddd - date[mm-1];
    cout << "The date is: " << mm  << "/" << dd << "/" << yyyy << endl;
}

void exit() {
    cout << "Thanks for using my program.\n";
}

void displayMenu() {
    rowStar();
    cout << "\t1\t Convert from Calendar to Julian Date\n";
    cout << "\t2\t Convert from Julian to Calendar Date\n";
    cout << "\t3\t Exit\n";
    rowStar();
}