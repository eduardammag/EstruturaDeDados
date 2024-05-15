#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//UDT: user defined type

struct Livro
{
    string strTitulo;
    string strAutor;
    int iPublicacao;
};

struct Ponto
{
    unsigned short usRed;
    unsigned short usGreen;
    unsigned short usBlue;
};

struct Biblioteca
{   // Exemplo de struct dentro de struct
    string strNome;
    int iTamAcervo;
    struct Livro livros[1000]; // a biblioteca tem 1000 livros, é um vetor
};

void listarLivros(struct Biblioteca);
void adicionarLivros(struct Biblioteca, struct Livro);

int main()
{
    
    struct Livro livro1;
    livro1.strTitulo = " Outliers: the story of success";
    livro1.strAutor = "Malcolm Gladwell";
    livro1.iPublicacao = 2008;
    
    struct Livro livro2;
    livro1.strTitulo = " How to grow old";
    livro1.strAutor = "Marus Tullius Cicero";
    livro1.iPublicacao = -44;
    
    cout << "Título 1: " << livro1.strTitulo << ", por " << livro1.strAutor << endl;
    cout << "Publidcado em : " << livro1.iPublicacao << ". " << endl;
    
    cout << "Título 2: " << livro2.strTitulo << ", por " << livro2.strAutor << endl;
    cout << "Publidcado em : " << livro2.iPublicacao << ". \n" << endl;
    
    struct Ponto telaComputador[640][480]; // é uma matriz formada por elementos do tipo structs
    telaComputador[0][0].usRed = 0;
    telaComputador[0][0].usGreen = 0;
    telaComputador[0][0].usBlue = 0;
    
    cout << "RGB[0,0] (" << telaComputador[0][0].usRed << "," << telaComputador[0][0].usGreen << "," << telaComputador[0][0].usBlue << ")" << endl;
    
    struct Biblioteca biblioteca;
    biblioteca.strNome = "Biblioteca do palácio Botafogo";
    biblioteca.iTamAcervo = 0;
    
    biblioteca.livros[0] = livro1;
    biblioteca.iTamAcervo += 1; 
    biblioteca.livros[1] = livro2;
    biblioteca.iTamAcervo += 1;
    
    struct Livro livro3;
    livro3.strTitulo = "1984";
    livro3.strAutor = "George Orwell";
    livro3.iPublicacao = 1949;

    
    listarLivros(biblioteca);
    
    adicionarLivros(biblioteca, livro3);
    
    listarLivros(biblioteca)
    
    
    
    //Exemplo 1
    struct // struct anonimo só da para definir um valor desse tipo na própria definição da struct, não é acessado fora
    {
        int iIdade; // membro de dado da estrutura
        string strNome;
    } alunoEMAp;

    alunoEMAp.iIdade = 18;
    alunoEMAp.strNome = "Ana";
    
    cout << "Idade do alunoEMAp: " << alunoEMAp.iIdade << endl;
    cout << "Nome do alunoEMAp: " << alunoEMAp.strNome << endl;

    struct
    {
        int iIdade; // membro de dado da estrutura
        string strNome;
    } alunoEMAp1, alunoEMAp2;
    
    alunoEMAp1.iIdade = 20;
    alunoEMAp1.strNome = "Antonio";
    
    cout << "Idade do alunoEMAp1: " << alunoEMAp1.iIdade << endl;
    cout << "Nome do alunoEMAp1: " << alunoEMAp1.strNome << endl;
    
    alunoEMAp2.iIdade = 17;
    alunoEMAp2.strNome = "Henzo";
    
    cout << "Idade do alunoEMAp2: " << alunoEMAp2.iIdade << endl;
    cout << "Nome do alunoEMAp2: " << alunoEMAp2.strNome << endl;
    
    return 0;    
}

void listarLivros(struct Biblioteca biblioteca)
{
    cout << "\nLivros do acervo da " << biblioteca.strNome << endl;
    for (int i = 0; i < biblioteca.iTamAcervo; i++)
    {
        cout << "Título : " << biblioteca.livros[i].strTitulo << ", por " << biblioteca.livros[i].strAutor << endl;
        cout << "Publidcado em : " << biblioteca.livros[i].iPublicacao << ".\n" << endl;
    }
}

// Verificar se o vetor já está cheio
void adicionarLivros(struct Biblioteca& biblioteca, struct Livro3 novoLivro)
{
    biblioteca.livros[biblioteca.iTamAcervo] = novoLivro;
    biblioteca.iTamAcervo += 1
}