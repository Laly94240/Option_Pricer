#include "main.h"
#include "CallOption.h"
#include "PutOption.h"
#include "BlackScholesPricer.h"
#include "CRRPricer.h"
#include <cmath>
#include <iostream>

using namespace std;

int main()
{
    double S = 100.0;
    double K = 100.0;
    double T = 1.0;
    double r = 0.05;
    double sigma = 0.2;

    // Création des deux options (attention : vérifie l'ordre des paramètres dans CallOption.h : expiry puis strike)
    CallOption call(T, K);
    PutOption put(T, K);

    // Création des pricers en passant l'adresse (&) des options
    BlackScholesPricer callPricer(&call, S, r, sigma);
    BlackScholesPricer putPricer(&put, S, r, sigma);

    // Affichage des résultats (callPricer() appelle ton operator())
    cout << "=== Test Black-Scholes ===" << endl;
    cout << "Call Price : " << callPricer() << " (attendu : ~10.4506)" << endl;
    cout << "Call Delta : " << callPricer.delta() << " (attendu : ~0.6368)" << endl;
    cout << endl;
    cout << "Put Price  : " << putPricer() << " (attendu : ~5.5735)" << endl;
    cout << "Put Delta  : " << putPricer.delta() << " (attendu : ~-0.3632)" << endl;

    // Vérification rapide de la parité Call-Put : C - P = S - K * exp(-rT) (~4.8771)
    cout << "\nParite C - P : " << callPricer() - putPricer() << " (attendu : ~4.8771)" << endl;

    // === Test CRR ===
    // Parametres calibres pour converger vers Black-Scholes : h = T/N
    int N = 15;
    double h = T / N;
    double R = exp(r * h) - 1.0;
    double U = exp(r * h + sigma * sqrt(h)) - 1.0;
    double D = exp(r * h - sigma * sqrt(h)) - 1.0;

    CRRPricer crrCall(&call, N, S, U, D, R);
    CRRPricer crrPut(&put, N, S, U, D, R);

    cout << "\n=== Test CRR (N = " << N << ") ===" << endl;
    cout << "Call CRR (arbre)        : " << crrCall() << endl;
    cout << "Call CRR (formule close): " << crrCall(true) << endl;
    cout << "Put  CRR (arbre)        : " << crrPut() << endl;
    cout << "Put  CRR (formule close): " << crrPut(true) << endl;
    cout << "H(1,1) call             : " << crrCall.get(1, 1) << endl;

    return 0;
}