#include <bits/stdc++.h>

using namespace std;

int INF = 10000000;

int n;              
int c2;              
int melhorCaminho = INF; 

vector<int> p;     
vector<int> t;     


void viagem_bt(int i, int ultimo, int custo) {

    if (custo >= melhorCaminho){
       
       return; 
    } 

   
    if (p[n+1] - p[ultimo] <= 100) {
     
        melhorCaminho = min(melhorCaminho, custo);
        
        return;
    }

    // Se ultrapassar o índice n e ainda não chegar não há solução pelo caminho
    if (i > n){

        return;
    } 

    // ------------------------------------------------------------------
    // 1) pular o posto
    // ------------------------------------------------------------------
    if (p[i] - p[ultimo] <= 100) {

        viagem_bt(i + 1, ultimo, custo);
    }

    // ------------------------------------------------------------------
    // 2) tentar abastecer
    // ------------------------------------------------------------------
    if (p[i] - p[ultimo] <= 100) {

        viagem_bt(i + 1, i, custo + t[i]);
    }
}

int main() {
    
    cin >> n;
    p.resize(n + 2);
    t.resize(n + 2);

    
    for (int i = 1; i <= n; i++){

        cin >> p[i] >> t[i];
    }


    cin >> c2;


    p[0] = 0; 
    t[0] = 0;
    
    p[n+1] = c2; 
    t[n+1] = 0;



    // bt chamada
    viagem_bt(1, 0, 0);

  
    cout << melhorCaminho << endl;

    return 0;
}
