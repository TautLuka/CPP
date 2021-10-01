#include <iostream>
using namespace std;

void Calculations(char ch, char arrayChar[], int modifiedNum[], int size,  int arrayNum[]);

int main()
{
    int arrayNum[100];
    char arrayChar[100];
    int modifiedNum[100];

    int size = 0;

    int min=INT_MAX;

    cin>>size;

    for(int i=0; i<size; i++)
    {
        cin>>arrayChar[i]>>arrayNum[i];
    }

    Calculations('R',arrayChar,modifiedNum, size, arrayNum);
    Calculations('G',arrayChar,modifiedNum, size, arrayNum);
    Calculations('M',arrayChar,modifiedNum, size, arrayNum);
    Calculations('J',arrayChar,modifiedNum, size, arrayNum);
}

void Calculations(char ch, char arrayChar[], int modifiedNum[], int size, int arrayNum[])
{
    int a = 0;
    int temp=0;

    for(int i=0; i<size; i++)
    {
        if(arrayChar[i]==ch)
        {
            modifiedNum[a] = arrayNum[i];
            a++;
        }
    }

    for(int i=0; i<a-1; i++)
    {
        for(int j=0; j<a-i-1; j++)
        {
            if(modifiedNum[j]>modifiedNum[j+1])
            {
                temp = modifiedNum[j];
                modifiedNum[j] = modifiedNum[j+1];
                modifiedNum[j+1] = temp;
            }
        }
    }


    for(int i=0; i<a; i++)
    {
        if(modifiedNum[i] == modifiedNum[i+1]- 1)
        {
            cout<<ch<<" "<<modifiedNum[i]<<" ";

        }
        else if(modifiedNum[i-1]+1 == modifiedNum[i])
        {
            cout<<ch<<" "<<modifiedNum[i]<<" ";
            cout<<endl;
        }

    }
    cout<<endl;
}

