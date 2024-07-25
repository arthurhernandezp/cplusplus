#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
int main() {
    std::string path = "./jogo.jpg";
    cv::Mat img = cv::imread( path ), img_resize, img_cut;

    std::cout << "Dimensoes da imagem: " << img.size() << '\n';
    std::cout << "Largura da imagem: " << img.size().width << '\n';
    std::cout << "Altura da imagem: " << img.size().height << '\n';
    std::cout << "Area da imagem: " << img.size().area() << '\n';

    //Redimensionar a imagem
    cv::resize( img, img_resize, cv::Size( img.size().width / 2, img.size().height / 2) );
    //cv::resize( img, img_resize, cv::Size(  ),0.5,0.5 ); Mesma coisa

    //Cortar a imagem
    img_cut = img( cv::Rect(0, 0, 200, 100) );


    cv::imshow("Original",img);
    cv::imshow("Redimensionada",img_resize);
    cv::imshow("Cortada",img_cut);
    cv::waitKey( 0 );
    return 0;
}
