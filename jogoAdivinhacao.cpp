#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
   cout << "***************************************" << endl;
   cout << "* Bem-vindes ao jogo de adivinhação ! *" << endl;
   cout << "***************************************" << endl;

   cout << "Escolha o nível de dificuldade do jogo:" << endl;
   cout << "Fácil (F), Médio (M) ou Difícil(D)" << endl;

   char dificuldade;
   cin >> dificuldade;

   int numero_de_tentativas;

   if (dificuldade == 'F')
   {
      numero_de_tentativas = 15;
   }
   else if (dificuldade == 'M')
   {
      numero_de_tentativas = 10;
   }
   else
   {
      numero_de_tentativas = 5;
   }

   srand(time(NULL));
   const int NUMERO_SECRETO = rand() % 100;

   bool nao_acertou = true;
   int tentativas = 0;

   double pontos = 1000.0;

   for (tentativas = 1; tentativas <= numero_de_tentativas; tentativas++)
   {
      int chute;
      cout << "Tentativa " << tentativas << endl;
      cout << "Qual o seu chute? ";
      cin >> chute;
      cout << "O valor do seu chute é " << chute << endl;

      double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
      pontos -= pontos_perdidos;

      bool acertou = chute == NUMERO_SECRETO;
      bool chute_maior = chute > NUMERO_SECRETO;
      bool chute_menor = chute < NUMERO_SECRETO;

      if (acertou)
      {
         cout << "Parabéns! Você acertou o número secreto!" << endl;
         nao_acertou = false;
         break;
      }
      else if (chute_maior)
      {
         cout << "Seu chute foi maior que a do número secreto!" << endl;
      }
      else if (chute_menor)
      {
         cout << "Seu chute foi menor que a do número secreto!" << endl;
      }
   }

   cout << "FIM DE JOGO." << endl;
   if (nao_acertou)
   {
      cout << "Você perdeu o jogo... :(" << endl;
      cout << "O número secreto era " << NUMERO_SECRETO << endl;
      cout << "Tente novamente!" << endl;
   }
   else
   {
      cout << "Você acertou o número secreto em " << tentativas << " tentativas." << endl;
      cout.precision(2);
      cout << fixed;
      cout << "sua pontuação foi de " << pontos << " pontos." << endl;
   }
}