#include <bits/stdc++.h> // Includes all standart libraries but isn't efficient

using namespace std;

void input(long long int &myNumber, string &whichOperation);
void inputErrorNotCin(long long int &myNumber, string whichOperation);
void inputErrorNotBinary(long long int &myNumber, string whichOperation);
string outputBy();
void decimalToBinaryConsole(long long int myNumber);
void decimalToBinaryFile(long long int myNumber);
void binaryToDecimalConsole(long long int myNumber);
void binaryToDecimalFile(long long int myNumber);

int main()
{
    string whichOperation; // Operation that the user chooses
    long long int myNumber; // Users number
    input(myNumber, whichOperation);
    string whichOutput = outputBy(); // Output that the user chooses
    system("cls"); // Clearing the console
    if(whichOperation == "1" && whichOutput == "1") decimalToBinaryConsole(myNumber);
    else if(whichOperation == "1" && whichOutput == "2") decimalToBinaryFile(myNumber);
    else if(whichOperation == "2" && whichOutput == "1") binaryToDecimalConsole(myNumber);
    else if(whichOperation == "2" && whichOutput == "2") binaryToDecimalFile(myNumber);

    return 0;
}

void input(long long int &myNumber, string &whichOperation)
{
    whichOperation = "0";
    while(whichOperation == "0")
    {
        cout << "Decimal to binary (1)" << endl;
        cout << "Binary to decimal (2)" << endl;
        cout << "Which operation would you like to use?" << endl;
        cin >> whichOperation;
        if(whichOperation == "1")
        {
            system("cls");
            cout << "Write a decimal number: " << endl;
            cin >> myNumber;
            if(!cin) inputErrorNotCin(myNumber, whichOperation); // If myNumber isn't a number.
        }
        else if(whichOperation == "2")
        {
            system("cls");
            cout << "Write a binary number: " << endl;
            cin >> myNumber;
            if(!cin) inputErrorNotCin(myNumber, whichOperation); // If myNumber isn't a number.
            else
            {
                int n = log10(myNumber)+1; // Length of the number.
                int myNumberArray[n];
                long long int myNumberOriginal = myNumber; // Storing the original number.
                for(int i = 0; i < n; i++)
                {
                    myNumberArray[i] = myNumber % 10;
                    myNumber /= 10;
                    if(myNumberArray[i] != 0 && myNumberArray[i] != 1)
                    {
                        inputErrorNotBinary(myNumber, whichOperation); // If the number provided by the user isn't a binary number.
                        break;
                    }
                }
                myNumber = myNumberOriginal; // Because we changed myNumber in a cycle.
            }
        }
        else   // whichOperation isn't 1 or 2
        {
            system("cls");
            cout << "Choose a correct operation!" << endl;
            cout << endl;
            cout << endl;
            whichOperation = "0";
        }
    }
}

void inputErrorNotCin(long long int &myNumber, string whichOperation)
{
    bool loop = false;
    system("cls");
    cout << "You did not enter a number. Try it again." << endl;
    cout << endl;
    cin.clear();
    cin.ignore(10000, '\n');
    cin >> myNumber;
    if(whichOperation == "2")
    {
        int n = log10(myNumber)+1;
        int myNumberArray[n];
        long long int myNumberOriginal = myNumber;
        for(int i = 0; i < n; i++)
        {
            myNumberArray[i] = myNumber % 10;
            myNumber /= 10;
            if(myNumberArray[i] != 0 && myNumberArray[i] != 1)
            {
                inputErrorNotBinary(myNumber, whichOperation);
                break;
            }
        }
        myNumber = myNumberOriginal;
    }

    if(!cin)

    {
        loop = true;
        while(loop)
        {
            system("cls");
            cout << "You did not enter a number. Try it again." << endl;
            cout << endl;
            cin >> myNumber;
            if(!cin)
            {
                cin.clear();
                cin.ignore(10000, '\n');
            }
            else
            {
                loop = false;
                system("cls");
            }
        }
    }
}

void inputErrorNotBinary(long long int &myNumber, string whichOperation)
{
    system("cls");
    bool ismyNumberGood = false;
    while(!ismyNumberGood)
    {
        cout << "You did not enter a binary number. Try it again." << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> myNumber;
        if(!cin) inputErrorNotCin(myNumber, whichOperation);
        int n = log10(myNumber)+1;
        int myNumberArray[64];
        long long int myNumberOriginal = myNumber;
        for(int i = 0; i < n; i++)
        {
            myNumberArray[i] = myNumber % 10;
            myNumber /= 10;
            if(myNumberArray[i] != 0 && myNumberArray[i] != 1)
            {
                ismyNumberGood = false;
                break;
            }
            else ismyNumberGood = true;
        }
        if(ismyNumberGood) myNumber = myNumberOriginal;
    }
}

string outputBy()
{
    string whichOutput = "0";
    while(whichOutput == "0")
    {
        cout << "Console (1)" << endl;
        cout << "Text file (2)" << endl;
        cout << "Which method of output would you like to use?" << endl;
        cin >> whichOutput;
        if(whichOutput != "1" && whichOutput != "2")
        {
            system("cls");
            cout << "Choose a correct method of output!" << endl;
            cout << endl;
            cout << endl;
            whichOutput = "0";
        }
    }
    return whichOutput;
}

