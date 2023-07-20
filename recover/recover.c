#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check if command-line argument is correct
    if (argc != 2)
    {
        printf("Correct usage: ./recover IMAGE\n");
        return 1;
    }

    //open memory card
    FILE *input_file = fopen(argv[1], "r");

    //check if input_file is valid
    if (input_file == NULL)
    {
        printf("File cannot be opened\n");
        return 2;
    }

    //store 512bytes blockes in an array
    unsigned char buffer[512];

    //count images already generated
    int count_img = 0;

    //file pointer for recovered images
    FILE *output_file = NULL;

    //allocate memory for filename
    char *filename = malloc(8 * sizeof(char));


    //read blocks of 512bytes
    while (fread(buffer, sizeof(char), 512, input_file))
    {
        //if first 4 bytes correspond to start of JPEG file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //close output file to begin with a new one (if it's not the first one)
            if (count_img > 0)
            {
                fclose(output_file);
            }

            //write the JPEG filenames
            sprintf(filename, "%03i.jpg", count_img);

            //open output_file for writing
            output_file = fopen(filename, "w");

            //keep counter of images already created
            count_img++;
        }

        //check if output has been used for valid input
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    //close all files
    fclose(input_file);
    fclose(output_file);

    //free previously allocated memory
    free(filename);
}