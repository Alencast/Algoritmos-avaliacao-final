#include <bits/stdc++.h>
using namespace std;

//var globais
int n;
int x;

vector<int> preco;
vector<int> paginas;

vector<vector<int>> memo;

int livro_dp(int i, int orcamento) {
    // casos base
    if (i == n)
        return 0;
    
    if (memo[i][orcamento] != -1)
        return memo[i][orcamento];
    
    // Opção 1: Não comprar o livro 
    int res = livro_dp(i + 1, orcamento);
    
    // Opção 2: Comprar o livro i, se houver orcamento
    if (orcamento >= preco[i])
        res = max(res, livro_dp(i + 1, orcamento - preco[i]) + paginas[i]);
    
  
    memo[i][orcamento] = res;
    return res;
}

int main() {
    
    cin >> n >> x;
    
    preco.resize(n);
    paginas.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> preco[i] >> paginas[i];
    }
    
    
    memo.assign(n, vector<int>(x + 1, -1));//iniciar memo com -1
    
    cout << livro_dp(0, x) << endl;
    
    return 0;
}
