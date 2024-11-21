#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

// 计算多边形重心
Point2f calculateCentroid(const vector<Point>& polygon) {
    Moments m = moments(polygon);
    return Point2f(static_cast<float>(m.m10 / m.m00), static_cast<float>(m.m01 / m.m00));
}

// 检测图像中的黑色标记点并提取关键点
void detectMarkers(const Mat& image, vector<Point2f>& outputPoints, double areaThreshold) {
    Mat gray, binary;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // 反转颜色（将黑色点转为白色），然后进行二值化
    bitwise_not(gray, gray);
    imshow("Gray Image (Inverted)", gray); // 显示灰度反转图像
    waitKey(0);

    threshold(gray, binary, 80, 255, THRESH_BINARY);
    imshow("Binary Image", binary); // 显示二值图像
    waitKey(0);

    // 使用形态学操作去除小噪声
    Mat morphElement = getStructuringElement(MORPH_RECT, Size(1, 1));
    morphologyEx(binary, binary, MORPH_OPEN, morphElement);
    imshow("After Morphological Opening", binary); // 显示形态学处理后的图像
    waitKey(0);

    // 寻找轮廓
    vector<vector<Point>> contours;
    findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    for (const auto& contour : contours) {
        double contourAreaValue = contourArea(contour);
        if (contourAreaValue < areaThreshold) {
            continue; // 过滤掉面积小的轮廓
        }

        // 获取凸包并逼近为多边形
        vector<Point> hull;
        convexHull(contour, hull);

        vector<Point> approx;
        approxPolyDP(hull, approx, arcLength(hull, true) * 0.09, true);

        // 根据顶点数量和形状特征来判断标记类型
        if (approx.size() == 4) {
            // 检测到四边形标记
            Point2f centroid = calculateCentroid(approx);
            outputPoints.insert(outputPoints.begin(), centroid); // 将四边形重心始终放在第一个位置
            cout << "检测到四边形，重心坐标: (" << centroid.x << ", " << centroid.y << ")" << endl;
        }
        else if (approx.size() == 3) {
            // 检测到三角形标记（如需要，可识别直角顶点）
            outputPoints.push_back(calculateCentroid(approx));
            cout << "检测到三角形，重心坐标: (" << outputPoints.back().x << ", " << outputPoints.back().y << ")" << endl;
        }
    }
}

// 计算两个点之间的欧式距离
double calculateDistance(const Point2f& pt1, const Point2f& pt2) {
    return norm(pt1 - pt2);
}

// 标注检测到的点和距离
void annotatePoints(Mat& image, const vector<Point2f>& points) {
    for (size_t i = 0; i < points.size(); i++) {
        // 标注点
        circle(image, points[i], 5, Scalar(0, 255, 0), -1);
        putText(image, "P" + to_string(i + 1), points[i] + Point2f(5, -5), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 255, 0), 0.5);
    }

    for (size_t i = 0; i < points.size(); i++) {
        size_t j = (i + 1) % points.size();
        double distance = calculateDistance(points[i], points[j]);
        Point2f midpoint = (points[i] + points[j]) * 0.5;
        string distanceText = "D" + to_string(i + 1) + "-" + to_string(j + 1) + ": " + to_string(distance);

        // 标注距离
        putText(image, distanceText, midpoint, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
        line(image, points[i], points[j], Scalar(0, 0, 255), 1);
    }
}

int main() {
    // 相机内参矩阵和畸变系数（根据相机校准结果填写）
    Mat cameraMatrix = (Mat_<double>(3, 3) << 1.5651e+03, 0, 349.9401,
        0, 1.5657e+03, 281.1659,
        0, 0, 1);
    Mat distCoeffs = (Mat_<double>(1, 5) << -0.4660, -3.3158, 0, 0, 0);

    // 读取图像并进行畸变矫正
    Mat image = imread("C:/Users/admin/Desktop/calibration/4444.jpg");
    if (image.empty()) {
        cerr << "无法读取图像文件！" << endl;
        return -1;
    }

    Mat undistortedImage;
    undistort(image, undistortedImage, cameraMatrix, distCoeffs);
    imshow("Undistorted Image", undistortedImage); // 显示畸变矫正后的图像
    waitKey(0);

    vector<Point2f> detectedPoints;
    double areaThreshold = 10.0; // 设置面积阈值，过滤小干扰轮廓
    detectMarkers(undistortedImage, detectedPoints, areaThreshold);

    annotatePoints(undistortedImage, detectedPoints);

    imshow("Detected Markers with Distances", undistortedImage); // 显示最终标注结果
    waitKey(0);

    return 0;
}
