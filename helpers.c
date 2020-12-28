#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // iterate through each row (vertically)
    {
        for (int j = 0; j < width; j++) // WITHIN each row (the outer loop), iterate through each column (horizontally)
        {
            int average = round(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3; // average of 3 colors
            image[i][j].rgbtRed = average; // setting the value for red to the average
            image[i][j].rgbtGreen = average; // setting the value for green to the average
            image[i][j].rgbtBlue = average; // setting the value for blue to the average
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // iterate through each row (vertically)
    {
        for (int j = 0; j < width; j++) // WITHIN each row (the outer loop), iterate through each column (horizontally)
        {
            int red = round(image[i][j].rgbtRed * .393 + image[i][j].rgbtGreen * .769 + image[i][j].rgbtBlue * .189);
            if (red > 255) // this in case pluggin in the formula (above) makes the value over 255.
            {
                red = 255;
            }
            int green = round(image[i][j].rgbtRed * .349 + image[i][j].rgbtGreen * .686 + image[i][j].rgbtBlue * .168);
            if (green > 255)
            {
                green = 255;
            }
            int blue = round(image[i][j].rgbtRed * .272 + image[i][j].rgbtGreen * .534 + image[i][j].rgbtBlue * .131);
            if (blue > 255)
            {
                blue = 255;
            }
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // iterate through each row (vertically)
    {
        for (int j = 0; j < (width / 2); j++) // So it's "width / 2" because we're going to replace from the outsides
                                            // in to the middle
        {
            // OK.. so the below is necessary because the memory of where the pixel needs to go to
            // will be erased. So we have to store its value in a temporary variable (a la the lecture).
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Below replaces the inside (left side) pixel with the outside (right) one
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            // And here we use our temp variables to fill the outside (right) pixels back in with the values that
            // WERE in the inside (left) pixel
            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtBlue = blue;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Not finished! Still need to figure out blur