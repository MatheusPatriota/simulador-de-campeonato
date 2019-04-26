#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include "CalculoDeForca.hpp"
#include "FaseDeGrupos.hpp"
using namespace std;


int main() {

  // Estrutura resuzida apenas para testes
    string Times[10][7] = {{"Campinense", "77","72","77","76","100","80"},
                           {"Treze", "73","70","74","72","100","80"},
                           {"Botafogo", "80","76","81","78","100","80"},
                           {"Souza", "63","65","65","68","100","80"},
                           {"Nacional de Patos", "59","60","60","61","100","80"},
                           {"Serrano", "48","50","56","52","100","80"},
                           {"Atletico-PB", "58","61","62","59","100","80"},
                           {"Perilima", "46","50","59","46","100","80"},
                           {"Esporte de Patos", "57","62","61","57","100","80"},
                           {"CSP", "64","66","69","65","100","80"}};


    // 7 Linhas para o time e seus atributos e 2 linhas a quantidade de times
    string Grupo_A[7][5] = {{},  // Time
                            {"0","0","0","0","0"},  // Pontos
                            {"0","0","0","0","0"},  // Partidas
                            {"0","0","0","0","0"},  // Vitorias
                            {"0","0","0","0","0"},  // Empates
                            {"0","0","0","0","0"},  // Derrotas
                            {"0","0","0","0","0"}}; // Gols

    string Grupo_B[7][5] = {{},  // Time
                            {"0","0","0","0","0"},  // Pontos
                            {"0","0","0","0","0"},  // Partidas
                            {"0","0","0","0","0"},  // Vitorias
                            {"0","0","0","0","0"},  // Empates
                            {"0","0","0","0","0"},  // Derrotas
                            {"0","0","0","0","0"}}; // Gols


	srand((unsigned)time(NULL));
  setlocale(LC_ALL,"");

    string sorteio = SorteiroFaseDeGrupos(Times, Grupo_A, Grupo_B);

    vector<string> jogos = RealizandoOsJogosDaFaseDeGrupos(Times, Grupo_A, Grupo_B);

    cout << sorteio << endl;
    // cout << sleep(5); 
    int contador =5;
    cout << sleep(5);
    system("reset");
    
    cout << "---------- Jogos Grupo A ----------" << endl;
    cout << "Rodada 01\n" + jogos[0] << "\n" << endl;
    cout << "Rodada 02\n" + jogos[1] << "\n" << endl;
    cout << "Rodada 03\n" + jogos[2] << "\n" << endl;
    cout << "Rodada 04\n" + jogos[3] << "\n" << endl;
    cout << "Rodada 05\n" + jogos[4] << endl;

    cout << "---------- Jogos Grupo B ----------" << endl;
    cout << "Rodada 06\n" + jogos[5] << "\n" << endl;
    cout << "Rodada 07\n" + jogos[6] << "\n" << endl;
    cout << "Rodada 08\n" + jogos[7] << "\n" << endl;
    cout << "Rodada 09\n" + jogos[8] << "\n" << endl;
    cout << "Rodada 10\n" + jogos[9] << endl;

    cout << "---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------" << endl;
    string resul1 = getGrupoOrdenado(Grupo_A, "A");
    string resul2 = getGrupoOrdenado(Grupo_B, "B");
    cout <<  resul1;
    cout << "---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------" << endl;
    cout <<  resul2;

    vector<int> classificados_A = getClassificadosParaFinal(Grupo_A);
    vector<int> classificados_B = getClassificadosParaFinal(Grupo_B);
    cout << "---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ---------- ----------\n\n" << endl;

    cout << "Classificados para semifinal do Grupo A:" << endl;
    cout << Grupo_A[0][classificados_A[0]] << "\n" << Grupo_A[0][classificados_A[1]] << endl;

    cout << endl;

    cout << "Classificados para semifinal do Grupo B:" << endl;
    cout << Grupo_B[0][classificados_B[0]] << "\n" << Grupo_B[0][classificados_B[1]] << endl;

    return 0;

}