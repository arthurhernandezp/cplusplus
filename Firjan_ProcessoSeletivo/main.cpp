#include <iostream>
#include <mysql.h>
#include <cstdlib>
#include <cstdlib>  // Para system()
#include <locale>   // Para locale
#include <codecvt>  // Para codecvt_utf8

std::string escape_json(const std::string& input);
std::string to_utf8(const std::wstring& wide_str);
int main(int argc, char **argv){
    setlocale(LC_ALL, "Portuguese_Brazil");


    MYSQL * connect;
    connect = mysql_init(NULL);

    connect = mysql_real_connect( connect, "localhost" , "/*****************/" , "/*****************/", "firjan",0,NULL,0);

    try{
        if( !connect ){
            throw connect;
            return 1;
        }

        MYSQL_RES * res_set;
        MYSQL_ROW row;

        mysql_query(connect,"SELECT * FROM base");
        //Armazenar os dados que vamos pegar do mysql_store_result
        //O que voltar do select será armazenado em res_set
        res_set = mysql_store_result( connect );

        unsigned numRows = mysql_num_rows( res_set );


        //vai pegar cada linha do res_set
        while( ( row = mysql_fetch_row( res_set ) ) != NULL ){
            //                unidade         linha de serviço     email
            //std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] << " | " << row[4] << " | " << row[5] <<'\n';

            // Cria o JSON escapando as aspas e barras invertidas
            std::string jsonData = "{";
            jsonData += "\"unidade\":\"" + escape_json(row[0]) + "\",";
            jsonData += "\"linha_de_servico\":\"" + escape_json(row[1]) + "\",";
            jsonData += "\"cliente\":\"" + escape_json(row[2]) + "\",";
            jsonData += "\"municipio_cliente\":\"" + escape_json(row[3]) + "\",";
            jsonData += "\"valor_contrato\":" + std::string(row[4]) + ",";
            jsonData += "\"horas_de_producao\":" + std::string(row[5]);
            jsonData += "}";
            std::string command = "curl -v -X POST http://demo.thingsboard.io/api/v1/*****************/telemetry --header \"Content-Type:application/json\" --data \"" + escape_json(jsonData) + "\"";
            //std::cout << command << '\n';
            // Executa o comando
            //system(command.c_str());

        }
        std::cout << "Terminou de ler a tabela base" << '\n';
        std::cout << "Iniciando a leitura da tabela metas" << '\n';

        mysql_query(connect,"SELECT * FROM metas");
        res_set = mysql_store_result( connect );
        numRows = mysql_num_rows( res_set );
        //TABELA METAS
        while( ( row = mysql_fetch_row( res_set ) ) != NULL ){
            //std::cout << row[0] << " | " << row[1] << " | " << row[2] << " | " << row[3] <<'\n';

            std::string jsonData = "{";
            jsonData += "\"unidade\":\"" + escape_json(row[0]) + "\",";
            jsonData += "\"valor_de_contratos_fechados\":\"" + escape_json(row[1]) + "\",";
            jsonData += "\"quantidade_de_projetos\":" + std::string(row[2]) + ",";
            jsonData += "\"horas_de_producao\":" + std::string(row[3]);
            jsonData += "}";
            //std::cout << jsonData << '\n';
            std::string command = "curl -v -X POST http://demo.thingsboard.io/api/v1/*****************/telemetry --header \"Content-Type:application/json\" --data \"" + escape_json(jsonData) + "\"";
            //system(command.c_str());
        }
        std::cout << "Terminou de ler a tabela metas" << '\n';
        std::cout << "Iniciando a leitura da tabela regionais" << '\n';
        mysql_query(connect,"SELECT * FROM regionais");
        res_set = mysql_store_result( connect );
        numRows = mysql_num_rows( res_set );
        //TABELA REGIONAIS
        while( ( row = mysql_fetch_row( res_set ) ) != NULL ){
            //std::cout << row[0] << " | " << row[1] <<'\n';

            std::string jsonData = "{";
            jsonData += "\"municipio\":\"" + escape_json(row[0]) + "\",";
            jsonData += "\"regional_senai\":\"" + escape_json(row[1]);
            jsonData += "\"}";
            //std::cout << jsonData << '\n';
            std::string command = "curl -v -X POST http://demo.thingsboard.io/api/v1/*****************/telemetry --header \"Content-Type:application/json\" --data \"" + escape_json(jsonData) + "\"";
            system(command.c_str());
        }
        std::cout << '\n';
        std::cout << "Terminou de enviar para o thingsboard!" << '\n';
        mysql_close(connect);
        return 0;

    }catch( ... ){
        std::cout << "Falha ao conectar." << '\n';
    }
}

std::string escape_json(const std::string& input) {
    std::string escaped;
    for (char ch : input) {
        if (ch == '"') {
            escaped += "\\\"";
        } else if (ch == '\\') {
            escaped += "\\\\";
        } else {
            escaped += ch;
        }
    }
    return escaped;
}

// Função para converter string UTF-8 para std::string
std::string to_utf8(const std::wstring& wide_str) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.to_bytes(wide_str);
}

//g++ read.cpp -L /usr/include/mysql -lmysqlclient -I /usr/include/mysql - o read
