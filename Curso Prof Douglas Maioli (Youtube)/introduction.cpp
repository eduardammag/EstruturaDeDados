#include <iostream>
using namespace std;

/*
Exercícios da playlist do Professor Douglas Maioli no youtube:

1 - Dada a função f(x) = x^2 - 3x + 5, crie um algoritmo em C++ que tenha uma função
que calcula o valor de f(a), em que a é um número real informado pelo usuário.

2 - Crie um algoritmo em C++ em que o usuário informa as notas de três provas de um determinado
aluno e também a média de nota da turma toda. O algoritmo deve calcular a média deste aluno e
informar se sua nota é acima da média, abaixo da média ou está na média.

3 - Crie um algoritmo em C++ que tenha uma função que calcula o fatorial de um número inteiro 
positivo, informado pelo usuário.

4 - Crie um algoritmo em C++ que calcula a potência, em que o usuário informa um número real e
um número natural. Nesse algoritmo, sempre que é informado o resultado da potência, é perguntado
ao usuário se este deseja calcular outra potência.

5 - Em um programa de Moradia Popular, somente pessoas maiores de 21 anos e com renda abaixo de
R$ 1200,00 podem participar. Crie um algoritmo em C++ em que o usuário informa sua idade e sua renda, 
e é informado se ele pode ou não participar desse programa.
*/

    int fat(int x){
    int fatorial=1;
    for (int i=1 ; i<=x ; i++){
        fatorial*=i; }
    return fatorial;}


float potencia(float x, int y){
    float pot=1;
    int cont=1;
    while (cont <= y){
        pot*=x;
        cont++;
    }
    return pot;    }


int main()
{
    
    //1
    int a;
    std::cout << "Digite um número real: " << std::endl;
    std::cin >> a ;
    std::cout << "Aplicando a função do enunciado, temos: " << (a*a -3*a + 5) << std::endl;


    //2 
    float nota1, nota2, nota3, alunomedia, turmamedia;
    cout << "Informe as notas do aluno:" << endl;
    cout << "Nota 1: " << endl;
    cin >> nota1;
    cout << "Nota 2: " << endl;
    cin >> nota2;
    cout << "Nota 3: " << endl;
    cin >> nota3;   
    cout << "Informe a média da turma:" << endl;
    cin >> turmamedia;    
    
    alunomedia = (nota1+nota2+nota3)/3;
    
    if (alunomedia >= turmamedia){
        cout<< "Aluno aprovado com média " << alunomedia << "." << endl;
        
    } else {
        cout<< "Aluno reprovado com média " << alunomedia << "." << endl;}
    
    
    
    //3 
    int n;
    while (true){
    cout << "Informe um numero inteiro positivo!\n";
    cin >> n;
    if (n <= 0){
        cout << "O numero informado e negativo!\n";
    } else{
        break;
    }
    }

    int valorfat = fat(n);
    cout << "O valor do fatorial de " << n << " e: " << valorfat << endl;
  
    //4 
    float b;
    int e;
    while (1){
    cout << "Digite a base (numero real)\n";
    cin >> b;
    cout << "Digite o expoente (numero natural)\n";
    cin >> e;
    float respot=potencia(b,e);
    cout << "O resultado de " << b << " elevado a " << e << " e igual a " << respot << endl;
    int q;
    cout << "Digite 1 se quiser calcular outra potencia e 0 se não quiser\n";
    cin >> q;
    if (q == 0){
        break;
    }
    }
  
    //5
    float idade, renda;
    cout << "Informe sua idade. " << endl;
    cin >> idade;
    cout<< "Informe sua renda. " << endl;
    cin >> renda;
    
    if (idade >= 21 && renda <= 1200.00){ 
        cout << "Você está APTO a participar do programa Moradia Popular." << endl;
    } else { 
        cout << "Você está INAPTO a participar do programa de Moradia Popular." << endl;}
    
        return 0;
}
