#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{

    // Check for command line arguments
    if(argc != 2)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }

    // Open card file
    FILE *card = fopen(argv[1], "r");
    if (!card)
    {
        return 1;
    }


    //Iterate through memory card
    BYTE buffer[512];
    int counter = 0;
    FILE *img = NULL;
    char jpegname[8];
    int jpeg_found = 0;


    while(fread(buffer, sizeof(BYTE), 512, card) == 512)
    {
        // If start of new jpeg
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
           //If first jpeg
            if (counter == 0)
           {
                jpeg_found = 1;
                sprintf(jpegname, "%03i.jpg", counter);
                img = fopen(jpegname, "w");
                fwrite(buffer, sizeof(BYTE) , 512, img);
                counter++;
            }


            //If other than fisrt
            else
            {
                fclose(img);
                sprintf(jpegname, "%03i.jpg", counter);
                img = fopen(jpegname, "w");
                fwrite(buffer, sizeof(BYTE) , 512, img);
                counter++;
            }



        }

        else if (jpeg_found == 1)                                                             // This code should run after the first jpeg is found
        {
            // If not a start of jpeg
            fwrite(buffer, sizeof(BYTE), 512, img);
        }


    }




    fclose(card);
    fclose(img);



}