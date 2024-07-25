#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
int main() {
    std::string path = "jogo.jpg";
    cv::Mat img = cv::imread( path ), img_rainbow, img_bw, img_gaussian, img_canny, img_canny_dilated, img_erode;
    //cv::cvtColor( img, img_rainbow, cv::COLORMAP_RAINBOW );
    //cv::cvtColor( img, img_bw, 6 );
    //cv::GaussianBlur( img, img_gaussian, cv::Size(7,7), 2);
    //cv::Canny( img, img_canny, 6, 93);
    //cv::dilate( img_canny, img_canny_dilated, cv::getStructuringElement( 2, cv::Size(4,4) ) );
    //cv::erode( img_canny, img_erode, cv::getStructuringElement( 1, cv::Size( 2, 2) ) );
    cv::imshow("Imagem original", img);
    //cv::imshow("Imagem original", img_erode);
    //cv::imshow("Imagem Canny", img_canny);
    //cv::imshow("Imagem Canny", img_canny_dilated);
    //cv::imshow("Imagem Gaussian", img_gaussian);
    //cv::imshow("Rainbow", img_rainbow);
    //cv::imshow("Black and White", img_bw);

    cv::waitKey( 0 );

    return 0;
}
