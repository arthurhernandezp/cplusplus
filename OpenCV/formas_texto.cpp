#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
int main( int argc, char ** argv ) {
    cv::Mat img( 720, 1280, CV_8UC3, cv::Scalar( 155, 0, 0 ) );
    cv::circle( img, cv::Point( 250,250 ),50, cv::Scalar( 0,0,200 ), cv::FILLED );
    cv::rectangle( img, cv::Point( 500,400 ),  cv::Point( 700,500 ),  cv::Scalar( 0,250,0 ), cv::FILLED );
    cv::putText( img, "Eu sou o Arthur", cv::Point( 200, 400),cv::FONT_HERSHEY_COMPLEX, 2 ,cv::Scalar(255,255,255), 5 );
    cv::imshow("Fundo azul", img );

    cv::waitKey( 0 );
    return 0;
}
