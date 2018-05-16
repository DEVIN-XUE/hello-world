#include<iostream>
#include <math.h>
using namespace std;

#define GAUSSIAN_CUT_OFF 0.005f


static float gaussian(float x, float sigma) 
{
	return (float) exp(-(x * x) / (2.0f * sigma * sigma));
}



int main() {
		float kernelRadius = 2.0;
		int kernelWidth = 16;

		float *kernel;
		float *diffKernel;
		int kwidth;

		int width, height;

		int initX;
		int maxX;
		int initY;
		int maxY;

		int x, y;
		int i;
		int flag;

		// width = rawImg->width;
  //       height = rawImg->height;

		kernel = new float[kernelWidth];
		diffKernel = new float[kernelWidth];
		// if(!kernel || !diffKernel)
			// goto error_exit;

		/* initialise the Gaussian kernel */
		for (kwidth = 0; kwidth < kernelWidth; kwidth++) 
		{
			float g1, g2, g3;
			g1 = gaussian((float) kwidth, kernelRadius);
			if (g1 <= GAUSSIAN_CUT_OFF && kwidth >= 2) 
				break;
			g2 = gaussian(kwidth - 0.5f, kernelRadius);
			g3 = gaussian(kwidth + 0.5f, kernelRadius);
			kernel[kwidth] = (g1 + g2 + g3) / 3.0f / (2.0f * (float) 3.14 * kernelRadius * kernelRadius);
			diffKernel[kwidth] = g3 - g2;
		}

		cout << "KERNEL: " << endl;
		for (int i = 0; i < kernelWidth; i++) {
			cout << kernel[i] << " ";
		}
		cout << endl;

		cout << "DIFF KERNEL: " << endl;
		for (int i = 0; i < kernelWidth; i++) {
			cout << diffKernel[i] << " ";
		}
		cout << endl;
		return 0;

}