#include <bits/stdc++.h>

using namespace std;

// Definindo um valor grande para representar "infinito"
const int INF = 10000000;

int troco(const vector<int>& moedas, int V) {
    // Casos base:
    if (V == 0)
        return 0;
    // Se V for negativo, não dá pra formar o valor
    if (V < 0)
        return INF;

    int minMoedas = INF;
  
    for (int valorMoeda : moedas) {
        // 1 + chamada rec
        minMoedas = min(minMoedas, 1 + troco(moedas, V - valorMoeda));
    }
    return minMoedas;
}

int main() {
    
    vector<int> C = {1, 3, 5}; 
    
    int V = 13; // Valor do troco

    int resultado = troco(C, V);
    
    if (resultado > INF){
        cout << "Não é possível formar o valor " << V << " com as moedas fornecidas." << endl;
    }
    
    else{
        cout << "Para formar o troco " << V << "são necessárias " << resultado<<" moedas" << endl;
    }
    return 0;
}
