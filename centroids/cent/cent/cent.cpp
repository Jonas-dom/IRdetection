//���ǵ�һ�� ʶ����������
// 
// 
// 
// #include <opencv2/opencv.hpp>
// 
//#include <iostream>
//
//using namespace std;
//using namespace cv;
//
//int main() {
//    // ��ȡͼ��
//    Mat image = imread("C:/Users/Administrator/Desktop/p/angle 1.jpg");
//    if (image.empty()) {
//        cerr << "�޷���ȡͼ��" << std::endl;
//        return -1;
//    }
//
//    // ת��Ϊ�Ҷ�ͼ��
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // Ӧ����ֵ
//    Mat binary;
//    threshold(gray, binary, 128, 255, cv::THRESH_BINARY);
//
//    // ��������
//    vector<std::vector<cv::Point>> contours;
//    findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
//
//    // ��������������
//    for (const auto& contour : contours) {
//        Moments m = moments(contour);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//
//        drawContours(image, std::vector<std::vector<cv::Point>>{contour}, -1, Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1);
//    }
//
//    // ��ʾ���
//    cv::imshow("����", image);
//    cv::waitKey(0);
//    return 0;
//}
//
//
//
// ���ǵڶ���  ����ʶ������
// 
// 
//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//int main() {
//    // ��ȡͼ��
//    cv::Mat image = cv::imread("C:/Users/Administrator/Desktop/p/angle 1.jpg");
//    if (image.empty()) {
//        std::cerr << "�޷���ȡͼ��" << std::endl;
//        return -1;
//    }
//
//    // ת��Ϊ�Ҷ�ͼ��
//    cv::Mat gray;
//    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // Ӧ����ֵ
//    cv::Mat binary;
//    cv::threshold(gray, binary, 128, 255, cv::THRESH_BINARY);
//
//    // ��������
//    std::vector<std::vector<cv::Point>> contours;
//    cv::findContours(binary, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
//
//    // ��������������
//    for (const auto& contour : contours) {
//        if (cv::contourArea(contour) < 100) continue; // ����С����
//
//        cv::Moments m = cv::moments(contour);
//        cv::Point center(m.m10 / m.m00, m.m01 / m.m00);
//
//        std::cout << "��������: (" << center.x << ", " << center.y << ")" << std::endl;
//
//        cv::drawContours(image, std::vector<std::vector<cv::Point>>{contour}, -1, cv::Scalar(0, 255, 0), 2);
//        cv::circle(image, center, 5, cv::Scalar(255, 0, 0), -1);
//    
//
//        cv::drawContours(image, std::vector<std::vector<cv::Point>>{contour}, -1, cv::Scalar(0, 255, 0), 2);
//        cv::circle(image, center, 5, cv::Scalar(255, 0, 0), -1);
//    }
//
//    // ��ʾ���
//    cv::imwrite("����.jpg", image);
//    cv::imshow("����", image);
//
//    cv::waitKey(0);
//    return 0;
//}


//���ǵ����� ����Ӧλ�õ��������
// 
// 
//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//
//int main() {
//    // ��ȡͼ��
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/222.jpg");
//    if (image.empty())
//    {
//        cerr << "�޷���ȡͼ��" << endl;
//        return -1;
//    }
//
//    // ת��Ϊ�Ҷ�ͼ��
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // Ӧ����ֵ
//    Mat binary;
//    threshold(gray, binary, 146, 255, cv::THRESH_BINARY);
//
//    // ��������
//    vector<std::vector<cv::Point>> contours;
//    findContours(binary, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centers; // �洢��������
//    int count = 0;// �����������
//
//    // ���������ͼ�������
//    for (size_t i = 0; i < contours.size(); ++i)
//    {
//        if (contourArea(contours[i]) < 10) continue; // ����С����
//
//        Moments m = cv::moments(contours[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centers.push_back(center); // �洢��������
//
//
//        // �������
//        count++;
//
//        // ��������
//        drawContours(image, contours, static_cast<int>(i), Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1);
//        // ������λ��������
//        string text = to_string(count); // ʹ���������
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
//    }
//
//    // �����������
//    for (size_t i = 0; i < centers.size(); ++i) 
//    {
//        cout << "���� " << i + 1 << " ����������: (" << centers[i].x << ", " << centers[i].y << ")" << endl;
//    }
//
//    // ֻ�����������������������
//    if (centers.size() >= 4)
//    {
//        cout << "��4����������������: (" << centers[3].x << ", " << centers[3].y << ")" << endl;
//    }
//    else 
//    {
//        cout << "û���㹻������" << endl;
//    }
//
//    // ��ʾ���
//    imwrite("����.jpg", image);
//    imshow("����", image);
//
//    waitKey(0);
//    return 0;
//}

