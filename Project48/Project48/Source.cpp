#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <pthread>

using namespace cv;
using namespace std;
void convert(Mat frame)
{
	Mat graymat;
	cvCvtColor(frame, graymat, CV_BGR2GRAY);
	Mat f_mat;
	graymat.convertTo(f_mat, CV_32F);
	imshow("MyVideoGS", graymat);
	imshow("Video", frame);
}
int main(int argc, char* argv[])
{
	VideoCapture vid("EdsProposal.mp4");
	if (!vid.isOpened())
	{
		cout << "File not available, please check the path." << endl;
		return -1;
	}
	double fps = vid.get(CV_CAP_PROP_FPS);
	cout << "Frame per second : " << fps << endl;
	namedWindow("Video", CV_WINDOW_AUTOSIZE);
	pthread_t thread;
	while (1)
	{
		Mat frame;
		bool bSuccess = vid.read(frame);
		if (!bSuccess)
		{
			cout << "Done reading frames " << endl;
			break;
		}
		pthread_create(&thread, NULL, convert, (void*)frame);
		if (waitKey(30) == 27)
		{
			cout << "esc key is pressed by user" << endl;
			break;
		}
		pthread_join(thread, NULL);
	}
	return 0;

}
