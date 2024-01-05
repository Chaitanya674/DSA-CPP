#include<iostream>
#include<vector>
using namespace std;
int vipcafe(vector<int>&arr, int pos)
{
    int in = -1;
    int maximum = -1;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (maximum < arr[i])
        {
            in = i;
            maximum = arr[i];
        }
    }
    if (in == pos)return 0;
    arr[in] = -1;

    for (int i = 0; i < in; i++)
    {
        if (arr[i] > 0)arr[i]++;
    }

    return 1 + vipcafe(arr, pos);
}
    int main() {
    int t, n;
    cin >> n;
    vector<int>arr(n);
    for (auto &i : arr)cin >> i;
    int b;
    cin >> b;
    b--;
    cout << 1 + vipcafe(arr, b) << endl;
    return 0;
}