// ���ǵ��İ棬ʶ�����������

//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//int main() 
//{
//    // ��ȡͼ��
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/3333.jpg");
//    if (image.empty()) 
//    {
//        cerr << "�޷���ȡͼ��" << endl;
//        return -1;
//    }
//
//    // ת��Ϊ�Ҷ�ͼ��
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // ---------- ������������� --------------
//    // Ӧ����ֵ����������ĵ�
//    Mat binaryBright;
//    threshold(gray, binaryBright, 230, 255, cv::THRESH_BINARY); // 200Ϊ������ֵ
//
//    vector<std::vector<Point>> contoursBright;
//    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersBright; // �洢���������
//    int countBright = 0; // �����������
//
//    // �������������ͼ�������
//    for (size_t i = 0; i < contoursBright.size(); ++i) 
//    {
//        if (contourArea(contoursBright[i]) < 40) continue; // ����С����
//
//        Moments m = moments(contoursBright[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersBright.push_back(center); // �洢��������
//
//        // ������������
//        drawContours(image, contoursBright, static_cast<int>(i), Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1); // ��ɫȦ����������
//
//        // ��Ǳ��
//        countBright++;
//        string text = "B" + to_string(countBright); // ʹ��B��ʾ����
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
//    }
//
//    // ---------- ���������� --------------
//    // Ӧ����ֵ�������ĵ�
//    Mat binaryDark;
//    threshold(gray, binaryDark, 100, 255, cv::THRESH_BINARY_INV); // 50Ϊ������ֵ
//
//    vector<std::vector<Point>> contoursDark;
//    findContours(binaryDark, contoursDark, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersDark; // �洢���������
//    int countDark = 0; // �����������
//
//    // ���ư��������ͼ�������
//    for (size_t i = 0; i < contoursDark.size(); ++i) 
//    {
//        if (contourArea(contoursDark[i]) < 20) continue; // ����С����
//
//        Moments m = moments(contoursDark[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersDark.push_back(center); // �洢��������
//
//        // ���ư�������
//        drawContours(image, contoursDark, static_cast<int>(i), Scalar(255, 0, 0), 2);
//        circle(image, center, 5, Scalar(0, 0, 255), -1); // ��ɫȦ����������
//
//        // ��Ǳ��
//        countDark++;
//        string text = "D" + to_string(countDark); // ʹ��D��ʾ����
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
//    }
//
//    // ���������������
//    cout << "������������: " << endl;
//    for (size_t i = 0; i < centersBright.size(); ++i) 
//    {
//        cout << "���� " << i + 1 << " ������: (" << centersBright[i].x << ", " << centersBright[i].y << ")" << endl;
//    }
//
//    // ���������������
//    cout << "������������: " << endl;
//    for (size_t i = 0; i < centersDark.size(); ++i) 
//    {
//        cout << "���� " << i + 1 << " ������: (" << centersDark[i].x << ", " << centersDark[i].y << ")" << endl;
//    }
//
//    // ��ʾ���
//    imwrite("����Ͱ�������.jpg", image);
//    imshow("����", image);
//
//    waitKey(0);
//    return 0;
//}



//����� �Ż���ɫ������ϸ��


//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    // ��ȡͼ��
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/111.jpg");
//    if (image.empty())
//    {
//        cerr << "�޷���ȡͼ��" << endl;
//        return -1;
//    }
//
//    // ת��Ϊ�Ҷ�ͼ��
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // ---------- ������������� --------------
//    // Ӧ����ֵ����������ĵ�
//    Mat binaryBright;
//    threshold(gray, binaryBright, 230, 255, cv::THRESH_BINARY); // ������ֵΪ230
//
//    vector<std::vector<Point>> contoursBright;
//    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersBright; // �洢���������
//    int countBright = 0; // �����������
//
//    // �������������ͼ�������
//    for (size_t i = 0; i < contoursBright.size(); ++i)
//    {
//        if (contourArea(contoursBright[i]) < 40) continue; // ����С����
//
//        Moments m = moments(contoursBright[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersBright.push_back(center); // �洢��������
//
//        // ������������
//        drawContours(image, contoursBright, static_cast<int>(i), Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1); // ��ɫȦ����������
//
//        // ��Ǳ��
//        countBright++;
//        string text = "B" + to_string(countBright); // ʹ��B��ʾ����
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
//    }
//
//    // ---------- ʹ������Ӧ��ֵ���������� --------------
//    // ����Ӧ��ֵ������ͬ���������µİ�����
//    Mat binaryDark;
//    adaptiveThreshold(gray, binaryDark, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 9, 3); // ����Ӧ��ֵ
//
//    vector<std::vector<Point>> contoursDark;
//    findContours(binaryDark, contoursDark, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersDark; // �洢���������
//    int countDark = 0; // �����������
//
//    // ���ư��������ͼ�������
//    for (size_t i = 0; i < contoursDark.size(); ++i)
//    {
//        if (contourArea(contoursDark[i]) < 20) continue; // ����С����
//
//        Moments m = moments(contoursDark[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersDark.push_back(center); // �洢��������
//
//        // ���ư�������
//        drawContours(image, contoursDark, static_cast<int>(i), Scalar(255, 0, 0), 2);
//        circle(image, center, 5, Scalar(0, 0, 255), -1); // ��ɫȦ����������
//
//        // ��Ǳ��
//        countDark++;
//        string text = "D" + to_string(countDark); // ʹ��D��ʾ����
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
//    }
//
//    // ���������������
//    cout << "������������: " << endl;
//    for (size_t i = 0; i < centersBright.size(); ++i)
//    {
//        cout << "���� " << i + 1 << " ������: (" << centersBright[i].x << ", " << centersBright[i].y << ")" << endl;
//    }
//
//    // ���������������
//    cout << "������������: " << endl;
//    for (size_t i = 0; i < centersDark.size(); ++i)
//    {
//        cout << "���� " << i + 1 << " ������: (" << centersDark[i].x << ", " << centersDark[i].y << ")" << endl;
//    }
//
//    // ��ʾ���
//    imwrite("����Ͱ�������.jpg", image);
//    imshow("����", image);
//
//    waitKey(0);
//    return 0;
//}
//


//����trackbar ������ ��̬���� ʹ�ò����仯��ʱ����


//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//// �ص�������������Ӧ�������ı仯
//void onTrackbarChange(int, void* userdata)
//{
//    // ͨ��ָ���ȡԭͼ��
//    Mat* img = (Mat*)userdata;
//    Mat gray;
//    cvtColor(*img, gray, COLOR_BGR2GRAY);
//
//    // ��ȡ��������ֵ
//    int brightThresh = getTrackbarPos("������ֵ", "��������");
//    int minAreaBright = getTrackbarPos("������С���", "��������");
//    int darkBlockSize = getTrackbarPos("����BlockSize", "��������");
//    int minAreaDark = getTrackbarPos("������С���", "��������");
//
//    // ȷ�� darkBlockSize Ϊ����
//    if (darkBlockSize % 2 == 0) {
//        darkBlockSize += 1;
//    }
//
//    // ��������
//    Mat binaryBright;
//    threshold(gray, binaryBright, brightThresh, 255, THRESH_BINARY);
//
//    vector<vector<Point>> contoursBright;
//    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    Mat outputImage = img->clone(); // ����ԭʼͼ��
//    vector<Point> centersBright;
//    int countBright = 0;
//
//    for (size_t i = 0; i < contoursBright.size(); ++i)
//    {
//        if (contourArea(contoursBright[i]) < minAreaBright) continue; // ����С����
//
//        Moments m = moments(contoursBright[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersBright.push_back(center);
//
//        drawContours(outputImage, contoursBright, static_cast<int>(i), Scalar(0, 255, 0), 2);
//        circle(outputImage, center, 5, Scalar(255, 0, 0), -1);
//
//        countBright++;
//        string text = "B" + to_string(countBright);
//        putText(outputImage, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
//    }
//
//    // ����Ӧ��ֵ��ⰵ��
//    Mat binaryDark;
//    adaptiveThreshold(gray, binaryDark, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, darkBlockSize, 2);
//
//    vector<vector<Point>> contoursDark;
//    findContours(binaryDark, contoursDark, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersDark;
//    int countDark = 0;
//
//    for (size_t i = 0; i < contoursDark.size(); ++i)
//    {
//        if (contourArea(contoursDark[i]) < minAreaDark) continue; // ����С����
//
//        Moments m = moments(contoursDark[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersDark.push_back(center);
//
//        drawContours(outputImage, contoursDark, static_cast<int>(i), Scalar(255, 0, 0), 2);
//        circle(outputImage, center, 5, Scalar(0, 0, 255), -1);
//
//        countDark++;
//        string text = "D" + to_string(countDark);
//        putText(outputImage, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
//    }
//
//    // ��ʾ���
//    imshow("�����", outputImage);
//    try {
//        // ���ÿ��������쳣�Ĵ���
//        imshow("�����", outputImage);
//    }
//    catch (const cv::Exception& e) {
//        cerr << "OpenCV ����: " << e.what() << endl;
//    }
//
//}
//
//int main()
//{
//    // ��ȡͼ��
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/3333.jpg");
//    if (image.empty())
//    {
//        cerr << "�޷���ȡͼ��" << endl;
//        return -1;
//    }
// 
//
//    // ������ʾ����
//    namedWindow("�����", WINDOW_AUTOSIZE);
//    namedWindow("��������", WINDOW_AUTOSIZE);
//
//    // ��ʼ������������
//    int brightThresh = 230;
//    int minAreaBright = 40;
//    int darkBlockSize = 11;
//    int minAreaDark = 20;
//
//    // �������������󶨵��ص�����
//    createTrackbar("������ֵ", "��������", &brightThresh, 255, onTrackbarChange, &image);
//    createTrackbar("������С���", "��������", &minAreaBright, 500, onTrackbarChange, &image);
//    createTrackbar("����BlockSize", "��������", &darkBlockSize, 25, onTrackbarChange, &image);
//    createTrackbar("������С���", "��������", &minAreaDark, 500, onTrackbarChange, &image);
//
//    // �ֶ�����һ�λص���������ʾ��ʼ���
//    onTrackbarChange(0, &image);
//
//    // �ȴ������˳�
//    waitKey(0);
//    return 0;
//}



