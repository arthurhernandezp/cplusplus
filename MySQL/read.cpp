#include <iostream>
#include <mysql.h>

int main(int argc, char **argv){
    MYSQL * connect;
    connect = mysql_init(NULL);

    connect = mysql_real_connect( connect, "localhost" , "root" , "", "cpp",0,NULL,0);

    try{
        if( !connect ){
            throw connect;
            return 1;
        }

        MYSQL_RES * res_set;
        MYSQL_ROW row;

        mysql_query(connect,"SELECT * FROM crudcpp");
        //Armazenar os dados que vamos pegar do mysql_store_result
        //O que voltar do select será armazenado em res_set
        res_set = mysql_store_result( connect );

        unsigned numRows = mysql_num_rows( res_set );

        //vai pegar cada linha do res_set
        while( ( row = mysql_fetch_row( res_set ) ) != NULL ){
        //                id                  nome             email
            std::cout << row[0] << " | " << row[1] << " | " << row[2] << '\n';

        }

        mysql_close(connect);
        return 0;

    }catch( ... ){
        std::cout << "Falha ao conectar." << '\n';
    }
}

//g++ read.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql - o read
