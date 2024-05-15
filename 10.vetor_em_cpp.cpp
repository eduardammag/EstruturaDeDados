#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    //Tipo nome tamanho
    
    int x[100] = {0}; //declarado um vetor de 100 elementos com zeros
    
    cout << "x[0] = " << x[0] << ", endereço: " << &x[0] << endl;
    cout << "x[1] = " << x[1] << ", endereço: " << &x[1] << endl;
    cout << "x[99] = " << x[99] << ", endereço: " << &x[99] << endl;
    
    cout << "Tamanho de x = " << sizeof(x)/sizeof(x[0]) << endl; // descobrindo o tamanho do vetor
    cout << "-------------------------------------" << endl;
    
    
    int array[4]; //declarado um vetor de 100 elementos com zeros
    
    array[0] = 8;
    array[1] = 64;
    array[2] = 256;
    array[3] = 512;
    array[4] = 4646; // indo além do que foi reservado pelo programa
    
    cout << "array[0] = " << array[0] << ", endereço: " << &array[0] << endl;
    cout << "array[1] = " << array[1] << ", endereço: " << &array[1] << endl;
    cout << "array[2] = " << array[2] << ", endereço: " << &array[2] << endl;
    cout << "array[3] = " << array[3] << ", endereço: " << &array[3] << endl;
    cout << "array[4] = " << array[4] << ", endereço: " << &array[4] << endl; // o programa le como se fosse array[0] + 4sizeof(elemento)
    
    cout << "Tamanho de array = " << sizeof(array)/sizeof(array[0]) << endl; // descobrindo o tamanho do vetor

    // offset => array + (index * sizeof(elemento)) deslocamento pelo vetor
    
    if (&array[0] ==  array) {cout << "Faz Sentido !" << endl;} // array é o enderço onde começa o vetor
    
    cout << "-------------------------------------" << endl;
    
    //Row Major faz o endereçamento linha a linha
    // Questão de prova: trabalhar com row major como se fosse column major
    
    int arriTest1[2][3] = {2,4,5,9,0,19};
    int arriTest2[2][3] = {{2,4,5},{9,0,19}};
    
    cout << "--- Testando array 1 ---" << endl;
    
    for (int i= 0; i<2; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << "Array 1 em [" << i << "][" << j << "] = " << arriTest1[i][j] << ", Endereço: " << &arriTest1[i][j] << endl;
        }
    }
    
    cout << "--- Testando array 2 ---" << endl;
    
    for (int i= 0; i<2; i++)
    {
        for (int j=0; j<3; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
    
    cout << "--- Aluno com TDAH ---" << endl;
    //Matriz_m_n_ em (i,j) = (i*n + j) * sizeof(elemento)
    //Matriz [2,3] em (1,1) = (3+1) * 4
    //Matriz [2,3] em (0,1) = (0+1) * 4
    //Matriz [2,3] em (1,0) = (1*3+0) *4
    //Matriz [2,0] em (1,1) = (2*3+0) *4 fra do vetor
    
    for (int i= 0; i<3; i++)
    {
        for (int j=0; j<2; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }

    cout << "--- Aluno com transtorno psicótico ---" << endl;
    //Matriz_m_n_ em (i,j) = (i*n + j) * sizeof(elemento)
    //Matriz [2,3] em (1,1) = (3+1) * 4
    //Matriz [2,3] em (0,1) = (0+1) * 4
    //Matriz [2,3] em (1,0) = (1*3+0) *4
    //Matriz [2,0] em (1,1) = (2*3+0) *4 fra do vetor
    
    for (int i= 0; i<3; i++)
    {
        for (int j=0; j<8; j++)
        {
            cout << "Array 2 em [" << i << "][" << j << "] = " << arriTest2[i][j] << ", Endereço: " << &arriTest2[i][j] << endl;
        }
    }
    
    return 0;
}