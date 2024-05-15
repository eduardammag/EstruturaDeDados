#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//Definindo a função TestFunction
//Definimos que o resultado e o argumento são int

int TestFunction(int arg1)
{
    int result = 5; //Inicializando com o valor 5
    if (arg1<5)     //Se arg1<5 retornará 10, se for maior retornará 5
        result = 10;
        
    return result;
}


int main()
{
    
    int resultado1 = TestFunction(11);
    cout << "O resultado 1 é: " << resultado1 << endl;
    cout << endl; //Imprime uma linha
    int resultado2 = TestFunction(3);
    cout << "O resultado 2 é: " << resultado2 << endl;

    //E ou OU 
    int iVal1 =9;
    if (iVal1 <1 || iVal1 >8)
        cout<< "EMAp" << endl;
    else 
        cout << "EPGE" << endl;
        
    
    //O operador de negação ! inverte o valor lógico da expressão seguinte
    int iVal2 =1;
    if (!(iVal2 >2 && iVal2>6))
    {
        if (iVal2 > -1){
            cout << "Ariana Grande" << endl;
    cout << "Katy Perry" << endl;}
        
    else 
        cout << "Anitta" << endl;
    }
       
    
    //Declarando e Inicializando previousThing como verdadeiro
    bool teste1 = true;
    
    // Ternary conditional operator (?)
    // Se teste1 for true, chama TestFunction(4), se não retorna 6
    int teste2 = teste1 ? TestFunction(4) : 6;
    cout << teste2 << endl;
        
    
}
