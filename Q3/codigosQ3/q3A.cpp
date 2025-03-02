#include <bits/stdc++.h>
using namespace std;

int maxPaginas = 0;

void livro_bt(vector<int>& preco, vector<int>& paginas, int i, int orcamento, int paginasAtuais) {
   
    // verificação do final da lista e do orcamento
    
    if (i == preco.size() || orcamento <= 0) {
        
        maxPaginas = max(maxPaginas, paginasAtuais);
        
        return;
    }

    //não comprar o livro atual
    livro_bt(preco, paginas, i + 1, orcamento, paginasAtuais);

    // Opção 2: Comprar o livro atual, se houver orcamento
    if (orcamento >= preco[i]) {
        livro_bt(preco, paginas, i + 1, orcamento - preco[i], paginasAtuais + paginas[i]);
    }
}

int main() {
    int n, x;
    cin >> n >> x; 

    vector<int> preco(n), paginas(n);
    
    for (int i = 0; i < n; i++) {
        
        cin >> preco[i] >> paginas[i];
    }

    livro_bt(preco, paginas, 0, x, 0);

    cout << maxPaginas << endl;

    return 0;
}
