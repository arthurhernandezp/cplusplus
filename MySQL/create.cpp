#include <iostream>
#include <mysql.h>
#include <cstring>
int main(int argc, char **argv){
    MYSQL * connect;
    connect = mysql_init(NULL);
    std::string create,nome,mail = {};
    connect = mysql_real_connect( connect, "localhost" , "root" , "", "cpp",0,NULL,0);

    try{
        if( !connect ){
            throw connect;
            return 1;
        }
        std::cout << "Informe o nome: ";
        std::getline( std::cin,nome );
        std::cout << "Informe o e-mail: ";
        std::getline( std::cin,mail );
        create = "INSERT INTO crudcpp VALUES( NULL, '" + nome + "', '" + mail +"')";
                                        // converte string para char
        bool query_state = mysql_query(connect,create.c_str() );
        if( !query_state ){
            std::cout << "Dados inseriodos com sucesso!" << '\n';
        }else{
            std::cout << "Erro ao inserir os dados: " << mysql_error(connect) << '\n';
        }
        mysql_close(connect);
        return 0;

    }catch( ... ){
        std::cout << "Falha ao conectar." << '\n';
    }
}

//g++ create.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql - o create
