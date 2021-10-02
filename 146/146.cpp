#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

void swap(char *c1, char *c2)
{
    char temp = *c1;
    *c1 = *c2;
    *c2 = temp;  
}

int main()
{   
    char code[51];
    int critical_index, localMax_index;
    bool descend = true;

    while(cin.getline(code, 51))
    {
        descend = true;
        // 讀取結束
        if (!strcmp(code,"#"))
            break;

        // ex: 136542, 找出3這個位置
        for (int i = strlen(code); i>=1; i--)
        { 
            if (code[i] > code[i-1])
            {
                critical_index = i-1;
                localMax_index = i;
                // localMax ＝ code[i];
                descend = false;
                break;
            }
        }

        // 若本來就降冪排列則印出No Successor
        if (descend == true)
        {
            cout << "No Successor\n";
        }
        else
        {
            // 找出大於critical但小於等於localMax的值，使其與critical交換位置
            for (int i = strlen(code); i > critical_index ; i--)
            {
                if (code[i] <= code[localMax_index] && code[i] > code[critical_index])
                {
                    swap(&code[critical_index], &code[i]);
                    break;
                }
            }
            
            sort(code + localMax_index, code + strlen(code));
            cout << code << endl;
        }
    }

    return 0;
}