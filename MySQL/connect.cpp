#include <iostream>
#include <mysql.h>

int main(int argc, char **argv){
    MYSQL * connect;
    connect = mysql_init(NULL);

    if( !connect ){
        std::cout << "O MYSQL não foi inicializado pelo sistema de inicializacao" << '\n';
        return 1;
    }

    connect = mysql_real_connect( connect, "localhost" , "root" , "", "cpp",0,NULL,0);

    if( connect ){
        std::cout << "Conectado com sucesso ao MySQL" << '\n';
    }else{
        std::cout << "Falha ao conectar ao banco de dados" << '\n';
    }

    mysql_close(connect);
	return 0;
}

//g++ -o connect connect.cpp -ID:/dev/MySQL/include -LD:/dev/MySQL/lib -lmysql
