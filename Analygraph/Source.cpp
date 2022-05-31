#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int true_analygraph(string l, string r)
{
	//create a new image which consists of 
	//3 channels 
	//image depth of 8 bits 
	//800 x 600 of resolution (800 wide and 600 high)
	//each pixels initialized to the value of (100, 250, 30) for Blue, Green and Red planes respectively.
	Mat image = imread("D:/Zeta/mars_stereo_left.jpg");
	Mat imageR = imread("D:/Zeta/mars_stereo_right.jpg");

	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}


	//namedWindow(windowName); // Create a window
	//Scalar intensity = outimage.at<uchar>(250, 250);
	//int x = outimage.at<Vec3b>(250, 250)[0];//getting the pixel values//
	//int y = outimage.at<Vec3b>(250, 250)[1];//getting the pixel values//
	//int z = outimage.at<Vec3b>(250, 250)[2];// getting the pixel values//
	//outimage.at<Vec3b>(250, 250)[0] = 0;
	//int m = outimage.at<Vec3b>(250, 250)[0];
	//cout << "Value of blue channel:" << m << endl;//showing the pixel values//
	//cout << "Value of green channel:" << y << endl;//showing the pixel values//
	//cout << "Value of red channel:" << z << endl;//showing the pixel values//

	int i = image.rows;
	int j = image.cols;
	Mat imageA = image;

	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			int redL = image.at<Vec3b>(x, y)[2];
			int greenL = image.at<Vec3b>(x, y)[1];
			int blueL = image.at<Vec3b>(x, y)[0];
			int redR = imageR.at<Vec3b>(x, y)[2];
			int greenR = imageR.at<Vec3b>(x, y)[1];
			int blueR = imageR.at<Vec3b>(x, y)[0];
			int redA = 0.299 * redL + 0.587 * greenL + 0.114 * blueL;
			int greenA = 0.299 * redR + 0.587 * greenR + 0.114 * blueR;
			int blueA = 0.299 * redR + 0.587 * greenR + 0.114 * blueR;

			imageA.at<Vec3b>(x, y)[2] = redA;
			imageA.at<Vec3b>(x, y)[1] = 0;
			imageA.at<Vec3b>(x, y)[0] = blueA;
		}
	}

	imshow("i", imageA);
	
	
	
	
	
	//Mat imageBrightness50;
	//image.convertTo(imageBrightness50, -1, 1, 50); //increase the brightness by 50

	//Mat imageBrightnessdec50;
	//image.convertTo(imageBrightnessdec50, -1, 1, 50); //decrease brightness by 50

	//Mat imgGray;
	//Mat imgBlur;
	//Mat imgCanny;
	//Mat imgDilate;
	//Mat imgErode;
	//String window50 = "Brightness increase by 50";

	//cvtColor(image, imgGray, COLOR_BGR2GRAY); //converts the image into a gray image ==> imgGray
	//GaussianBlur(image, imgBlur, Size(7,7), 5, 0); //blurs the image
	//Canny(imgBlur, imgCanny, 50, 150);

	//Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5)); //creates a kernel we can use for dilation, if we increase size, it will dilate more and vice versa
	//dilate(imgCanny, imgDilate, kernel);
	//erode(imgDilate, imgErode, kernel);
	//namedWindow(window50); //creates window for image increase bbrightness by 50

	//imshow(windowName, image); // Show our image inside the created window.
	//imshow(window50, imageBrightness50);
	//imshow("Image Gray", imgGray);
	//imshow("Blur", imgBlur);
	//imshow("Canny", imgCanny); // Canny is used for edge detection, and often before it, you blur the image
	//imshow("Dilation", imgDilate); //diilate the thickness of the edge detection
	//imshow("Erode", imgErode); //decrease the thickeness of edge detection


	waitKey(0); // Wait for any keystroke in the window




}

int gray_analygraph(string l, string r) {
	Mat image = imread("D:/Zeta/mars_stereo_left.jpg");
	Mat imageR = imread("D:/Zeta/mars_stereo_right.jpg");

	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	int i = image.rows;
	int j = image.cols;
	Mat imageA = image;

	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			int redL = image.at<Vec3b>(x, y)[2];
			int greenL = image.at<Vec3b>(x, y)[1];
			int blueL = image.at<Vec3b>(x, y)[0];
			int redR = imageR.at<Vec3b>(x, y)[2];
			int greenR = imageR.at<Vec3b>(x, y)[1];
			int blueR = imageR.at<Vec3b>(x, y)[0];
			int redA = 0.299 * redL + 0.587 * greenL + 0.114 * blueL;
			int greenA = 0.299 * redR + 0.587 * greenR + 0.114 * blueR;
			int blueA = 0.299 * redR + 0.587 * greenR + 0.114 * blueR;
			imageA.at<Vec3b>(x, y)[2] = redA;
			imageA.at<Vec3b>(x, y)[1] = greenA;
			imageA.at<Vec3b>(x, y)[0] = blueA;
		}
	}

	imshow("i", imageA);
	waitKey(0);
}

