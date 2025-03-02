#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, X;
    cin >> n >> X;  // n número de livros, x orçamento disponível
    
    vector<int> preco(n), paginas(n);
    for (int i = 0; i < n; i++) {
        cin >> preco[i] >> paginas[i];
    }
    
  
    vector<vector<int>> livro_dp(n + 1, vector<int>(X + 1, 0));
    
   
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= X; j++) {
            
            livro_dp[i][j] = livro_dp[i - 1][j];
            
             if (j >= preco[i - 1]) {
                livro_dp[i][j] = max(livro_dp[i][j], livro_dp[i - 1][j - preco[i - 1]] + paginas[i - 1]);
            }
        }
    }
    
    cout << livro_dp[n][X] << endl;
    return 0;
}
