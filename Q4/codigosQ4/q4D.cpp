#include <iostream>
#include <vector>

using namespace std;

void tabelaSYSOUT(const vector<vector<int>>& dp) {
    
    for (int i = 0; i < dp.size(); i++){
        for (int j = 0; j < dp[i].size(); j++){
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main(){
    int C, V;
    cin >> C;  
    vector<int> moedas(C);
    for (int i = 0; i < C; i++){
         cin >> moedas[i];
    }
    cin >> V;  

    // Definição d a tabela dp:
    // dp[i][v] = número de formas de obter o valor v usando as moedas dos índices i até C-1.
    // Teremos C+1 linhas e V+1 coluna
    vector<vector<int>> dp(C + 1, vector<int>(V + 1, 0));

    for (int i = 0; i <= C; i++){
        dp[i][0] = 1;
    }
   
    for (int i = C - 1; i >= 0; i--){
        
        for (int v = 1; v <= V; v++){
         
            dp[i][v] = dp[i + 1][v];
            
            if (v >= moedas[i]){
                dp[i][v] += dp[i][v - moedas[i]];
            }
        }
    }
    
  
    cout << "Tabela DP:\n";
    tabelaSYSOUT(dp);
    
    // O resultado final é dp[0][V]:
    cout << dp[0][V] << endl;
    
    return 0;
}