int color_analygraph(string l, string r) {

	Mat image = imread("D:/Zeta/mars_stereo_left.jpg");
	Mat imageR = imread("D:/Zeta/mars_stereo_right.jpg");

	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}

	int i = image.rows;
	int j = image.cols;
	Mat imageA = image;

	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			int redL = image.at<Vec3b>(x, y)[2];
			int greenL = image.at<Vec3b>(x, y)[1];
			int blueL = image.at<Vec3b>(x, y)[0];
			int redR = imageR.at<Vec3b>(x, y)[2];
			int greenR = imageR.at<Vec3b>(x, y)[1];
			int blueR = imageR.at<Vec3b>(x, y)[0];

			imageA.at<Vec3b>(x, y)[2] = redL;
			imageA.at<Vec3b>(x, y)[1] = greenR;
			imageA.at<Vec3b>(x, y)[0] = blueR;
		}
	}

	imshow("i", imageA);
	cout << "Press enter to go back to menu" << endl;
	waitKey(0); 
}


int half_analygraph(string l, string r) {
	Mat image = imread("D:/Zeta/mars_stereo_left.jpg");
	Mat imageR = imread("D:/Zeta/mars_stereo_right.jpg");
	 

	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	int i = image.rows;
	int j = image.cols;
	Mat imageA = image;

	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			int redL = image.at<Vec3b>(x, y)[2];
			int greenL = image.at<Vec3b>(x, y)[1];
			int blueL = image.at<Vec3b>(x, y)[0];
			int redR = imageR.at<Vec3b>(x, y)[2];
			int greenR = imageR.at<Vec3b>(x, y)[1];
			int blueR = imageR.at<Vec3b>(x, y)[0];
			int redA = 0.299 * redL + 0.587 * greenL + 0.114 * blueL;
			int greenA = 0.299 * redR + 0.587 * greenR + 0.114 * blueR;
			int blueA = 0.299 * redR + 0.587 * greenR + 0.114 * blueR;
			imageA.at<Vec3b>(x, y)[2] = redA;
			imageA.at<Vec3b>(x, y)[1] = greenR;
			imageA.at<Vec3b>(x, y)[0] = blueR;
		}
	}

	imshow("i", imageA);
	waitKey(0);
}


int tv_analygraph(string l, string r) {
	Mat image = imread("D:/Zeta/mars_stereo_left.jpg");
	Mat imageR = imread("D:/Zeta/mars_stereo_right.jpg");


	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	int i = image.rows;
	int j = image.cols;
	Mat imageA = image;

	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			int redL = image.at<Vec3b>(x, y)[2];
			int greenL = image.at<Vec3b>(x, y)[1];
			int blueL = image.at<Vec3b>(x, y)[0];
			int redR = imageR.at<Vec3b>(x, y)[2];
			int greenR = imageR.at<Vec3b>(x, y)[1];
			int blueR = imageR.at<Vec3b>(x, y)[0];
			int redA = 0.7 * greenL + 0.3 * blueL;
			imageA.at<Vec3b>(x, y)[2] = redA;
			imageA.at<Vec3b>(x, y)[1] = greenR;
			imageA.at<Vec3b>(x, y)[0] = blueR;
		}
	}

	imshow("i", imageA);
	waitKey(0);
}


int dubois_analygraph(string l, string r) {
	Mat image = imread("D:/Zeta/mars_stereo_left.jpg");
	Mat imageR = imread("D:/Zeta/mars_stereo_right.jpg");


	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	int i = image.rows;
	int j = image.cols;
	Mat imageA = image;

	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			int redL = image.at<Vec3b>(x, y)[2];
			int greenL = image.at<Vec3b>(x, y)[1];
			int blueL = image.at<Vec3b>(x, y)[0];
			int redR = imageR.at<Vec3b>(x, y)[2];
			int greenR = imageR.at<Vec3b>(x, y)[1];
			int blueR = imageR.at<Vec3b>(x, y)[0];
			int redA = (0.437 * redL + 0.449 * greenL + 0.164 * blueL) + (((-0.011) * redR) + ((-0.011) * greenR) + (( - 0.007) * blueR));
			int greenA = ((-0.062) * redL + (-0.062) * greenL + (-0.024) * blueL) + (0.377 * redR + 0.761 * greenR + 0.009 * blueR);
			int blueA = ((-0.048) * redL + (-0.05) * greenL + (-0.017) * blueL) + ((-0.026) * redR + (-0.093) * greenR + (1.234) * blueR);
			imageA.at<Vec3b>(x, y)[2] = redA;
			imageA.at<Vec3b>(x, y)[1] = greenA;
			imageA.at<Vec3b>(x, y)[0] = blueA;
		}
	}

	imshow("i", imageA);
	waitKey(0);
}


