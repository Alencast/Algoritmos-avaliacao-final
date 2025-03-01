#include <bits/stdc++.h>

using namespace std;

int INF = 10000000;

int n;              
int c2;              
vector<int> p;     
vector<int> t;     

// Função que retorna o menor custo para completar a viagm

int viagem_bt(int i, int ultimo, int custo) {
   
    if (p[n+1] - p[ultimo] <= 100)  {
        return custo;
    }
    // Se não há mais postos para verificar  e ainda não conseguimos chegar, o problema não tem solução
    if (i > n) {
        
        return INF;
    }

    int ans = INF;
    
    if (p[i] - p[ultimo] <= 100) {
        ans = min(ans, viagem_bt(i + 1, ultimo, custo));
    }
    
    if (p[i] - p[ultimo] <= 100) {
        ans = min(ans, viagem_bt(i + 1, i, custo + t[i]));
    }
    return ans;
}

int main() {
    cin >> n;
    p.resize(n + 2);
    t.resize(n + 2);
    
    
    for (int i = 1; i <= n; i++){
        cin >> p[i] >> t[i];
    }
    
    cin >> c2;
    
    // C1 e C2
    p[0] = 0; 
    t[0] = 0;
    p[n+1] = c2; 
    t[n+1] = 0;
    
    int resultado = viagem_bt(1, 0, 0);
    cout << resultado << endl;
    
    return 0;
}
