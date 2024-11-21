//这是第一版 识别轮廓重心
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
//    // 读取图像
//    Mat image = imread("C:/Users/Administrator/Desktop/p/angle 1.jpg");
//    if (image.empty()) {
//        cerr << "无法读取图像" << std::endl;
//        return -1;
//    }
//
//    // 转换为灰度图像
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // 应用阈值
//    Mat binary;
//    threshold(gray, binary, 128, 255, cv::THRESH_BINARY);
//
//    // 查找轮廓
//    vector<std::vector<cv::Point>> contours;
//    findContours(binary, contours, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
//
//    // 绘制轮廓和重心
//    for (const auto& contour : contours) {
//        Moments m = moments(contour);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//
//        drawContours(image, std::vector<std::vector<cv::Point>>{contour}, -1, Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1);
//    }
//
//    // 显示结果
//    cv::imshow("重心", image);
//    cv::waitKey(0);
//    return 0;
//}
//
//
//
// 这是第二版  可以识别坐标
// 
// 
//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//int main() {
//    // 读取图像
//    cv::Mat image = cv::imread("C:/Users/Administrator/Desktop/p/angle 1.jpg");
//    if (image.empty()) {
//        std::cerr << "无法读取图像" << std::endl;
//        return -1;
//    }
//
//    // 转换为灰度图像
//    cv::Mat gray;
//    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // 应用阈值
//    cv::Mat binary;
//    cv::threshold(gray, binary, 128, 255, cv::THRESH_BINARY);
//
//    // 查找轮廓
//    std::vector<std::vector<cv::Point>> contours;
//    cv::findContours(binary, contours, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
//
//    // 绘制轮廓和重心
//    for (const auto& contour : contours) {
//        if (cv::contourArea(contour) < 100) continue; // 过滤小轮廓
//
//        cv::Moments m = cv::moments(contour);
//        cv::Point center(m.m10 / m.m00, m.m01 / m.m00);
//
//        std::cout << "重心坐标: (" << center.x << ", " << center.y << ")" << std::endl;
//
//        cv::drawContours(image, std::vector<std::vector<cv::Point>>{contour}, -1, cv::Scalar(0, 255, 0), 2);
//        cv::circle(image, center, 5, cv::Scalar(255, 0, 0), -1);
//    
//
//        cv::drawContours(image, std::vector<std::vector<cv::Point>>{contour}, -1, cv::Scalar(0, 255, 0), 2);
//        cv::circle(image, center, 5, cv::Scalar(255, 0, 0), -1);
//    }
//
//    // 显示结果
//    cv::imwrite("质心.jpg", image);
//    cv::imshow("重心", image);
//
//    cv::waitKey(0);
//    return 0;
//}


//这是第三版 将对应位置的坐标输出
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
//    // 读取图像
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/222.jpg");
//    if (image.empty())
//    {
//        cerr << "无法读取图像" << endl;
//        return -1;
//    }
//
//    // 转换为灰度图像
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // 应用阈值
//    Mat binary;
//    threshold(gray, binary, 146, 255, cv::THRESH_BINARY);
//
//    // 查找轮廓
//    vector<std::vector<cv::Point>> contours;
//    findContours(binary, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centers; // 存储重心坐标
//    int count = 0;// 用于连续编号
//
//    // 绘制轮廓和计算重心
//    for (size_t i = 0; i < contours.size(); ++i)
//    {
//        if (contourArea(contours[i]) < 10) continue; // 过滤小轮廓
//
//        Moments m = cv::moments(contours[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centers.push_back(center); // 存储重心坐标
//
//
//        // 递增编号
//        count++;
//
//        // 绘制轮廓
//        drawContours(image, contours, static_cast<int>(i), Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1);
//        // 在重心位置添加序号
//        string text = to_string(count); // 使用连续编号
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
//    }
//
//    // 输出重心坐标
//    for (size_t i = 0; i < centers.size(); ++i) 
//    {
//        cout << "轮廓 " << i + 1 << " 的质心坐标: (" << centers[i].x << ", " << centers[i].y << ")" << endl;
//    }
//
//    // 只输出第三个轮廓的重心坐标
//    if (centers.size() >= 4)
//    {
//        cout << "第4个轮廓的质心坐标: (" << centers[3].x << ", " << centers[3].y << ")" << endl;
//    }
//    else 
//    {
//        cout << "没有足够的轮廓" << endl;
//    }
//
//    // 显示结果
//    imwrite("质心.jpg", image);
//    imshow("重心", image);
//
//    waitKey(0);
//    return 0;
//}

// 这是第四版，识别高亮跟暗点

