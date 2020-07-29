// Hello....
#include <windows.h>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;;

wstring ExePath() {
    TCHAR buffer[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, buffer, MAX_PATH);
    std::wstring::size_type pos = std::wstring(buffer).find_last_of(L"\\/");
    return std::wstring(buffer).substr(0, pos);
}


int main(int argc, char* argv[]) {
    printf("Hello world\n");

    wcout << "my directory is " << ExePath() << "\n";

    // Read an image 
    cv::Mat image = cv::imread("C:/opencv/samples/data/lena.jpg");
    // cv::Mat image = cv::imread("../../../opencv/samples/data/lena.jpg");
    if (image.empty()) {
        std::cout << "Hey! Can't read the image!" << std::endl;
        system("PAUSE");
        return EXIT_FAILURE;
    }
    // Create image window named "My Image". (You actually don't have to do
    // this step, but this command allows you to set properties of the window,
    // such as its location, or whether you can resize it.)
    cv::namedWindow("My Image");
    // Show the image in the window
    cv::imshow("My Image", image);
    
    // Wait for 5000 ms (0 means wait until a keypress)
    cv::waitKey( 0 );

    return EXIT_SUCCESS;
}