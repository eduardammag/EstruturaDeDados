#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main()
{
    enum Streaming {AppleTV, AmazonPrime, CrunchyRoll, DisneyPlus, NetFlix, Max};
    
    // streaming passa a ser um tipo, variável é streamingSubscription
    
    Streaming streamingSubscription = CrunchyRoll;
    
    switch (streamingSubscription)
    {
        case AppleTV:
            cout << "Nunca usei... não sei como é... [" << streamingSubscription << "]" << endl;
            break;
        case CrunchyRoll:
            cout << "Muito bom... [" << streamingSubscription << "]" << endl;
            break;
        default:
            cout << "NADA" << endl;
    }
    

    // tem que botar o break se nao ele roda os outros casos tbm


    cout << "======================" << endl;
    
    enum Meses {JANEIRO = 10, FEVEREIRO, MARCO, ABRIL, MAIO};
    
    Meses mesProvas = MAIO;
    cout << mesProvas << endl;
    
    enum Semana { Segunda = 10, Terça = 1, Quarta = -3};
    Semana diaPalestra = Quarta;
    cout << diaPalestra << endl;
    
    return 0;
}