//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//int main() 
//{
//    // 读取图像
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/3333.jpg");
//    if (image.empty()) 
//    {
//        cerr << "无法读取图像" << endl;
//        return -1;
//    }
//
//    // 转换为灰度图像
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // ---------- 检测最亮点轮廓 --------------
//    // 应用阈值来检测最亮的点
//    Mat binaryBright;
//    threshold(gray, binaryBright, 230, 255, cv::THRESH_BINARY); // 200为亮点阈值
//
//    vector<std::vector<Point>> contoursBright;
//    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersBright; // 存储亮点的重心
//    int countBright = 0; // 用于连续编号
//
//    // 绘制亮点轮廓和计算重心
//    for (size_t i = 0; i < contoursBright.size(); ++i) 
//    {
//        if (contourArea(contoursBright[i]) < 40) continue; // 过滤小轮廓
//
//        Moments m = moments(contoursBright[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersBright.push_back(center); // 存储亮点重心
//
//        // 绘制亮点轮廓
//        drawContours(image, contoursBright, static_cast<int>(i), Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1); // 蓝色圈出亮点重心
//
//        // 标记编号
//        countBright++;
//        string text = "B" + to_string(countBright); // 使用B表示亮点
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
//    }
//
//    // ---------- 检测最暗点轮廓 --------------
//    // 应用阈值来检测最暗的点
//    Mat binaryDark;
//    threshold(gray, binaryDark, 100, 255, cv::THRESH_BINARY_INV); // 50为暗点阈值
//
//    vector<std::vector<Point>> contoursDark;
//    findContours(binaryDark, contoursDark, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersDark; // 存储暗点的重心
//    int countDark = 0; // 用于连续编号
//
//    // 绘制暗点轮廓和计算重心
//    for (size_t i = 0; i < contoursDark.size(); ++i) 
//    {
//        if (contourArea(contoursDark[i]) < 20) continue; // 过滤小轮廓
//
//        Moments m = moments(contoursDark[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersDark.push_back(center); // 存储暗点重心
//
//        // 绘制暗点轮廓
//        drawContours(image, contoursDark, static_cast<int>(i), Scalar(255, 0, 0), 2);
//        circle(image, center, 5, Scalar(0, 0, 255), -1); // 红色圈出暗点重心
//
//        // 标记编号
//        countDark++;
//        string text = "D" + to_string(countDark); // 使用D表示暗点
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
//    }
//
//    // 输出亮点重心坐标
//    cout << "亮点重心坐标: " << endl;
//    for (size_t i = 0; i < centersBright.size(); ++i) 
//    {
//        cout << "亮点 " << i + 1 << " 的重心: (" << centersBright[i].x << ", " << centersBright[i].y << ")" << endl;
//    }
//
//    // 输出暗点重心坐标
//    cout << "暗点重心坐标: " << endl;
//    for (size_t i = 0; i < centersDark.size(); ++i) 
//    {
//        cout << "暗点 " << i + 1 << " 的重心: (" << centersDark[i].x << ", " << centersDark[i].y << ")" << endl;
//    }
//
//    // 显示结果
//    imwrite("亮点和暗点轮廓.jpg", image);
//    imshow("重心", image);
//
//    waitKey(0);
//    return 0;
//}



//第五版 优化黑色轮廓的细节


