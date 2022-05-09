#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int avg;
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            avg = round ((image[h][w].rgbtRed + image[h][w].rgbtGreen + image[h][w].rgbtBlue) / 3.0);
            image[h][w].rgbtRed = avg;
            image[h][w].rgbtGreen = avg;
            image[h][w].rgbtBlue = avg;
        }
    }
    return;
}


// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed;
    int sepiaGreen;
    int sepiaBlue;

   for (int h = 0; h < height; h++)
   {
       for (int w = 0; w < width; w++)
       {
          sepiaRed = round ((0.393 * image[h][w].rgbtRed) + (0.769 * image[h][w].rgbtGreen) + (0.189 * image[h][w].rgbtBlue) );
          sepiaGreen = round ((0.349 * image[h][w].rgbtRed) + (0.686 * image[h][w].rgbtGreen) + (0.168 * image[h][w].rgbtBlue) );
          sepiaBlue = round ((0.272 * image[h][w].rgbtRed) + (0.534 * image[h][w].rgbtGreen) + (0.131 * image[h][w].rgbtBlue) );

          image[h][w].rgbtRed = sepiaRed;
          image[h][w].rgbtGreen = sepiaGreen;
          image[h][w].rgbtBlue = sepiaBlue;

          if (sepiaRed > 255)
          {
              image[h][w].rgbtRed = 255;
          }
          if( sepiaGreen > 255)
          {
              image[h][w].rgbtGreen = 255;
          }
          if(sepiaBlue > 255)
          {
              image[h][w].rgbtBlue = 255;
          }
       }
   }

    return;
}



// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width / 2; w++)
        {
            RGBTRIPLE temp = image[h][w];
            image[h][w] = image[h][width-w-1];
            image[h][width-w-1] = temp;
        }
    }
    return;
}



// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Declare new image as the copy of the image
    RGBTRIPLE copy[height][width];

    // For each pixel in copyimage(h,w) do:


    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int avg=0;
            float totalRed = 0.0;
            float totalGreen = 0.0;
            float totalBlue = 0.0;

            for(int i = h-1; i <= h+1; i++ )
            {

                for(int j = w-1; j <= w+1; j++)
                {

                 if(i >= 0 && i < height && j >=0 && j < width)
                 {
                     totalRed+=image[i][j].rgbtRed;
                     totalGreen+=image[i][j].rgbtGreen;
                     totalBlue+=image[i][j].rgbtBlue;
                     avg++;
                 }

                }
            }

            copy[h][w].rgbtRed = round(totalRed/avg);
            copy[h][w].rgbtGreen = round(totalGreen/avg);
            copy[h][w].rgbtBlue = round(totalBlue/avg);
        }
    }


    for(int h = 0; h < height; h++){
        for(int w=0; w < width; w++){
            image[h][w] = copy[h][w];
        }
    }
    return;
}

