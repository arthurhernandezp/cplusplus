#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
int main() {
    cv::Mat img, img_canny;
    cv::VideoCapture cap ( 0 );

    while( true ){
        cap.read( img );
        cv::imshow("Minha webcam", img);
        cv::waitKey( 1 );
    }

    return 0;
}
