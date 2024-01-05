#include <iostream>
#include <vector>

using namespace std;

int maxExpertise(int n, vector<vector<bool>> conflicts, vector<int> expertise) {
    int maxExpertise = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        bool validTeam = true;
        int expertiseSum = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                expertiseSum += expertise[i];

                for (int j = i + 1; j < n; j++) {
                    if ((mask & (1 << j)) && conflicts[i][j]) {
                        validTeam = false;
                        break;
                    }
                }

                if (!validTeam) {
                    break;
                }
            }
        }

        if (validTeam) {
            maxExpertise = max(maxExpertise, expertiseSum);
        }
    }

    return maxExpertise;
}

int main() {
    int n, c;
    cin >> n >> c;

    vector<vector<bool>> conflicts(n, vector<bool>(n, false));

    for (int i = 0; i < c; i++) {
        int a, b;
        cin >> a >> b;

        conflicts[a - 1][b - 1] = true;
        conflicts[b - 1][a - 1] = true;
    }

    vector<int> expertiseLevels(n);
    for (int i = 0; i < n; i++) {
        cin >> expertiseLevels[i];
    }

    int res = maxExpertise(n, conflicts, expertiseLevels);
    cout << res << endl;

    return 0;
}