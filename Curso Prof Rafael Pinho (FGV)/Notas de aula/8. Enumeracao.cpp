#include <iostream>

// Inclui o cabeçalho para usar entrada e saída padrão
using std::cout;
using std::endl;
using std::string;

// Define um enum chamado Streaming com diferentes serviços de streaming
enum Streaming {AppleTV, AmazonPrime, CrunchyRoll, DisneyPlus, NetFlix, Max};

int main()
{
    // Define uma variável do tipo Streaming e a inicializa com CrunchyRoll
    Streaming streamingSubscription = CrunchyRoll;
    
    // Verifica o valor de streamingSubscription usando um switch
    switch (streamingSubscription)
    {
        case AppleTV:
            // Se streamingSubscription for AppleTV, imprime uma mensagem
            cout << "Nunca usei... não sei como é... [" << streamingSubscription << "]" << endl;
            break;
        case CrunchyRoll:
            // Se streamingSubscription for CrunchyRoll, imprime uma mensagem
            cout << "Muito bom... [" << streamingSubscription << "]" << endl;
            break;
        default:
            // Se streamingSubscription for outro valor, imprime "NADA"
            cout << "NADA" << endl;
    }

    // Imprime uma linha para separar
    cout << "======================" << endl;
    
    // Define um enum chamado Meses com os meses do ano
    enum Meses {JANEIRO = 10, FEVEREIRO, MARCO, ABRIL, MAIO};
    
    // Define uma variável do tipo Meses e a inicializa com MAIO
    Meses mesProvas = MAIO;
    // Imprime o valor de mesProvas
    cout << mesProvas << endl;
    
    // Define um enum chamado Semana com dias da semana
    enum Semana { Segunda = 10, Terça = 1, Quarta = -3};
    // Define uma variável do tipo Semana e a inicializa com Quarta
    Semana diaPalestra = Quarta;
    // Imprime o valor de diaPalestra
    cout << diaPalestra << endl;
    
    // Retorna 0 para indicar que o programa terminou com sucesso
    return 0;
}



    cout << "======================" << endl;
    
    enum Meses {JANEIRO = 10, FEVEREIRO, MARCO, ABRIL, MAIO};
    
    Meses mesProvas = MAIO;
    cout << mesProvas << endl;
    
    enum Semana { Segunda = 10, Terça = 1, Quarta = -3};
    Semana diaPalestra = Quarta;
    cout << diaPalestra << endl;
    
    return 0;
}
