

#include <iostream>
#include "CubeToFishLUTBuilder.h"

using namespace CubemapToFisheye;


int main()
{
	CubeToFishLUTBuilder ctfBuilder;
	cv::Mat k = (cv::Mat_<double>(3, 3) << 3.4785700891916935e+02, 0., 6.6456087637359985e+02, 0.,
	   3.4684162049611314e+02, 3.7127164435740463e+02, 0., 0., 1. );
	cv::Vec4d dist(-1.3546745328679019e-02, 3.2778169224761300e-03,
		-1.8706797173545517e-03, 6.1391222292769867e-05);


	ctfBuilder.BuildLUT(cv::Size(1280, 720), k, dist, 512);
	ctfBuilder.LoadBinary("../TestData/");

	ctfBuilder.SaveBinary("../TestData/");

	std::vector<cv::Mat> faces;

	faces.push_back(cv::imread("../TestData/demo@right.jpg"));
	faces.push_back(cv::imread("../TestData/demo@left.jpg"));
	faces.push_back(cv::imread("../TestData/demo@top.jpg"));
	faces.push_back(cv::imread("../TestData/demo@bottom.jpg"));
	faces.push_back(cv::imread("../TestData/demo@front.jpg"));
	faces.push_back(cv::imread("../TestData/demo@back.jpg"));

	cv::Mat projected;
	ctfBuilder.ProjectImage(faces, projected);

	int i = 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
