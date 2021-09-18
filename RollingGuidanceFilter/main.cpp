#include "RollingGuidanceFilter.h"

int main(int argc, char *argv[])
{
	String name = "./imgs/image.png";

	Mat img = imread(name);

	if(img.empty()){
		printf("No such file.\n");
		getchar();
		exit(1);
	}

	clock_t startTime = clock();
	Mat res = RollingGuidanceFilter::filter(img,3,25.5,4);
	clock_t endTime = clock();
	printf("Elapsed Time: %d ms\n", endTime - startTime);

	imshow("img",img);
	imshow("res",res);
	imwrite("./imgs/res.png", res);
	waitKey();

	return 0;
}