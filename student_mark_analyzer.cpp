#include <iostream>
using namespace std;

void ReadMarks(int marks[], int n);
int FindTotal(int marks[], int n);
double FindAverage(int marks[], int n);
int FindHighest(int marks[], int n);
int FindLowest(int marks[], int n);
int CountPassed(int marks[], int n);
void PrintReport(int marks[], int n);

int main()
{
        int n;
        char choice;
    do
    {
        int marks[100];

        cout << "\nSTUDENT MARK ANALYZER\n";
        cout << "\n---------------------\n";

        cout << "Enter number of students: ";
        cin >> n;

        while(n < 1 || n > 100)
        {
            cout << "Invalid input! Enter between 1-100";
            cin >> n;
        }

        ReadMarks(marks, n);
        PrintReport(marks, n);
        
        cout << "\nDo you wants to repeat? (y/n): ";
        cin >> choice;
    } while(choice == 'Y'|| choice == 'y');
    
    cout << "\nTHANK YOU\n";

    return 0;

}
// Functions 
void ReadMarks(int marks[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Student" << i + 1 << ": ";
        cin >> marks[i];

        while(marks[i] < 0 || marks[i] > 100)
        {
            cout << "Invalid mark! Enter Again: ";
            cin >> marks[i];
        }
    }
}

int FindTotal(int marks[], int n)
{
    int total = 0;
    for(int i = 0; i < n; i++)
    {
        total = total + marks[i];
    }
    return total;
}

double FindAverage(int marks[], int n)
{
    return (double)FindTotal(marks, n) / n;
}

int FindHighest(int marks[], int n)
{
    int highest = marks[0];

    for(int i = 1; i < n; i++)
    {
        if(marks[i] > highest)
        {
            highest = marks[i];
        }
    }
    return highest;
}

int FindLowest(int marks[], int n)
{
    int lowest = marks[0];
    
    for(int i = 1; i < n; i++)
    {
        if(marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}
int CountPassed(int marks[], int n)
{
    int passed = 0;

    for(int i = 0; i < n; i++)
    {
        if(marks[i] > 40)
        {
            passed++;
        }
    }
    
    return passed;
}

void PrintReport(int marks[], int n)
{
    int total = FindTotal(marks, n);
    int passed = CountPassed(marks, n);
    int failed = n - passed;

    cout << "\nSTUDENT REPORT\n";
    cout << "\n--------------\n";
    cout << "Total Students: " << n << endl;
    cout << "Total Marks: " << total << endl;
    cout << "Average: " << FindAverage(marks, n) << endl;
    cout << "Highest Mark: " << FindHighest(marks, n) << endl;
    cout << "Lowest Mark: " << FindLowest(marks, n) << endl;
    cout << "Passed Students: " << passed << endl;
    cout << "Failled Students: " << failed << endl;
}
