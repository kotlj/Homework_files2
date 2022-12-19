
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int choise;
    cout << "choose task:\n1 - equal strings?\n2 - count\n3 - Caesar code\n";
    cin >> choise;
    if (choise == 1)
    {
        ifstream first;
        ifstream second;
        string frFyle1;
        string frFyle2;
        first.open("equal_1.txt");
        second.open("equal_2.txt");
        if (first.is_open() && second.is_open())
        {
            while (!first.eof() && !second.eof())
            {
                getline(first, frFyle1);
                getline(second, frFyle2);
                if (frFyle1 != frFyle2)
                {
                    cout << frFyle1 << '\n' << frFyle2 << '\n';
                }
            }
            first.close();
            second.close();
        }
    }
    else if (choise == 2)
    {
        int counter = 0;
        int counterVowel = 0;
        int counterConsn = 0;
        int counterNumbs = 0;
        int counterStr = 0;
        char* symb = new char[1];
        string buff;
        ifstream file0;
        file0.open("task_2.txt");
        if (file0.is_open())
        {
            while (!file0.eof())
            {
                getline(file0, buff);
                counterStr++;
                for (int i = 0; buff[i] != '\0'; i++)
                {
                    *symb = buff[i];
                    if (*symb >= 65 && *symb <= 90) //LowerCase
                    {
                        counter;
                        if (*symb >= 66 && *symb <= 68 || *symb >= 70 && *symb <= 72 || *symb >= 74 && *symb <= 78 ||
                            *symb >= 80 && *symb <= 84 ||
                            *symb >= 86 && *symb <= 88 || *symb == 90)
                        {
                            counterConsn++;
                        }
                        else
                        {
                            counterVowel++;

                        }
                    }
                    else if (*symb >= 97 && *symb <= 122) //UpperCase
                    {
                        counter++;
                        if (*symb >= 98 && *symb <= 100 || *symb >= 102 && *symb <= 104 || *symb >= 106 && *symb <= 110
                            || *symb >= 112 && *symb <= 116 ||
                            *symb >= 118 && *symb <= 120 || *symb == 122)
                        {
                            counterConsn++;
                        }
                        else
                        {
                            counterVowel++;
                        }
                    }
                    else if (*symb >= 48 && *symb <= 57) //numbers
                    {
                        counter++;
                        counterNumbs++;
                    }
                    else if (*symb > 32 && *symb < 48 || *symb > 90 && *symb < 97 || *symb > 122 && *symb < 128 ||
                        *symb > 248 && *symb < 254)
                    {
                        counter++;
                    }
                }
            }
            cout << "Number of symbols: " << counter << '\n' << "Number of vowels: " << counterVowel << '\n' <<
                "Number of consn: " << counterConsn << '\n' << "Number of numbers: " << counterNumbs << '\n' <<
                "Number of strings: " << counterStr << '\n';
        }
        file0.close();
        delete[] symb;
    }
    else if (choise == 3)
    {
        int shift = 0;
        char* symb = new char[1];
        cout << "Enter number of shift:\n";
        cin >> shift;
        ifstream readFrom;
        ofstream writeTo;
        readFrom.open("codeText.txt");
        writeTo.open("codetText.txt");
        if (readFrom.is_open() && writeTo.is_open())
        {
            while (!readFrom.eof())
            {
                readFrom.read(symb, 1);
                if (*symb > 'a' && *symb < 'z')
                {
                    writeTo << char((*symb + shift) % ('z' + 1));
                }
                else if (*symb > 'A' && *symb < 'Z')
                {
                    writeTo << char((*symb + shift) % ('Z' + 1));
                }
                else
                {
                    writeTo << *symb;
                }
            }
            readFrom.close();
            writeTo.close();
            delete[] symb;
        }
    }
    else
    {
        cout << "ERROR: INVALID OPTION";

    }
}