void decimalToBinaryConsole(long long int myNumber)
{
    cout << "Decimal " << myNumber << " converted to binary:" << endl;
    int binaryByParts[64];
    if(myNumber == 0 ) cout << "It's 0, of course." << endl;
    else if(myNumber == 1) cout << "It's 1, of course." << endl;
    else if(myNumber == -1) cout << "It's -1, of course." << endl;
    else
    {
        int i; // We will need this number for a later for cycle
        cout << endl;
        for(i = 0; myNumber != 0; i++)
        {
            double myNumberCout = myNumber;
            cout << myNumber << "/2 = " << myNumberCout/2 << ", remainder: " << myNumber % 2 << endl;
            cout << endl;
            binaryByParts[i] = myNumber % 2;
            myNumber /= 2;
        }
        cout << "The answers shown were vice versa, the correct answer looks like:" << endl;
        cout << endl;

        // Because we got the binary number backwards, we need to insert it from right to left by the for cycle below.

        int j = i-1;
        bool decimalIsNegative = false;
        for(i = i-1; i >= 0; i--)   // Checking if the inserted number by the user is negative.
        {
            if(binaryByParts[i] < 0)
            {
                decimalIsNegative = true;
                binaryByParts[i] *= -1; // If true, converting the number from negative to positive.
            }
        }

        int checkIfFirstNumber = j;
        for(j = j; j >= 0; j--)
        {
            if(!decimalIsNegative) cout << binaryByParts[j];
            else if(j == checkIfFirstNumber) cout << "-" << binaryByParts[j]; // If the number was negative, we start out with a string declaring that it was negative.
            else cout << binaryByParts[j];
        }
    }
    cout << endl;
}

void decimalToBinaryFile(long long int myNumber)
{
    ofstream fr("result.txt"); // Opening the text file.
    fr << "Decimal " << myNumber << " converted to binary:" << endl;
    int binaryByParts[64];
    if(myNumber == 0 ) fr << "It's 0, of course." << endl;
    else if(myNumber == 1) fr << "It's 1, of course." << endl;
    else if(myNumber == -1) fr << "It's -1, of course." << endl;
    else
    {
        int i;
        fr << endl;
        for(i = 0; myNumber != 0; i++)
        {
            double myNumberCout = myNumber;
            fr << myNumber << "/2 = " << myNumberCout/2 << ", remainder: " << myNumber % 2 << endl;
            fr << endl;
            binaryByParts[i] = myNumber % 2;
            myNumber /= 2;
        }
        fr << "The answers shown were vice versa, the correct answer looks like:" << endl;
        fr << endl;
        int j = i-1;
        bool decimalIsNegative = false;
        for(i = i-1; i >= 0; i--)
        {
            if(binaryByParts[i] < 0)
            {
                decimalIsNegative = true;
                binaryByParts[i] *= -1;
            }
        }
        int checkIfFirstNumber = j;
        for(j = j; j >= 0; j--)
        {
            if(!decimalIsNegative) fr << binaryByParts[j];
            else if(j == checkIfFirstNumber) fr << "-" << binaryByParts[j];
            else fr << binaryByParts[j];
        }
    }
    fr.close(); // Closing the text file.
    cout << "The answer is outputed by a text file." << endl;
}

void binaryToDecimalConsole(long long int myNumber)
{
    cout << "Binary " << myNumber << " converted to decimal:" << endl;
    int decimalNumber = 0; // Our final answer will be stored here.
    if(myNumber == 0) cout << "It's 0, of course." << endl;
    else if(myNumber == 1) cout << "It's 1, of course." << endl;
    else if(myNumber == -1) cout << "It's -1, of course." << endl;
    else
    {
        cout << endl;
        for(int i = 0; myNumber != 0; i++)
        {
            cout << "The number we have at the moment: " << decimalNumber << " | Operation: " << myNumber << " % 10 = " << myNumber % 10 << " * 2^" << i << " = " << decimalNumber << " + " << myNumber % 10 * pow(2, i) << endl;
            cout << endl;
            decimalNumber += myNumber % 10 * pow(2, i);
            myNumber /= 10;
        }
        cout << "The final answer is " << decimalNumber << endl;
    }
}

void binaryToDecimalFile(long long int myNumber)
{
    ofstream fr("result.txt");
    fr << "Binary " << myNumber << " converted to decimal:" << endl;
    int decimalNumber = 0;
    if(myNumber == 0) fr << "It's 0, of course." << endl;
    else if(myNumber == 1) fr << "It's 1, of course." << endl;
    else if(myNumber == -1) fr << "It's -1, of course." << endl;
    else
    {
        fr << endl;
        for(int i = 0; myNumber != 0; i++)
        {
            fr << "The number we have at the moment: " << decimalNumber << " | Operation: " << myNumber << " % 10 = " << myNumber % 10 << " * 2^" << i << " = " << decimalNumber << " + " << myNumber % 10 * pow(2, i) << endl;
            fr << endl;
            decimalNumber += myNumber % 10 * pow(2, i);
            myNumber /= 10;
        }
        fr << "The final answer is: " << decimalNumber << endl;
    }
    fr.close();
    cout << "The answer is outputed by a text file." << endl;
}
