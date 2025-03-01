#include <bits/stdc++.h>

using namespace std;

const int INF = 10000000;

int trocoDP(const vector<int>& moedas, int V) {
    
    int n = moedas.size();
    // Cria a matriz dp
    vector<vector<int>> dp(n + 10, vector<int>(V + 1, INF));
    
  
    for (int i = 0; i < n; i++) {
        dp[i][0] = 0;
    }
    
    // Preencher a matriz
    
    for (int i = 1; i <= n; i++) {
        
        for (int j = 1; j <= V; j++) {
         
            dp[i][j] = dp[i - 1][j];
            
            // Se a moeda atual pode ser utilizada
          
            if (moedas[i] <= j) {
                
                dp[i][j] = min(dp[i][j], 1 + dp[i][j - moedas[i]]);
            }
        }
    }
    
    return dp[n][V];
}

int main() {
    vector<int> moedas = {1, 3, 5}; // Conjunto de moedas
    int V = 13;                     // Valor do troco

    int resultado = trocoDP(moedas, V);
    
    if (resultado >= INF)
        cout << "Não é possível formar o valor " << V << " com as moedas fornecidas." << endl;
    else
        cout << "Para formar o troco " << V << " são necessárias " << resultado << " moedas." << endl;
    
    return 0;
}