//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    // 读取图像
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/111.jpg");
//    if (image.empty())
//    {
//        cerr << "无法读取图像" << endl;
//        return -1;
//    }
//
//    // 转换为灰度图像
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // ---------- 检测最亮点轮廓 --------------
//    // 应用阈值来检测最亮的点
//    Mat binaryBright;
//    threshold(gray, binaryBright, 230, 255, cv::THRESH_BINARY); // 亮点阈值为230
//
//    vector<std::vector<Point>> contoursBright;
//    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersBright; // 存储亮点的重心
//    int countBright = 0; // 用于连续编号
//
//    // 绘制亮点轮廓和计算重心
//    for (size_t i = 0; i < contoursBright.size(); ++i)
//    {
//        if (contourArea(contoursBright[i]) < 40) continue; // 过滤小轮廓
//
//        Moments m = moments(contoursBright[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersBright.push_back(center); // 存储亮点重心
//
//        // 绘制亮点轮廓
//        drawContours(image, contoursBright, static_cast<int>(i), Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1); // 蓝色圈出亮点重心
//
//        // 标记编号
//        countBright++;
//        string text = "B" + to_string(countBright); // 使用B表示亮点
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
//    }
//
//    // ---------- 使用自适应阈值检测最暗点轮廓 --------------
//    // 自适应阈值来处理不同光照条件下的暗点检测
//    Mat binaryDark;
//    adaptiveThreshold(gray, binaryDark, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 9, 3); // 自适应阈值
//
//    vector<std::vector<Point>> contoursDark;
//    findContours(binaryDark, contoursDark, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersDark; // 存储暗点的重心
//    int countDark = 0; // 用于连续编号
//
//    // 绘制暗点轮廓和计算重心
//    for (size_t i = 0; i < contoursDark.size(); ++i)
//    {
//        if (contourArea(contoursDark[i]) < 20) continue; // 过滤小轮廓
//
//        Moments m = moments(contoursDark[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersDark.push_back(center); // 存储暗点重心
//
//        // 绘制暗点轮廓
//        drawContours(image, contoursDark, static_cast<int>(i), Scalar(255, 0, 0), 2);
//        circle(image, center, 5, Scalar(0, 0, 255), -1); // 红色圈出暗点重心
//
//        // 标记编号
//        countDark++;
//        string text = "D" + to_string(countDark); // 使用D表示暗点
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
//    }
//
//    // 输出亮点重心坐标
//    cout << "亮点重心坐标: " << endl;
//    for (size_t i = 0; i < centersBright.size(); ++i)
//    {
//        cout << "亮点 " << i + 1 << " 的重心: (" << centersBright[i].x << ", " << centersBright[i].y << ")" << endl;
//    }
//
//    // 输出暗点重心坐标
//    cout << "暗点重心坐标: " << endl;
//    for (size_t i = 0; i < centersDark.size(); ++i)
//    {
//        cout << "暗点 " << i + 1 << " 的重心: (" << centersDark[i].x << ", " << centersDark[i].y << ")" << endl;
//    }
//
//    // 显示结果
//    imwrite("亮点和暗点轮廓.jpg", image);
//    imshow("重心", image);
//
//    waitKey(0);
//    return 0;
//}
//


//增加trackbar 滑动条 动态调参 使得参数变化适时进行


//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//// 回调函数，用于响应滑动条的变化
//void onTrackbarChange(int, void* userdata)
//{
//    // 通过指针获取原图像
//    Mat* img = (Mat*)userdata;
//    Mat gray;
//    cvtColor(*img, gray, COLOR_BGR2GRAY);
//
//    // 获取滑动条的值
//    int brightThresh = getTrackbarPos("亮点阈值", "参数调节");
//    int minAreaBright = getTrackbarPos("亮点最小面积", "参数调节");
//    int darkBlockSize = getTrackbarPos("暗点BlockSize", "参数调节");
//    int minAreaDark = getTrackbarPos("暗点最小面积", "参数调节");
//
//    // 确保 darkBlockSize 为奇数
//    if (darkBlockSize % 2 == 0) {
//        darkBlockSize += 1;
//    }
//
//    // 处理亮点
//    Mat binaryBright;
//    threshold(gray, binaryBright, brightThresh, 255, THRESH_BINARY);
//
//    vector<vector<Point>> contoursBright;
//    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    Mat outputImage = img->clone(); // 复制原始图像
//    vector<Point> centersBright;
//    int countBright = 0;
//
//    for (size_t i = 0; i < contoursBright.size(); ++i)
//    {
//        if (contourArea(contoursBright[i]) < minAreaBright) continue; // 忽略小轮廓
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
//    // 自适应阈值检测暗点
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
//        if (contourArea(contoursDark[i]) < minAreaDark) continue; // 忽略小轮廓
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
//    // 显示结果
//    imshow("检测结果", outputImage);
//    try {
//        // 放置可能引发异常的代码
//        imshow("检测结果", outputImage);
//    }
//    catch (const cv::Exception& e) {
//        cerr << "OpenCV 错误: " << e.what() << endl;
//    }
//
//}
//
//int main()
//{
//    // 读取图像
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/3333.jpg");
//    if (image.empty())
//    {
//        cerr << "无法读取图像" << endl;
//        return -1;
//    }
// 
//
//    // 创建显示窗口
//    namedWindow("检测结果", WINDOW_AUTOSIZE);
//    namedWindow("参数调节", WINDOW_AUTOSIZE);
//
//    // 初始化滑动条参数
//    int brightThresh = 230;
//    int minAreaBright = 40;
//    int darkBlockSize = 11;
//    int minAreaDark = 20;
//
//    // 创建滑动条并绑定到回调函数
//    createTrackbar("亮点阈值", "参数调节", &brightThresh, 255, onTrackbarChange, &image);
//    createTrackbar("亮点最小面积", "参数调节", &minAreaBright, 500, onTrackbarChange, &image);
//    createTrackbar("暗点BlockSize", "参数调节", &darkBlockSize, 25, onTrackbarChange, &image);
//    createTrackbar("暗点最小面积", "参数调节", &minAreaDark, 500, onTrackbarChange, &image);
//
//    // 手动调用一次回调函数，显示初始结果
//    onTrackbarChange(0, &image);
//
//    // 等待按键退出
//    waitKey(0);
//    return 0;
//}



