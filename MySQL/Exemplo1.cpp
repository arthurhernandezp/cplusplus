#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <mysql.h>
#include <cstdio>
#include <stdlib.h>
#include <string>

void erro(MYSQL *conexao){
    std::cerr << '\n' << mysql_error(conexao) << "\n";
    mysql_close(conexao);
    exit(1);
}

MYSQL * __stdcall obterConexao(){
    const char *servidor = "**********";
    const char *usuario = "**********";
    const char *senha = "**********";
    const char *nomeBanco = "**********";
    MYSQL *conexao = mysql_init(NULL);

    if(!mysql_real_connect(conexao,servidor,usuario,senha,nomeBanco,0,NULL,0)){
        erro(conexao);
    }else{
        std::cout << "Conexao realizada com sucesso!" << std::endl;
    }
    return conexao;
}

void inserir(MYSQL *conexao, char *nome, float saldo){
    char query[100];
    sprintf(query,"INSERT INTO clientes(nome,saldo) VALUES('%s','%f');",nome,saldo);
    if(mysql_query(conexao,query)){
        erro(conexao);
    }else{
        std::cout << "\nDados inseridos com sucesso!\n";
    }
}

void ler(MYSQL *conexao){

    MYSQL_RES *resultado;
    MYSQL_ROW row;

    if(mysql_query(conexao,"SELECT * FROM clientes")){
        erro(conexao);
    }

    resultado = mysql_store_result(conexao);
    if(resultado == NULL){
        erro(conexao);
    }

    while((row = mysql_fetch_row(resultado)) != NULL){
        std::cout << "\nNome: " << row[0] << std::endl;
        std::cout << "Conta: " << row[1] << std::endl;
        std::cout << "Saldo: " << row[2] << std::endl;
    }

    mysql_free_result(resultado);
}

void atualizar(MYSQL *conexao, int numeroConta, float saldo){
    char query[100];
    sprintf(query, "UPDATE clientes SET saldo = %f WHERE numero_conta = %d;",saldo,numeroConta);
    if(mysql_query(conexao,query)){
        erro(conexao);
    }else{
        std::cout << "\nDados atualizados com sucesso!" << std::endl;
    }
}

void apagar(MYSQL* conexao, int numeroConta){
    char query[100];
    sprintf(query, "DELETE FROM clientes WHERE numero_conta = %d",numeroConta);
    if(mysql_query(conexao,query)){
        erro(conexao);
    }else{
        std::cout << "\nDados apagados com sucesso!" << std::endl;
    }
}

int main(){
    MYSQL *conexao = obterConexao();
    //system("pause");
    char nome[100];
    float saldo;
    system("cls");
    std::cout << "\n ******** CADASTRO DE CLIENTES ******** "<< std::endl;
    /*
    for(int i = 0; i < 3;i++){
        std::cout << "\n" << i << " - Nome: ";
        std::cin.ignore(); // Ignora qualquer caractere de nova linha deixado no buffer
        std::cin.getline(nome, sizeof(nome)); // Lê o nome completo incluindo espaços
        std::cout << "\n" << i << " - Saldo: ";
        std::cin >> saldo;
        inserir(conexao, nome, saldo);
    }*/
    std::cout << "\n******** CLIENTES CADASTRADOS ********" << std::endl ;
    ler(conexao);

    // atualizar(conexao, 9, 300.49);

    // std::cout << "\n*** CLIENTES CADASTRADOS ***\n";
    // ler(conexao);

    // apagar(conexao, 11);

    // std::cout << "\n*** CLIENTES CADASTRADOS ***\n";
    // ler(conexao);
    mysql_close(conexao);
    return 0;
}
