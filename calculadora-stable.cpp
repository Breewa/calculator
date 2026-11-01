#include <iostream>

void ERRO(char leitor)
{
    std::cout << "ERRO, inválido\n\n";
    if (leitor == '\n')
    {
        return;
    }
    else
    {
        while (std::cin.get() != '\n');
    }
}

int main()
{
    double resultado = 0;
    bool debug = false;
    int i = 0;

    erro:
    double a = 0;
    double b = 0;
    char simbolo = '\0';
    char leitor = '\0';
    int divisor = 0;
    double valor = 0;
    bool valorinicial = false;
    bool menos = false;

    std::cin >> leitor;

    while (1)
    {
        if (debug) {std::cout << "debug a: "<< debug <<'\n'; i++;}

        if (leitor == '\n') {ERRO(leitor); goto erro;}

        if (!valorinicial && leitor == 'r')
        {
            a = resultado;
            leitor = std::cin.get();
            simbolo = leitor;
            break;
        }

        if (!valorinicial && !menos && leitor == '-')
        {
            menos = true;
            leitor = std::cin.get();
            continue;
        }

        if (!valorinicial && menos && leitor == '-')
        {
            menos = false;
            leitor = std::cin.get();
            continue;
        }

        if (valorinicial)
        {
            if (leitor == '+' || leitor == '-' || leitor == '/' || leitor == '*')
            {
                valorinicial = false;
                simbolo = leitor;
                leitor = std::cin.get();
                break;
            }
        }

        if (leitor >= '0' && leitor <= '9')
        {
            valorinicial = true;
            a = a * 10;
            leitor = leitor - '0';
            a = a + leitor;
            leitor = std::cin.get();
            continue;
        }
        else
        {
            ERRO(leitor);
            goto erro;
        }
    }

    i = 0;
    while (1)
    {
        if (debug) {std::cout << "debug simbolo: "<< debug <<'\n'; i++;}

        if (simbolo != '+' && simbolo != '-' && simbolo != '/' && simbolo != '*')
        {
            ERRO(leitor);
            goto erro;
        }

        if (simbolo == '/' || simbolo == '*')
        {
            simbolo = leitor;
            leitor = std::cin.get();
            break;
        }

        if (leitor == '-' && simbolo == '+')
        {
            simbolo = '-';
            leitor = std::cin.get();
            continue;
        }

        if (leitor == '-' && simbolo == '-')
        {
            simbolo = '+';
            leitor = std::cin.get();
            continue;
        }

        if (leitor >= '0' && leitor <= '9')
        {
            break;
        }

        leitor = std::cin.get();
    }

    i = 0;
    while (leitor != '\n')
    {
        if (debug) {std::cout << "debug b: "<< debug <<'\n'; i++;}
        
        if (leitor >= '0' && leitor <= '9')
        {
            b = b * 10;
            leitor = leitor - '0';
            b = b + leitor;
            leitor = std::cin.get();
            continue;
        }
        else
        {
            ERRO(leitor);
            goto erro;
        }
    }

    if (menos) {a = a * -1;}
    if (simbolo == '+') {resultado = a + b;}
    if (simbolo == '-') {resultado = a - b;}
    if (simbolo == '*') {resultado = a * b;}
    if (simbolo == '/') {resultado = a / b;}
    std::cout << resultado << "\n\n";
    goto erro;
    return 1;
}