// 增加原图显示功能，做对比

//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//int main()
//{
//    // 读取图像
//    Mat image = imread("C:/Users/Administrator/Desktop/calibration/111.jpg");
//    if (image.empty())
//    {
//        cerr << "无法读取图像" << endl;
//        return -1;
//    }
//
//    // 创建原图的副本
//    Mat originalImage = image.clone();
//
//    // 显示原图
//    imshow("原图", originalImage);
//
//    // 转换为灰度图像
//    Mat gray;
//    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
//
//    // ---------- 检测最亮点轮廓 --------------
//    // 应用阈值来检测最亮的点
//    Mat binaryBright;
//    threshold(gray, binaryBright, 230, 255, cv::THRESH_BINARY); // 亮点阈值为230
//
//    vector<std::vector<Point>> contoursBright;
//    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersBright; // 存储亮点的重心
//    int countBright = 0; // 用于连续编号
//
//    // 绘制亮点轮廓和计算重心
//    for (size_t i = 0; i < contoursBright.size(); ++i)
//    {
//        if (contourArea(contoursBright[i]) < 40) continue; // 过滤小轮廓
//
//        Moments m = moments(contoursBright[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersBright.push_back(center); // 存储亮点重心
//
//        // 绘制亮点轮廓
//        drawContours(image, contoursBright, static_cast<int>(i), Scalar(0, 255, 0), 2);
//        circle(image, center, 5, Scalar(255, 0, 0), -1); // 蓝色圈出亮点重心
//
//        // 标记编号
//        countBright++;
//        string text = "B" + to_string(countBright); // 使用B表示亮点
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
//    }
//
//    // ---------- 使用自适应阈值检测最暗点轮廓 --------------
//    // 自适应阈值来处理不同光照条件下的暗点检测
//    Mat binaryDark;
//    adaptiveThreshold(gray, binaryDark, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 9, 3); // 自适应阈值
//
//    vector<std::vector<Point>> contoursDark;
//    findContours(binaryDark, contoursDark, RETR_LIST, CHAIN_APPROX_SIMPLE);
//
//    vector<Point> centersDark; // 存储暗点的重心
//    int countDark = 0; // 用于连续编号
//
//    // 绘制暗点轮廓和计算重心
//    for (size_t i = 0; i < contoursDark.size(); ++i)
//    {
//        if (contourArea(contoursDark[i]) < 20) continue; // 过滤小轮廓
//
//        Moments m = moments(contoursDark[i]);
//        Point center(m.m10 / m.m00, m.m01 / m.m00);
//        centersDark.push_back(center); // 存储暗点重心
//
//        // 绘制暗点轮廓
//        drawContours(image, contoursDark, static_cast<int>(i), Scalar(255, 0, 0), 2);
//        circle(image, center, 5, Scalar(0, 0, 255), -1); // 红色圈出暗点重心
//
//        // 标记编号
//        countDark++;
//        string text = "D" + to_string(countDark); // 使用D表示暗点
//        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);
//    }
//
//    // 输出亮点重心坐标
//    cout << "亮点重心坐标: " << endl;
//    for (size_t i = 0; i < centersBright.size(); ++i)
//    {
//        cout << "亮点 " << i + 1 << " 的重心: (" << centersBright[i].x << ", " << centersBright[i].y << ")" << endl;
//    }
//
//    // 输出暗点重心坐标
//    cout << "暗点重心坐标: " << endl;
//    for (size_t i = 0; i < centersDark.size(); ++i)
//    {
//        cout << "暗点 " << i + 1 << " 的重心: (" << centersDark[i].x << ", " << centersDark[i].y << ")" << endl;
//    }
//
//    // 显示结果
//    imwrite("亮点和暗点轮廓.jpg", image);
//
//    // 创建一个足够大的画布来容纳两张图片
//    Mat combined;
//    hconcat(originalImage, image, combined);
//
//    imwrite("原图与处理后对比.jpg", combined);
//
//    // 显示原图和处理后的图像
//    imshow("原图 | 处理后的图像", combined);
//
//
//    waitKey(0);
//    return 0;
//}


