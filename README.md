# IRdetection
IR image detection
visual studio 2022 and OpenCV 4.8.0
用于识别红外图像上的特征点重心、特征点定位、特征点间距
centroids文件 用于检测重心
white文件 用于检测图像中被检测物轮廓
distance文件 用于最终检测各标记点距离，利用凸包顶点与直角顶点等，结合相机标定的校正矩阵与径向畸变参数
pictures中为项目检测图像，其中运行效果可以看到分别呈现颜色反转、二值化效果、图像学处理、与最终检测图、控制台输出距离，在运行distance时任意按键即可依次显示图像