int roscolux_analygraph(string l, string r) {
	Mat image = imread("D:/Zeta/mars_stereo_left.jpg");
	Mat imageR = imread("D:/Zeta/mars_stereo_right.jpg");


	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return -1;
	}
	int i = image.rows;
	int j = image.cols;
	Mat imageA = image;

	for (int x = 0; x < i; x++) {
		for (int y = 0; y < j; y++) {
			int redL = image.at<Vec3b>(x, y)[2];
			int greenL = image.at<Vec3b>(x, y)[1];
			int blueL = image.at<Vec3b>(x, y)[0];
			int redR = imageR.at<Vec3b>(x, y)[2];
			int greenR = imageR.at<Vec3b>(x, y)[1];
			int blueR = imageR.at<Vec3b>(x, y)[0];
			int redA = (0.3185 * redL + 0.0769 * greenL + 0.0109 * blueL) + (0.0174 * redR + 0.0484 * greenR + 0.1402 * blueR);
			int greenA = (0.1501 * redL + 0.0767 * greenL + 0.0056 * blueL) + (0.0184 * redR + 0.1807 * greenR + 0.0458 * blueR);
			int blueA = (0.0007 * redL + 0.002 * greenL + 0.0156 * blueL) + (0.0286 * redR + 0.0991 * greenR + 0.7662 * blueR);
			imageA.at<Vec3b>(x, y)[2] = redA;
			imageA.at<Vec3b>(x, y)[1] = greenA;
			imageA.at<Vec3b>(x, y)[0] = blueA;
		}
	}

	imshow("i", imageA);
	waitKey(0);
}




int main()
{
	restart:
	char ch;
	int num;
	string stereo_l, stereo_r;
	cout << "Please input path of left stereo image: ";
	std::cin >> stereo_l;
	cout << "Please input path of right stereo image: ";
	std::cin >> stereo_r;


	do
	{
		end:
		system("cls");
		cout << "\n\n\n\tAnalygraph Generation Functions: ";
		cout << "\n\n\t01. True Analygraph";
		cout << "\n\n\t02. Gray Analygraph";
		cout << "\n\n\t03. Color Analygraph";
		cout << "\n\n\t04. Half-Colored Analygraph";
		cout << "\n\n\t05. 3DTV-Optimized Analgraph";
		cout << "\n\n\t06. DuBois Analygraph";
		cout << "\n\n\t07. Roscolux Analgraph";
		cout << "\n\n\t08. Select a different pair of stereo images";
		cout << "\n\n\t09. EXIT";
		cout << "\n\n\tSelect Your Option (1-8) ";
		std::cin >> ch;
		system("cls");
		switch (ch)
		{
		case '1':
			cout << "True Analygraph: \n";
			true_analygraph(stereo_l, stereo_r);
			break;
		case '2':
			cout << "Gray Analygraph: \n";
			gray_analygraph(stereo_l, stereo_r);
			break;
		case '3':
			cout << "Color Analygraph: \n";
			color_analygraph(stereo_l, stereo_r);
			break;
		case '4':
			cout << "Half Analygraph: \n";
			half_analygraph(stereo_l, stereo_r);
			break;
		case '5':
			cout << "3DTV-Optimized Analygraph: \n";
			tv_analygraph(stereo_l, stereo_r);
			break;
		case '6':
			cout << "DuBois Analygraph: \n";
			dubois_analygraph(stereo_l, stereo_r);
			break;
		case '7':
			cout << "Roscolux Analygraph: \n";
			roscolux_analygraph(stereo_l, stereo_r);
			break;
		case '8':
			goto restart;
			break;
		case '9':
			cout << "\n\n\tThanks for using analygraph generation function";
			break;
		default:cout << "\a";
		}
		cin.ignore();
		cin.get();
	} while (ch != '8');
	return 0;
}