// 增加凸包检测

#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace cv;

int main()
{
    // 读取图像
    Mat image = imread("C:/Users/Administrator/Desktop/calibration/111.jpg");
    if (image.empty())
    {
        cerr << "无法读取图像" << endl;
        return -1;
    }

    // 创建原图的副本
    Mat originalImage = image.clone();

    // 显示原图
    imshow("原图", originalImage);

    // 转换为灰度图像
    Mat gray;
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // ---------- 检测最亮点轮廓 --------------
    // 应用阈值来检测最亮的点
    Mat binaryBright;
    threshold(gray, binaryBright, 230, 255, cv::THRESH_BINARY); // 亮点阈值为230

    vector<vector<Point>> contoursBright;
    findContours(binaryBright, contoursBright, RETR_LIST, CHAIN_APPROX_SIMPLE);

    vector<Point> centersBright; // 存储亮点的重心
    int countBright = 0; // 用于连续编号

    // 绘制亮点轮廓和计算重心
    for (size_t i = 0; i < contoursBright.size(); ++i)
    {
        if (contourArea(contoursBright[i]) < 40) continue; // 过滤小轮廓

        Moments m = moments(contoursBright[i]);
        Point center(m.m10 / m.m00, m.m01 / m.m00);
        centersBright.push_back(center); // 存储亮点重心

        // 绘制亮点轮廓
        drawContours(image, contoursBright, static_cast<int>(i), Scalar(0, 255, 0), 2);
        circle(image, center, 5, Scalar(255, 0, 0), -1); // 蓝色圈出亮点重心

        // 标记编号
        countBright++;
        string text = "B" + to_string(countBright); // 使用B表示亮点
        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 1);
    }

    // ---------- 使用自适应阈值检测最暗点轮廓并计算凸包 --------------
    // 自适应阈值来处理不同光照条件下的暗点检测
    Mat binaryDark;
    adaptiveThreshold(gray, binaryDark, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 9, 3); // 自适应阈值

    vector<vector<Point>> contoursDark;
    findContours(binaryDark, contoursDark, RETR_LIST, CHAIN_APPROX_SIMPLE);

    vector<Point> centersDark; // 存储暗点的重心
    int countDark = 0; // 用于连续编号

    // 绘制暗点轮廓、计算重心和凸包
    for (size_t i = 0; i < contoursDark.size(); ++i)
    {
        if (contourArea(contoursDark[i]) < 20) continue; // 过滤小轮廓

        Moments m = moments(contoursDark[i]);
        Point center(m.m10 / m.m00, m.m01 / m.m00);
        centersDark.push_back(center); // 存储暗点重心

        // 绘制暗点轮廓
        drawContours(image, contoursDark, static_cast<int>(i), Scalar(255, 0, 0), 2);
        circle(image, center, 5, Scalar(0, 0, 255), -1); // 红色圈出暗点重心

        // 标记编号
        countDark++;
        string text = "D" + to_string(countDark); // 使用D表示暗点
        putText(image, text, center, FONT_HERSHEY_SIMPLEX, 0.5, Scalar(255, 0, 0), 1);

        // 计算暗点的凸包
        vector<Point> hull;
        convexHull(contoursDark[i], hull);

        // 绘制凸包轮廓
        drawContours(image, vector<vector<Point>>{hull}, -1, Scalar(0, 255, 255), 2); // 黄色显示凸包

        // 获取凸包的顶点数并标注
        int vertexCount = hull.size();
        putText(image, "V" + to_string(vertexCount), center + Point(10, 10), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 255), 1);
    }

    // 输出亮点重心坐标
    cout << "亮点重心坐标: " << endl;
    for (size_t i = 0; i < centersBright.size(); ++i)
    {
        cout << "亮点 " << i + 1 << " 的重心: (" << centersBright[i].x << ", " << centersBright[i].y << ")" << endl;
    }

    // 输出暗点重心坐标
    cout << "暗点重心坐标: " << endl;
    for (size_t i = 0; i < centersDark.size(); ++i)
    {
        cout << "暗点 " << i + 1 << " 的重心: (" << centersDark[i].x << ", " << centersDark[i].y << ")" << endl;
    }

    // 保存结果
    imwrite("亮点和暗点轮廓和凸包.jpg", image);

    // 创建一个足够大的画布来容纳两张图片
    Mat combined;
    hconcat(originalImage, image, combined);

    imwrite("原图与处理后对比.jpg", combined);

    // 显示原图和处理后的图像
    imshow("原图 | 处理后的图像", combined);

    waitKey(0);
    return 0;
}
