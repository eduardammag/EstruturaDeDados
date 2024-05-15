#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    
    // tamanho de int: 4 bytes
    int iNum1 =42;
    int iNum2 = 0;
    int iNum3 =17;
    
    cout << "iNum1:" << iNum1 << "\nTamanho de iNum1:" << sizeof(iNum1) << endl;
    cout << endl;
    cout << "iNum2:" << iNum2 << "\nTamanho de iNum2:" << sizeof(iNum2) << endl;
    cout << endl;
    cout << "iNum3:" << iNum3 << "\nTamanho de iNum3:" << sizeof(iNum3) << endl;
    cout << endl;
    
    
    // tamanho de short: 2 bytes
    short sNum= 17;
    cout << "sNum:" << sNum << "\nTamanho de sNum:" << sizeof(sNum) << endl;
    cout << endl;
    
    //tamanho de long: 8 bytes
    long lNum= 17;
    cout << "lNum: " << lNum << "\nTamanho de lNum: " << sizeof(lNum) << endl;
    cout << endl;
    
    //tamanho de long long: 8, 12 ou 16 bytes
    long long llNum= 999999000;
    cout << "llNum: " << llNum << "\nTamanho de llNum: " << sizeof(llNum) << endl;
    cout << endl;
    
    
    float fNum = 42.156;                    //float: precisão simples, 4 bytes
    double dNum= 42.99999;                  //double: precisão dupla, 8 bytes
    long double ldNum = 42.8765874576;
    
    
    cout << "fNum: " << fNum << "\nTamanho de fNum: " << sizeof(fNum) << endl;
    cout << "dNum: " << dNum << "\nTamanho de dNum: " << sizeof(dNum) << endl;
    cout << "ldNum: " << ldNum << "\nTamanho de ldNum: " << sizeof(ldNum) << endl;


    //string: Aspas duplas
    //char: Aspas simples
    char  cValue ='E';
    cout << "cValue:" << cValue << "\nTamanho de cValue:" << sizeof(cValue) << endl;
    cout << "(int)cValue:" << int(cValue) << endl;
    
    //Tudo para o computador é número. A letra E, de acordo com a tabela ascii, corresponde ao número 69.
  
    char cPalavraPreferida_1 = 116;
    char cPalavraPreferida_2 = 0x41;
    char cPalavraPreferida_3 = 0b1110000;
    
    cout << "cValue: " << cValue;
    cout << "\ncPalavraPreferida_1: " << cPalavraPreferida_1;
    cout << "\ncPalavraPreferida_2: " << cPalavraPreferida_2;
    cout << "\ncPalavraPreferida_3: " << cPalavraPreferida_3 << endl;
    
    
    string strValue_1 = "Eu adoro a";
    string strValue_2 = "EMAp";
    
    cout << "strValue_1:" << strValue_1 << "\nTamanho de strValue_1:" << sizeof(strValue_1) << endl;
    cout << "strValue_2:" << strValue_2 << "\nTamanho de strValue_2:" << sizeof(strValue_2) << endl;
    cout << strValue_1 << " " << strValue_2 << endl;
    
    bool bValue_1 = true;
    bool bValue_2 = false;
    bool bValue_3 = 42;
    bool bValue_4 = 0;
    
   // zero é a definição de falso, qualquer outro inteiro sempre será true

    cout << "bValue_1: " << bValue_1 << "\nTamanho de bValue_1: " << sizeof(bValue_1) << endl;
    cout << "bValue_2: " << bValue_2 << "\nTamanho de bValue_2: " << sizeof(bValue_2) << endl;
    cout << "bValue_3: " << bValue_3 << "\nTamanho de bValue_3: " << sizeof(bValue_3) << endl;
    cout << "bValue_4: " << bValue_4 << "\nTamanho de bValue_4: " << sizeof(bValue_4) << endl;
    
    
    const int iNUMERO = 42;
    //iNUMERO = 111; é proibido alterar a constante, da erro se tentar rodar 
    cout << "iNUMERO: " << iNUMERO << "\nTamanho de iNUMERO: " << sizeof(iNUMERO) << endl;
    
    //unsigned: apenas valores não negativos são permitidos
    //unsigned short: ocupa menos espaço na memória que um "int" padrão. Geralmente é de 16 bits, o que permite representar valores na faixa de 0 a 65.535.
    //unsigned long: tem uma capacidade de armazenamento maior do que o "int" padrão. Geralmente é de 32 bits ou 64 bits, pode representar valores na faixa de 0 a 4.294.967.295
    //Esses tipos de dados são úteis em situações em que você sabe que os valores serão sempre não negativos e deseja usar o espaço de memória de forma eficiente.
    
    unsigned short usNum = 40000; // representação básica binária, não usa complemento a 2, não existe representação para negativo
    cout << "usNum: " << usNum << "\nTamanho de usNum: " << sizeof(usNum) << endl;
    
    unsigned long long int ulliNum_1 = 42;
    cout << "ulliNum_1: " << ulliNum_1 << "\nTamanho de ulliNum_1: " << sizeof(ulliNum_1) << endl;
    
    long unsigned int long ulliNum_2 = 42; // mesma coisa que o de cima, preferível a de cima
    cout << "ulliNum_2: " << ulliNum_2 << "\nTamanho de ulliNum_2: " << sizeof(ulliNum_2) << endl;
}
    
