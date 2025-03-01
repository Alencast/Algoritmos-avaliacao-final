#include <bits/stdc++.h>

//using namespace std;

void trocoMetodoGuloso(const std::vector<int>& listaDemoedas, int valor) {
    
    std::vector<int> quantidades(listaDemoedas.size(), 0); 

    for (int i = listaDemoedas.size() - 1; i >= 0; i--) { 
        quantidades[i] = valor / listaDemoedas[i]; // Pegar a maior qtd possível da moeda
        valor %= listaDemoedas[i];
    }

   
    for (size_t i = 0; i < listaDemoedas.size(); i++) {
        if (quantidades[i] > 0) {
            std::cout << "Moeda  de " << listaDemoedas[i] << ": " << quantidades[i] <<std::endl;
        }
    }
}

int main() {
    
    int numero; 
    int valor;

    std::cout << "Informe a quantidade de moedas disponíveis: ";
    std::cin >> numero;

    std::vector<int> S(numero);
    
    std::cout << "Digite os valores das moedas ";
    // S = (1, 2, 5, 10, 20, 50, 100, 200, 500) e o valor a ser obtido v = 7.
    for (int i = 0; i < numero; i++) {
        std::cin >> S[i];
    }

    std::cout << "Digte o valor do troco: ";
    std::cin >> valor;

    trocoMetodoGuloso(S, valor);

    return 0;
}
