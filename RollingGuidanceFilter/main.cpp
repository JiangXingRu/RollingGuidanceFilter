#include "RollingGuidanceFilter.h"

int main(int argc, char *argv[])
{
	string name = "./imgs/image.png";

	cv::Mat img = cv::imread(name);

	if(img.empty())
	{
		printf("No such file.\n");
		getchar();
		exit(1);
	}

	clock_t startTime = clock();
	float sigma_s = 3.f;
	float sigma_r = 25.5f;
	int iteration = 4;
	cv::Mat res = RollingGuidanceFilter::filter(img, sigma_s, sigma_r, iteration);
	clock_t endTime = clock();
	printf("Elapsed Time: %d ms\n", endTime - startTime);

	cv::imshow("img",img);
	cv::imshow("res",res);
	cv::imwrite("./imgs/res.png", res);

	cv::waitKey();

	return 0;
}