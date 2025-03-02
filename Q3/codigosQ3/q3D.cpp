#include <bits/stdc++.h>

using namespace std;

void tabelaSYSOUT(const vector<vector<int>> &dp) {
    for (int i = 0; i < dp.size(); i++){
        for (int j = 0; j < dp[i].size(); j++){
            cout << dp[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main(){
    int n, X;
    cin >> n >> X;  // n: número de livros, X: orçamento disponível
    
    vector<int> preco(n), paginas(n);
    for (int i = 0; i < n; i++){
         cin >> preco[i] >> paginas[i];
    }
    
   
    vector<vector<int>> dp(n + 1, vector<int>(X + 1, 0));
    
    for (int i = 1; i <= n; i++){
        
         for (int j = 0; j <= X; j++){
             
              
              dp[i][j] = dp[i - 1][j];
              
              if (j >= preco[i - 1]){
                  dp[i][j] = max(dp[i][j], dp[i - 1][j - preco[i - 1]] + paginas[i - 1]);
              }
         }
    }
    
    cout << "Tabela: " <<endl;
    tabelaSYSOUT(dp);
    
    cout << "\nMax pág: " << dp[n][X] << endl;
    
    return 0;
}
