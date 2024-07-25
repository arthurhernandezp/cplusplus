#include <gtkmm.h>
#include <iostream>
#include <regex>
using namespace Gtk;

Window * pWindow;
Entry * num_1, * num_2, * result;
Button * btn_soma;
Label * title_label;

bool verifica_campo_num( std::string str ){
    std::regex re("^[0-9]+$");
    std::smatch match;
    return std::regex_search( str, match, re );
}

void on_btn_soma_clicked(){
    std::string a = num_1->get_text();
    std::string b = num_2->get_text();
    std::cout << "O valor de num_1 e: " << a << " e o valor de num_2 e: " << b << std::endl;

    if( verifica_campo_num( a ) && verifica_campo_num( b ) ){
        int x = std::stoi( a );
        int y = std::stoi( b );
        result->set_text( std::to_string( x + y ) );
        num_1->set_text("");
        num_2->set_text("");
    }else{
        title_label->set_text("Insira somente numeros");
    }
}

int main( int argc, char ** argv ){
    auto app = Application::create(argc, argv, "org.gtkmm.exemplo");
	auto refBuilder = Builder::create();

	refBuilder->add_from_file("soma.glade");
	refBuilder->get_widget( "window" , pWindow );
	if( pWindow ){
        refBuilder->get_widget("title_label", title_label);
		refBuilder->get_widget("num_1", num_1);
		refBuilder->get_widget("num_2", num_2);
		refBuilder->get_widget("btn_soma", btn_soma);
        refBuilder->get_widget("result", result);
	}

    if( btn_soma ){
        btn_soma->signal_clicked().connect( sigc::ptr_fun( on_btn_soma_clicked ) );
    }

	app->run( *pWindow );

	delete pWindow;
	return 0;
}
//g++ soma.cpp -o soma `pkg-config --cflags --libs gtkmm-3.0` -export-dynamic
