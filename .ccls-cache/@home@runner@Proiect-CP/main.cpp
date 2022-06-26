#include <iostream>
#include <map>
#include <vector>
using namespace std;

// functie care returneaza suma bancnotelor
int suma(int *nr) {
  int sum = 0;
  int v[] = {1, 5, 10, 50};
  for (int i = 0; i < 4; i++)
    sum += nr[i] * v[i];

  return sum;
}
void automat() {

  cout << "AUTOMAT DE PARCARE" << endl;

  int pret;

  // citim pretul parcarii
  cout << "Pret parcare: ";
  cin >> pret;

  // verificam daca este in intervalul dorit
  while (pret < 3 || pret > 120) {
    cout << "Pret incorect!" << endl;
    return;
  }
  // declaram un vector cu valorile bancnotelor
  int v[] = {1, 5, 10, 50};
  int nr[4];

  // citim de la tastatura numarul de bancnote
  // de fiecare fel
  for (int i = 0; i < 4; i++) {
    if (i == 0)
      cout << "Bancnote de " << v[i] << " leu: ";
    else
      cout << "Bancnote de " << v[i] << " lei: ";
    cin >> nr[i];
  }

  cout << endl;
  // afisam costul parcarii
  cout << "Cost parcare: " << pret << endl;

  // afisam numarul de bancnote asociat
  // fiecarui tip de bancnota
  cout << "Bancnote introduse: ";
  for (int i = 0; i < 4; i++) {
    if (i != 0)
      cout << "                    ";
    cout << nr[i] << "x" << v[i] << endl;
  }
  // daca suma introduse este mai mica
  // decat costul parcarii
  // creditul va fi insuficient
  if (suma(nr) < pret) {
    cout << "Credit insuficient" << endl;
    return;
  }
  // calculam si afisam restul
  cout << "Rest calculat: " << suma(nr) << "-" << pret << " = "
       << suma(nr) - pret << endl;

  int rest = (suma(nr) - pret);
  int bancnote50, bancnote10, bancnote5, bancnote1;

  // impartim restul la bancnote de 50
  // vedem cate sunt apoi scadem din rest
  // valoarea acestora
  // la fel si pentru celelalte bancnote

  bancnote50 = rest / 50;
  rest -= bancnote50 * 50;

  bancnote10 = rest / 10;
  rest -= bancnote10 * 10;

  bancnote5 = rest / 5;
  rest -= bancnote5 * 5;

  bancnote1 = rest;
  // afisam restul calculat anterior
  cout << "Bancnote restituite" << endl;
  cout << bancnote1 << "x" << 1 << endl;
  cout << bancnote5 << "x" << 5 << endl;
  cout << bancnote10 << "x" << 10 << endl;
  cout << bancnote50 << "x" << 50 << endl;
}
int main() { automat(); }