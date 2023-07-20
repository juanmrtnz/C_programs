#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //for every pixel (1 loop height, 1 nested loop width)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //get average of the 3 colours
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.00);

            //change each of 3 colours to average
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //for every pixel (1 loop height, 1 nested loop width)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //calculate sepia formula
            int sepiaBlue = round((image[i][j].rgbtRed * .272) + (image[i][j].rgbtGreen * .534) + (image[i][j].rgbtBlue * .131));
            int sepiaGreen = round((image[i][j].rgbtRed * .349) + (image[i][j].rgbtGreen * .686) + (image[i][j].rgbtBlue * .168));
            int sepiaRed = round((image[i][j].rgbtRed * .393) + (image[i][j].rgbtGreen * .769) + (image[i][j].rgbtBlue * .189));


            //change each of 3 colours to sepia
            image[i][j].rgbtBlue = (sepiaBlue < 255) ? sepiaBlue : 255;
            image[i][j].rgbtGreen = (sepiaGreen < 255) ? sepiaGreen : 255;
            image[i][j].rgbtRed = (sepiaRed < 255) ? sepiaRed : 255;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //make temporal copy of values
            int tempBlue = image[i][j].rgbtBlue;
            int tempGreen = image[i][j].rgbtGreen;
            int tempRed = image[i][j].rgbtRed;

            //change values of first half to those of second half
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;

            //change values to second half to those of the temporal copy
            image[i][width - j - 1].rgbtBlue = tempBlue;
            image[i][width - j - 1].rgbtGreen = tempGreen;
            image[i][width - j - 1].rgbtRed = tempRed;
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //create a copy of the image
    RGBTRIPLE imgcopy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            imgcopy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int Red, Blue, Green;
            Red = Blue = Green = 0;
            float counter = 0.00;

            //get neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //check if neighbouring pixel is valid
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    //get image value
                    Blue += image[currentX][currentY].rgbtBlue;
                    Green += image[currentX][currentY].rgbtGreen;
                    Red += image[currentX][currentY].rgbtRed;

                    counter++;
                }

                //calculate average of neighbouring pixels
                imgcopy[i][j].rgbtBlue = round(Blue / counter);
                imgcopy[i][j].rgbtGreen = round(Green / counter);
                imgcopy[i][j].rgbtRed = round(Red / counter);
            }
        }
    }

    //copy new pixels into original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = imgcopy[i][j].rgbtBlue;
            image[i][j].rgbtGreen = imgcopy[i][j].rgbtGreen;
            image[i][j].rgbtRed = imgcopy[i][j].rgbtRed;
        }
    }
    return;
}
