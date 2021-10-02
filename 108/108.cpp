#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

int kadane(int *arr, int len)
{
    int max_ending_here = arr[0], max_so_far = arr[0];
    int length = length;
    for (int i = 1; i < len; i++)
    {
        max_ending_here = max(arr[i], max_ending_here + arr[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}

void getTempArray(int **array, int *temp_array, int left_col, int right_col, int length)
{
    for (int i = 0; i < length; i++)
    {
        temp_array[i] = 0;
        for (int j = left_col; j <= right_col; j++)
        {
            temp_array[i] += array[i][j];
        }
    }
}

int main()
{
    int N, left_col, right_col, temp;

    // 讀取資料
    while (scanf("%d", &N)!=EOF)
    {
        int maximum = -128;
        int array[N][N];
        int *pointers[N];
        int temp_array[N];

        for (int i = 0; i < N; i++)
        {
            pointers[i] = array[i];
        }
        
        // 寫入array
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> array[i][j];
                
            }
        }

        // 由左至右找出最大範圍
        for (left_col = 0; left_col < N; left_col++)
        {
            for (right_col = left_col; right_col < N; right_col++)
            {
                getTempArray(pointers, temp_array, left_col, right_col, N);
                temp = kadane(temp_array, N);
                if (maximum < temp)
                    maximum = temp;
            }
        } 

        cout << maximum << endl;
    }
    
    return 0;
}