#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace cv;
using namespace std;


int main()

{
	system("color F0");
	Mat img = imread("C:/Users/admin/Desktop/calibration/1111.jpg");
	//Mat img = imread("D:/photo/6-17 12.54.jpg");
	if (img.empty())
	{
		cout << "确认文件名称" << endl;
		

		return -1;
	}
	imshow("原图", img);
	Mat gray, binary;
	cvtColor(img, gray, COLOR_BGR2GRAY);
	GaussianBlur(gray, gray, Size(17, 17), 4, 4);
	threshold(gray, binary, 170, 255, THRESH_BINARY | THRESH_OTSU);


	vector<vector<Point>> contours;
	vector<Vec4i>hierarchy;
	findContours(binary, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());

	for (int t = 0; t < contours.size(); t++)
	{

		drawContours(img, contours, t, Scalar(0, 0, 225), 2, 8);

	}

	for (int i = 0; i < hierarchy.size(); i++)
	{
		cout << hierarchy[i] << endl;
	}
	imwrite("轮廓.jpg", img);
	imshow("轮廓检测结果", img);
	waitKey(0);
	return(0);
}