// ����ԭͼ��ʾ���ܣ����Ա�

//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    // ��ȡͼ��
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/111.jpg");
//    if (image.empty())
//    {
//        cerr << "�޷���ȡͼ��" << endl;
//        return -1;
//    }
//
//    // ����ԭͼ�ĸ���
//    Mat originalImage = image.clone();
//
//    // ��ʾԭͼ
//    imshow("ԭͼ", originalImage);
//
//    // ת��Ϊ�Ҷ�ͼ��
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // ---------- ������������� --------------
//    // Ӧ����ֵ����������ĵ�
//    Mat binaryBright;
//    threshold(gray, binaryBright, 230, 255, cv::THRESH_BINARY); // ������ֵΪ230
//
//    vector<std::vector<Point>> contoursBright;
//    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersBright; // �洢���������
//    int countBright = 0; // �����������
//
//    // �������������ͼ�������
//    for (size_t i = 0; i < contoursBright.size(); ++i)
//    {
//        if (contourArea(contoursBright[i]) < 40) continue; // ����С����
//
//        Moments m = moments(contoursBright[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersBright.push_back(center); // �洢��������
//
//        // ������������
//        drawContours(image, contoursBright, static_cast<int>(i), Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1); // ��ɫȦ����������
//
//        // ��Ǳ��
//        countBright++;
//        string text = "B" + to_string(countBright); // ʹ��B��ʾ����
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
//    }
//
//    // ---------- ʹ������Ӧ��ֵ���������� --------------
//    // ����Ӧ��ֵ������ͬ���������µİ�����
//    Mat binaryDark;
//    adaptiveThreshold(gray, binaryDark, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 9, 3); // ����Ӧ��ֵ
//
//    vector<std::vector<Point>> contoursDark;
//    findContours(binaryDark, contoursDark, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersDark; // �洢���������
//    int countDark = 0; // �����������
//
//    // ���ư��������ͼ�������
//    for (size_t i = 0; i < contoursDark.size(); ++i)
//    {
//        if (contourArea(contoursDark[i]) < 20) continue; // ����С����
//
//        Moments m = moments(contoursDark[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersDark.push_back(center); // �洢��������
//
//        // ���ư�������
//        drawContours(image, contoursDark, static_cast<int>(i), Scalar(255, 0, 0), 2);
//        circle(image, center, 5, Scalar(0, 0, 255), -1); // ��ɫȦ����������
//
//        // ��Ǳ��
//        countDark++;
//        string text = "D" + to_string(countDark); // ʹ��D��ʾ����
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
//    }
//
//    // ���������������
//    cout << "������������: " << endl;
//    for (size_t i = 0; i < centersBright.size(); ++i)
//    {
//        cout << "���� " << i + 1 << " ������: (" << centersBright[i].x << ", " << centersBright[i].y << ")" << endl;
//    }
//
//    // ���������������
//    cout << "������������: " << endl;
//    for (size_t i = 0; i < centersDark.size(); ++i)
//    {
//        cout << "���� " << i + 1 << " ������: (" << centersDark[i].x << ", " << centersDark[i].y << ")" << endl;
//    }
//
//    // ��ʾ���
//    imwrite("����Ͱ�������.jpg", image);
//
//    // ����һ���㹻��Ļ�������������ͼƬ
//    Mat combined;
//    hconcat(originalImage, image, combined);
//
//    imwrite("ԭͼ�봦���Ա�.jpg", combined);
//
//    // ��ʾԭͼ�ʹ�����ͼ��
//    imshow("ԭͼ | ������ͼ��", combined);
//
//
//    waitKey(0);
//    return 0;
//}


