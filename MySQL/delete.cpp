#include <iostream>
#include <mysql.h>
#include <cstring>
int main(int argc, char **argv){
    MYSQL * connect;
    connect = mysql_init(NULL);
    std::string del,id = {};
    connect = mysql_real_connect( connect, "localhost" , "root" , "", "cpp",0,NULL,0);

    try{
        if( !connect ){
            throw connect;
            return 1;
        }

        std::cout << "Informe o id: ";
        std::getline( std::cin,id );
        /*
        if( argc > 1 ){
            id = argv[1];
        }else{
            std::cout << "Use: " << argv[0] << "[id]" << '\n';
        }
        */
        del = "DELETE FROM crudcpp WHERE id = " + id;
        std::cout << "Comando SQL: " << del << std::endl;
                    // converte string para char
        bool query_state = mysql_query(connect,del.c_str() );
        if( !query_state ){
            std::cout << "Dados atualizar com sucesso!" << '\n';
        }else{
            std::cout << "Erro ao deletar os dados: " << mysql_error(connect) << '\n';
        }
        mysql_close(connect);
        return 0;

    }catch( ... ){
        std::cout << "Falha ao conectar." << '\n';
    }
}

//g++ delete.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql - o delete
