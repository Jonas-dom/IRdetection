#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

// ������������
Point2f calculateCentroid(const vector<Point>& polygon) {
    Moments m = moments(polygon);
    return Point2f(static_cast<float>(m.m10 / m.m00), static_cast<float>(m.m01 / m.m00));
}

// ���ͼ���еĺ�ɫ��ǵ㲢��ȡ�ؼ���
void detectMarkers(const Mat& image, vector<Point2f>& outputPoints, double areaThreshold) {
    Mat gray, binary;
    cvtColor(image, gray, COLOR_BGR2GRAY);

    // ��ת��ɫ������ɫ��תΪ��ɫ����Ȼ����ж�ֵ��
    bitwise_not(gray, gray);
    imshow("Gray Image (Inverted)", gray); // ��ʾ�Ҷȷ�תͼ��
    waitKey(0);

    threshold(gray, binary, 80, 255, THRESH_BINARY);
    imshow("Binary Image", binary); // ��ʾ��ֵͼ��
    waitKey(0);

    // ʹ����̬ѧ����ȥ��С����
    Mat morphElement = getStructuringElement(MORPH_RECT, Size(1, 1));
    morphologyEx(binary, binary, MORPH_OPEN, morphElement);
    imshow("After Morphological Opening", binary); // ��ʾ��̬ѧ������ͼ��
    waitKey(0);

    // Ѱ������
    vector<vector<Point>> contours;
    findContours(binary, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    for (const auto& contour : contours) {
        double contourAreaValue = contourArea(contour);
        if (contourAreaValue < areaThreshold) {
            continue; // ���˵����С������
        }

        // ��ȡ͹�����ƽ�Ϊ�����
        vector<Point> hull;
        convexHull(contour, hull);

        vector<Point> approx;
        approxPolyDP(hull, approx, arcLength(hull, true) * 0.09, true);

        // ���ݶ�����������״�������жϱ������
        if (approx.size() == 4) {
            // ��⵽�ı��α��
            Point2f centroid = calculateCentroid(approx);
            outputPoints.insert(outputPoints.begin(), centroid); // ���ı�������ʼ�շ��ڵ�һ��λ��
            cout << "��⵽�ı��Σ���������: (" << centroid.x << ", " << centroid.y << ")" << endl;
        }
        else if (approx.size() == 3) {
            // ��⵽�����α�ǣ�����Ҫ����ʶ��ֱ�Ƕ��㣩
            outputPoints.push_back(calculateCentroid(approx));
            cout << "��⵽�����Σ���������: (" << outputPoints.back().x << ", " << outputPoints.back().y << ")" << endl;
        }
    }
}

// ����������֮���ŷʽ����
double calculateDistance(const Point2f& pt1, const Point2f& pt2) {
    return norm(pt1 - pt2);
}

// ��ע��⵽�ĵ�;���
void annotatePoints(Mat& image, const vector<Point2f>& points) {
    for (size_t i = 0; i < points.size(); i++) {
        // ��ע��
        circle(image, points[i], 5, Scalar(0, 255, 0), -1);
        putText(image, "P" + to_string(i + 1), points[i] + Point2f(5, -5), FONT_HERSHEY_SIMPLEX, 0.6, Scalar(0, 255, 0), 0.5);
    }

    for (size_t i = 0; i < points.size(); i++) {
        size_t j = (i + 1) % points.size();
        double distance = calculateDistance(points[i], points[j]);
        Point2f midpoint = (points[i] + points[j]) * 0.5;
        string distanceText = "D" + to_string(i + 1) + "-" + to_string(j + 1) + ": " + to_string(distance);

        // ��ע����
        putText(image, distanceText, midpoint, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
        line(image, points[i], points[j], Scalar(0, 0, 255), 1);
    }
}

int main() {
    // ����ڲξ���ͻ���ϵ�����������У׼�����д��
    Mat cameraMatrix = (Mat_<double>(3, 3) << 1.5651e+03, 0, 349.9401,
        0, 1.5657e+03, 281.1659,
        0, 0, 1);
    Mat distCoeffs = (Mat_<double>(1, 5) << -0.4660, -3.3158, 0, 0, 0);

    // ��ȡͼ�񲢽��л������
    Mat image = imread("C:/Users/admin/Desktop/calibration/4444.jpg");
    if (image.empty()) {
        cerr << "�޷���ȡͼ���ļ���" << endl;
        return -1;
    }

    Mat undistortedImage;
    undistort(image, undistortedImage, cameraMatrix, distCoeffs);
    imshow("Undistorted Image", undistortedImage); // ��ʾ����������ͼ��
    waitKey(0);

    vector<Point2f> detectedPoints;
    double areaThreshold = 10.0; // ���������ֵ������С��������
    detectMarkers(undistortedImage, detectedPoints, areaThreshold);

    annotatePoints(undistortedImage, detectedPoints);

    imshow("Detected Markers with Distances", undistortedImage); // ��ʾ���ձ�ע���
    waitKey(0);

    return 0;
}
