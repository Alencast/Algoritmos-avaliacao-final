#include <bits/stdc++.h>

using namespace std;

const int INF = 10000000;

int viagem_dp(int n, int c2, vector<int>& p, vector<int>& t) {
    
    vector<vector<int>> dp(n + 10, vector<int>(n + 2, INF));
    
    dp[0][0] = 0;
    
    for (int i = 1; i <= n + 1; i++) {
        
        for (int j = 0; j < i; j++) {
            
            if (p[i] - p[j] <= 100) {
                
                dp[i][j] = min(dp[i][j], dp[j][j]);
                dp[i][i] = min(dp[i][i], dp[j][j] + t[i]);
            }
        }
    }
    
    int melhorCaminho = INF;
    
    for (int j = 0; j <= n + 1; j++) {
        
        melhorCaminho = min(melhorCaminho, dp[n + 1][j]);
    }
    
    return melhorCaminho;
}

int main() {
    
    int n, c2;
    cin >> n;
    vector<int> p(n + 2), t(n + 2);
    
    for (int i = 1; i <= n; i++) {
        
        cin >> p[i] >> t[i];
    }
    
    cin >> c2;
    p[0] = 0; t[0] = 0;
    p[n + 1] = c2; t[n + 1] = 0;
    
    cout << viagem_dp(n, c2, p, t) << endl;
    
    return 0;
}
