#include <stdio.h>
#include <string.h>

#define ARQUIVO "equipamentos.txt"
#define TAM 100

/* Remove o '\n' que o fgets deixa no final da string */
void removerQuebraLinha(char *texto) {
    texto[strcspn(texto, "\n")] = '\0';
}

/* Modo "w": cria o arquivo ou sobrescreve (apaga tudo que existia) */
void criarArquivoNovo() {
    FILE *arq = fopen(ARQUIVO, "w");

    if (arq == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return;
    }

    fclose(arq);
    printf("Arquivo criado/limpo com sucesso!\n");
}

/* Modo "a": acrescenta ao final do arquivo sem apagar o conteudo existente */
void cadastrarEquipamento() {
    char nome[TAM];
    char codigo[TAM];
    char setor[TAM];

    FILE *arq = fopen(ARQUIVO, "a");

    if (arq == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    /* Solicitar dados ao usuario */
    printf("\n--- Novo equipamento ---\n");

    printf("Nome do equipamento: ");
    fgets(nome, TAM, stdin);
    removerQuebraLinha(nome);

    printf("Codigo/patrimonio: ");
    fgets(codigo, TAM, stdin);
    removerQuebraLinha(codigo);

    printf("Setor: ");
    fgets(setor, TAM, stdin);
    removerQuebraLinha(setor);

    /* Salvar no arquivo .txt */
    fprintf(arq, "%s;%s;%s\n", nome, codigo, setor);

    fclose(arq);
    printf("Equipamento cadastrado com sucesso!\n");
}

/* Modo "r": le um arquivo existente e mostra os registros */
void listarEquipamentos() {
    char linha[TAM * 3];
    int contador = 0;

    FILE *arq = fopen(ARQUIVO, "r");

    if (arq == NULL) {
        printf("\nNenhum cadastro encontrado (arquivo ainda nao existe).\n");
        return;
    }

    printf("\n--- Equipamentos cadastrados ---\n");

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        char *nome, *codigo, *setor;

        removerQuebraLinha(linha);

        nome   = strtok(linha, ";");
        codigo = strtok(NULL, ";");
        setor  = strtok(NULL, ";");

        contador++;
        printf("\nRegistro %d\n", contador);
        printf("Nome  : %s\n", nome   ? nome   : "-");
        printf("Codigo: %s\n", codigo ? codigo : "-");
        printf("Setor : %s\n", setor  ? setor  : "-");
    }

    if (contador == 0) {
        printf("Arquivo vazio, nenhum equipamento cadastrado.\n");
    }

    fclose(arq);
}

int main() {
    char entrada[TAM];
    int opcao;

    do {
        printf("\n===== CADASTRO DE EQUIPAMENTOS =====\n");
        printf("1 - Cadastrar equipamento\n");
        printf("2 - Listar equipamentos\n");
        printf("3 - Apagar todos os registros (recriar arquivo)\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        fgets(entrada, TAM, stdin);
        if (sscanf(entrada, "%d", &opcao) != 1) {
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                cadastrarEquipamento();
                break;
            case 2:
                listarEquipamentos();
                break;
            case 3:
                criarArquivoNovo();
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
