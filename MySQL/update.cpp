#include <iostream>
#include <mysql.h>
#include <cstring>
int main(int argc, char **argv){
    MYSQL * connect;
    connect = mysql_init(NULL);
    std::string update,campo,mail,id,novo = {};
    connect = mysql_real_connect( connect, "localhost" , "root" , "", "cpp",0,NULL,0);

    try{
        if( !connect ){
            throw connect;
            return 1;
        }

        std::cout << "Informe o Campo a ser alterado: ";
        std::getline( std::cin,campo );
        std::cout << "Informe o novo valor: ";
        std::getline( std::cin,novo );
        std::cout << "Informe o id: ";
        std::getline( std::cin,id );
        /*
        if( argc > 3){
            campo = argv[1];
            novo = argv[2];
            id = argv[3];
        }else{
            std::cout << "Use: " << argv[0] << " ['campo'] ['novo_valor'] [id]" << '\n';
        }
        */
        update = "UPDATE crudcpp SET " + campo + " = '" + novo + "' WHERE id = " + id;
        std::cout << "Comando SQL: " << update << std::endl;
                    // converte string para char
        bool query_state = mysql_query(connect,update.c_str() );
        if( !query_state ){
            std::cout << "Dados atualizar com sucesso!" << '\n';
        }else{
            std::cout << "Erro ao inserir os dados: " << mysql_error(connect) << '\n';
        }
        mysql_close(connect);
        return 0;

    }catch( ... ){
        std::cout << "Falha ao conectar." << '\n';
    }
}

//g++ update.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql - o update
