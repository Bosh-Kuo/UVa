#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int main() {
    // bin[3][3] = {{b0, g0, c0},{b1, g1, c1}, {b2, g2, c2}}
    int bin[3][3];
    int color_order[6][3] = {{0,2,1},{0,1,2},{2,0,1},{2,1,0},{1,0,2},{1,2,0}};  //按照"b,c,g"字母從小到大排列
    int total = 0 , min, temp, orderIndex;
    char color[4] = "BGC";  // color index: B:0, G:1, C:2
    while ((scanf("%d", &bin[0][0])) != EOF)
    {
        total = 0;
        min = INT_MAX;

        // 讀取input
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {   
                if (i == 0 && j == 0)
                {
                    total += bin[i][j];
                    continue;
                }
                scanf("%d", &bin[i][j]);
                total += bin[i][j];
            }
        }
        
        // 計算各種組合最小值
        for (int i = 0; i < 6; i++)
        {
            temp = total - (bin[0][color_order[i][0]] + bin[1][color_order[i][1]] + bin[2][color_order[i][2]]);
            if (temp < min)
            {
                min = temp;
                orderIndex = i;
            }
        }

        //印出結果
        for (int i = 0; i < 3; i++)
        {
            cout << color[color_order[orderIndex][i]];
        }
        cout << " " << min << endl;
    }
    return 0;
}