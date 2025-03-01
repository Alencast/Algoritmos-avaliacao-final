#include <bits/stdc++.h>
using namespace std;

const int INF = 10000000;


int topDownMemo(vector<int>& moedas, int V, vector<int>& memo) {
    
    // Casos base:
    if (V == 0) return 0;

    
    if (V < 0) return INF;

    // valor já foi caluclado?
    if (memo[V] != -1){
        
        return memo[V];
    } 

    int minMoedas = INF;
    
    for (int moeda : moedas) {
        minMoedas = min(minMoedas, 1 + topDownMemo(moedas, V - moeda, memo));
    }

    memo[V] = minMoedas; //salvar o valor da moeda atual
    return minMoedas;
}

int main() {
    vector<int> moedas = {1, 3, 5}; 
    int V = 13; 
    vector<int> memoization(V + 1, -1); 

    int resultado = topDownMemo(moedas, V, memoization);

    if (resultado >= INF) {
        cout << "Não é possível formar o valor " << V << endl;
    } else {
        cout << "Para formar o troco " << V << " são necessárias " << resultado << " moedas." << endl;
    }

    return 0;
}
