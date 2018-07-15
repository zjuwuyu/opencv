#include <opencv2/opencv.hpp>
#include <iostream>
#include <math.h>

using namespace cv;

int main(int arv, char ** argv)
{
	Mat src = imread("C:\\Users\\wuyu\\Desktop\\3.png");
	Mat dst;
	
	if (src.empty()) {
		printf("src not found\n");
		return -1;
	}
	src.copyTo(dst);

	namedWindow("output", CV_WINDOW_AUTOSIZE);
	imshow("output", src);

	for (int row = 1; row < src.rows - 1; row++) {
		const uchar *current = src.ptr<uchar>(row);
		const uchar *prev = src.ptr<uchar>(row - 1);
		const uchar *next = src.ptr<uchar>(row + 1);
		uchar *output = dst.ptr<uchar>(row);
		const int nchannel = src.channels();
		for (int col = nchannel; col < (src.cols-1) * nchannel; col++) {
			*output = saturate_cast<uchar>(5 * current[col] - (prev[col] + next[col] + current[col - nchannel] + current[col + nchannel]));
		}

	}

	namedWindow("dst", CV_WINDOW_AUTOSIZE);
	imshow("dst", dst);

	imwrite("C:\\Users\\wuyu\\Desktop\\3_new.png", dst);

	waitKey(0);
	return 0;
}