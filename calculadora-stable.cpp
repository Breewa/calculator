#include <iostream>

void ERRO(char leitor, int local, bool debug)
{
    if (!debug)
    {
        std::cout << "ERROR, invalid\n\n";
    }
    else
    {
        std::cout << "ERRO, inválido debug: " << local << "\n\n";
    }

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

    std::cout << "Calculator\n\n";

    error:
    double a = 0;
    double b = 0;
    char simbolo = '\0';
    char leitor = '\0';
    long divisor = 10;
    int local = 1;
    double valor = 0;
    bool valorinicial = false;
    bool menos = false;
    bool menosb = false;
    bool ponto = false;

    std::cin >> leitor;

    while (1)
    {
        if (debug) {std::cout << "debug a: "<< i <<'\n'; i++;}

        //debug 1
        if (leitor == '\n') {ERRO(leitor, local, debug); goto error;}

        if (valorinicial && leitor == '.')
        {
            ponto = true;
            leitor = std::cin.get();
            continue;
        }

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
                simbolo = leitor;
                leitor = std::cin.get();
                break;
            }
        }

        if (leitor >= '0' && leitor <= '9')
        {

            if (ponto)
            {
                valor = leitor - '0';
                valor = valor / divisor;
                a = a + valor;
                divisor = divisor * 10;
                leitor = std::cin.get();
                continue;
            }

            valorinicial = true;
            a = a * 10;
            leitor = leitor - '0';
            a = a + leitor;
            leitor = std::cin.get();
            continue;
        }
        else
        {
            //debug 1
            ERRO(leitor, local, debug);
            goto error;
        }
    }

    valorinicial = false;
    ponto = false;
    i = 0;
    local++;
    divisor = 10;
    while (1)
    {
        if (debug) {std::cout << "debug simbolo: "<< i <<'\n'; i++;}

        if (leitor == '/' || leitor == '*')
        {
            ERRO(leitor, local, debug);
            goto error;
        }

        if (!menosb && simbolo == '*' && leitor == '-' || !menosb && simbolo == '/' && leitor == '-')
        {
            menosb = true;
            leitor = std::cin.get();
            continue;
        }

        if (menosb && simbolo == '*' && leitor == '-' || menosb && simbolo == '/' && leitor == '-')
        {
            menosb = false;
            leitor = std::cin.get();
            continue;
        }

        if (simbolo == '/' || simbolo == '*')
        {
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

    //debug 2
    if (simbolo != '+' && simbolo != '-' && simbolo != '/' && simbolo != '*')
    {
        ERRO(leitor, local, debug);
        goto error;
    }

    i = 0;
    local++;
    while (leitor != '\n')
    {
        if (debug) {std::cout << "debug b: "<< i <<'\n'; i++;}
        
        if (valorinicial && leitor == '.')
        {
            ponto = true;
            leitor = std::cin.get();
            continue;
        }

        if (leitor >= '0' && leitor <= '9')
        {
            if (ponto)
            {
                valor = leitor - '0';
                valor = valor / divisor;
                b = b + valor;
                divisor = divisor * 10;
                leitor = std::cin.get();
                continue;
            }
            valorinicial = true;
            b = b * 10;
            leitor = leitor - '0';
            b = b + leitor;
            leitor = std::cin.get();
            continue;
        }
        else
        {
            //debug 3
            ERRO(leitor, local, debug);
            goto error;
        }
    }

    if (menos) {a = a * -1;}
    if (menosb) {b = b * -1;}

    if (debug)
    {
        std::cout << "a: " << a << "\nb: " << b << "\nsimbolo: " << simbolo << '\n';
    }

    if (simbolo == '+') {resultado = a + b;}
    if (simbolo == '-') {resultado = a - b;}
    if (simbolo == '*') {resultado = a * b;}
    if (simbolo == '/') {resultado = a / b;}
    std::cout << resultado << "\n\n";
    goto error;
    return 1;
}