// ����͹�����

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    // ��ȡͼ��
    Mat image = imread("C:/Users/Administrator/Desktop/calibration/111.jpg");
    if (image.empty())
    {
        cerr << "�޷���ȡͼ��" << endl;
        return -1;
    }

    // ����ԭͼ�ĸ���
    Mat originalImage = image.clone();

    // ��ʾԭͼ
    imshow("ԭͼ", originalImage);

    // ת��Ϊ�Ҷ�ͼ��
    Mat gray;
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // ---------- ������������� --------------
    // Ӧ����ֵ����������ĵ�
    Mat binaryBright;
    threshold(gray, binaryBright, 230, 255, cv::THRESH_BINARY); // ������ֵΪ230

    vector<vector<Point>> contoursBright;
    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);

    vector<Point> centersBright; // �洢���������
    int countBright = 0; // �����������

    // �������������ͼ�������
    for (size_t i = 0; i < contoursBright.size(); ++i)
    {
        if (contourArea(contoursBright[i]) < 40) continue; // ����С����

        Moments m = moments(contoursBright[i]);
        Point center(m.m10 / m.m00, m.m01 / m.m00);
        centersBright.push_back(center); // �洢��������

        // ������������
        drawContours(image, contoursBright, static_cast<int>(i), Scalar(0, 255, 0), 2);
        circle(image, center, 5, Scalar(255, 0, 0), -1); // ��ɫȦ����������

        // ��Ǳ��
        countBright++;
        string text = "B" + to_string(countBright); // ʹ��B��ʾ����
        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
    }

    // ---------- ʹ������Ӧ��ֵ����������������͹�� --------------
    // ����Ӧ��ֵ������ͬ���������µİ�����
    Mat binaryDark;
    adaptiveThreshold(gray, binaryDark, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 9, 3); // ����Ӧ��ֵ

    vector<vector<Point>> contoursDark;
    findContours(binaryDark, contoursDark, RETR_LIST, CHAIN_APPROX_SIMPLE);

    vector<Point> centersDark; // �洢���������
    int countDark = 0; // �����������

    // ���ư����������������ĺ�͹��
    for (size_t i = 0; i < contoursDark.size(); ++i)
    {
        if (contourArea(contoursDark[i]) < 20) continue; // ����С����

        Moments m = moments(contoursDark[i]);
        Point center(m.m10 / m.m00, m.m01 / m.m00);
        centersDark.push_back(center); // �洢��������

        // ���ư�������
        drawContours(image, contoursDark, static_cast<int>(i), Scalar(255, 0, 0), 2);
        circle(image, center, 5, Scalar(0, 0, 255), -1); // ��ɫȦ����������

        // ��Ǳ��
        countDark++;
        string text = "D" + to_string(countDark); // ʹ��D��ʾ����
        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);

        // ���㰵���͹��
        vector<Point> hull;
        convexHull(contoursDark[i], hull);

        // ����͹������
        drawContours(image, vector<vector<Point>>{hull}, -1, Scalar(0, 255, 255), 2); // ��ɫ��ʾ͹��

        // ��ȡ͹���Ķ���������ע
        int vertexCount = hull.size();
        putText(image, "V" + to_string(vertexCount), center + Point(10, 10), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 1);
    }

    // ���������������
    cout << "������������: " << endl;
    for (size_t i = 0; i < centersBright.size(); ++i)
    {
        cout << "���� " << i + 1 << " ������: (" << centersBright[i].x << ", " << centersBright[i].y << ")" << endl;
    }

    // ���������������
    cout << "������������: " << endl;
    for (size_t i = 0; i < centersDark.size(); ++i)
    {
        cout << "���� " << i + 1 << " ������: (" << centersDark[i].x << ", " << centersDark[i].y << ")" << endl;
    }

    // ������
    imwrite("����Ͱ���������͹��.jpg", image);

    // ����һ���㹻��Ļ�������������ͼƬ
    Mat combined;
    hconcat(originalImage, image, combined);

    imwrite("ԭͼ�봦���Ա�.jpg", combined);

    // ��ʾԭͼ�ʹ�����ͼ��
    imshow("ԭͼ | ������ͼ��", combined);

    waitKey(0);
    return 0;
}
