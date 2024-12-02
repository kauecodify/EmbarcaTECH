//Documentação do projeto de inversão de valores - EMBARCATECH

// ----------------------------------------------------------- //

// 0 > Instalar MinGW "https://sourceforge.net/projects/mingw/"
// 1 > Procurar na pasta a bin para download após instalar os componentes (mingw32-gcc-g++ e mingw32-gdb)
// 2 > localize a bin " Set-Location C:\MinGW\bin "
// 3 > VERIFICAR INSTALAÇÃO CORRETA DO GCC E GDB " gcc --version ; gdb --version " (CASO NÃO ENCONTRE ADICIONE A DOCUMENTAÇÃO AO PATH)
// 4 > abrir powershell (win e pesquisa editar variável ambiente) ; clicar em variável ambiente
// 5 > Editar a variavel do path para o caminho do arquivo " C:\MinGW\bin " ; verificar instalação WIN + R > (echo %PATH%)
// 6 > Verificar a instalação correta dos paths " gcc --version ; gdb --version " no terminal da aplicação
// 7 > compilar com -g = gcc -g seu_programa.c -o inversao.cpp e iniciar com gdb ./inversao.cpp
// 8 > DEFINIR BREAKPOINT > break InverterNumero
// 9 > Inspecionar variável com "print numero" e "print invertido"

// ----------------------------------------------------------- //

#include <stdio.h>

int inverterNumero(int numero) {
    int invertido = 0, resto;

    while (numero != 0) {
        resto = numero % 10;
        printf("Restante: %d, Invertido: %d\n", resto, invertido);  // debug
        invertido = invertido * 10 + resto;
        numero /= 10;
    }

    return invertido;
}

int main() {
    int numero, numeroInvertido;

    printf("Digite um número de três dígitos: ");
    scanf("%d", &numero);

    if (numero >= 100 && numero <= 999) {
        numeroInvertido = inverterNumero(numero);
        printf("O número invertido é: %d\n", numeroInvertido);
    } else {
        printf("Número inválido. Digite um número entre 100 e 999.\n");
    }

    return 0;
}
