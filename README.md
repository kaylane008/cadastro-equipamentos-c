# Cadastro de Equipamentos em C

## Descrição
Programa desenvolvido em linguagem C para cadastrar e listar equipamentos, armazenando as informações em um arquivo de texto.

## Funcionalidades
- Cadastrar equipamento com nome, código/patrimônio e setor.
- Listar equipamentos cadastrados.
- Apagar todos os registros.
- Encerrar o programa.

## Arquivos
- `equipamentos.c`: código-fonte do programa.
- `equipamentos.txt`: arquivo de armazenamento e exemplo de registros.
- `README.md`: documentação do projeto.

## Como compilar
É necessário ter um compilador C, como o GCC.

No terminal, dentro da pasta do projeto, execute:

`gcc equipamentos.c -o equipamentos.exe`

## Como executar no Windows
Execute no terminal:

`.\equipamentos.exe`

## Utilização
No menu do programa:
- Digite `1` para cadastrar um equipamento.
- Digite `2` para listar os equipamentos.
- Digite `3` para apagar todos os registros.
- Digite `0` para sair.

Os registros são armazenados no arquivo `equipamentos.txt`, com os campos separados por ponto e vírgula.
