/*
  Some modules are: Cx Core, CV CVAUX, ML, HighGUI
 */
#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char** argv) {
  if ( argc != 2 )
    {
      std::cout << "usage: DisplayImage.out <Image_Path>\n";
      return -1;
    }

  cv::Mat A, C;
  A = cv::imread( argv[1],  CV_LOAD_IMAGE_COLOR); // allocate matrix

  cv::Mat B(A); // copy constructor

  C = A; // Assignment operator

  cv::Mat D (A, cv::Rect(1, 1, 5, 5) ); // using a rectangle

  cv::Mat E = D(cv::Range::all(), cv::Range(1,3)); // using row and column boundaries
  std::cout << "A = " << std::endl << " " << A
	    << std::endl << std::endl;
  
  std::cout << "D = " << std::endl << " " << D
	    << std::endl << std::endl;

  std::cout << "E = " << std::endl << " " << E
	    << std::endl << std::endl;

  // cloning a Mat object
  cv::Mat F = E.clone();
  cv::Mat G;
  E.copyTo(G);

  /* Atoring methods
     Select color space and data type used 
     1. Color spaces: gray, rgb, rgba, bgr, 
        hsv, hls, YCrCb(JPEG), CIE L*a*b*
     2. Data type: uint8, int8, int32, int64, 
        float, double
  */

  // creating a Mat object explicity
  cv::Mat M(2,2,CV_8UC3, cv::Scalar(0,0,255));
  std::cout << "M = " << std::endl << " " << M
	    << std::endl << std::endl;

  return 0;
}
