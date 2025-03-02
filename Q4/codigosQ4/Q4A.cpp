#include <bits/stdc++.h>

using namespace std;

// Função que retorna o número de formas de obter o valor V
int caminho(int V, int i, const vector<int>& moedas) {

    // Casos base
    if (V == 0)
        return 1;
    
    if (V < 0 || i >= moedas.size())
        return 0;
    
    
    if (V < moedas[i])
        return caminho(V, i + 1, moedas);
    
    
    return caminho(V, i + 1, moedas) + caminho(V - moedas[i], i, moedas);
}

int main(){
    int C, V;
    
    cin >> C;
    vector<int> moedas(C);
    for (int i = 0; i < C; i++){
         cin >> moedas[i];
    }

    cin >> V;
    
    cout <<caminho(V, 0, moedas) << endl;
    
    return 0;
}
//3
//2 3 5
//9

//caminhos: 3