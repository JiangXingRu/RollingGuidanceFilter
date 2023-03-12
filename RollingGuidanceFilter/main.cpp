#include "RollingGuidanceFilter.h"

int main(int argc, char *argv[])
{
	string name = "./imgs/image.png";

	cv::Mat img = cv::imread(name);

	if(img.empty()){
		printf("No such file.\n");
		getchar();
		exit(1);
	}

	clock_t startTime = clock();
	cv::Mat res = RollingGuidanceFilter::filter(img,3,25.5,4);
	clock_t endTime = clock();
	printf("Elapsed Time: %d ms\n", endTime - startTime);

	cv::imshow("img",img);
	cv::imshow("res",res);
	cv::imwrite("./imgs/res.png", res);
	cv::waitKey();

	return 0;
}