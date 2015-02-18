//
//  main.cpp
//  Project2
//
//  Created by Enrique  on 2/12/15.
//  Copyright (c) 2015 Enrique . All rights reserved.
//

#include <iostream>
#include <iomanip>

using namespace std;

void rowStar();
void displayMenu();
void displayQueue(int queue[], int& index);
void dequeue(int queue[], int& index);
void enqueue(int queue[], int& index);
void exit();
void pause();

int main() {
    
    int userChoice = 0;
    int Q[10];
    
    int queue_index = -1;
    
    do {
        displayMenu();
        cin >> userChoice;
        if (userChoice == 1) { // display queue
            displayQueue(Q, queue_index);
        }
        else if (userChoice == 2) { // dequeue queue
            dequeue(Q, queue_index);
        }
        else if (userChoice == 3) { //enqueue into queue
            enqueue(Q, queue_index);
        }
        else if (userChoice == 4) { // exit program
            exit();
        } else {
            cout << "\nInvalid option. Please try again.\n";
        }
        
    } while (userChoice != 4);
    
    cout << "\nThank you for you choosing my program. Goodbye!\n";
    return 0;
}

void rowStar() {
    for (int i = 0; i < 50; i++) {
        cout << "*";
    }
    cout << endl;
}

void displayMenu() {
    cout << "\nChoose from one of the options below\n";
    rowStar();
    cout << "\t1\t Display Queue\n";
    cout << "\t2\t De-Queue - Exit from Queue\n";
    cout << "\t3\t En-Queue - Enter into Queue\n";
    cout << "\t4\t Exit\n";
    rowStar();
}

void displayQueue(int queue[], int& index) {
    if(index == -1) {
        cout << "\nThe Queue is currently empty, enter a value into the queue first or exit program.\n";
    }
    else {
        cout << endl;
        for (int i = 0; i <= index; i++) {
            cout << right << setw(5) << queue[i];
            if (i != index)
                cout << ",";
        }
        cout << endl;
        for (int i = 0; i <= index; i++) {
            cout << right << setw(3) << "Q[" << i  << "]";
            if (i != index)
                cout << ",";
            
        }
        cout << endl;
    }
}

void dequeue(int queue[], int& index) {
    if(index == -1) {
        cout << "\nThe Queue is empty. Nothing to De-Queue\n";
    }
    else {
        for (int i = 0; i <= index - 1; i++) {
            queue[i] = queue[i + 1];
        }
    }
    index--;
}

void enqueue(int queue[], int& index) {
    if (index == 9) {
        cout << "\nThe Queue is full. Cannot enter into queue.\n";
    }
    else {
        int userInput;
        cout << "\nWhat should I enter into the Queue.\n";
        cin >> userInput;
        queue[++index] = userInput;
    }
    cout << endl;
}

void exit() {
    // do nothing
    // mainly used for exiting out of program
}

void pause() {
    cout << "Press any button to continue...\n";
    getchar();
}
