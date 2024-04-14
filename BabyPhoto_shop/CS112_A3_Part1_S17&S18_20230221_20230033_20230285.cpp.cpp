// FCAI _ Structured Programming _ 2024_Assignment3

// program name:CS112_A3_Part1_S17&18_20230221_20230285_20230033.cpp

//Program Description: This program creates some filters for images

// Last Modification Date:12/4/2023

// Author1 and ID and Group:Abdelrahaman yasser _ 20230221 _ B 

// Author2 and ID and Group:Ahmed mohamed _ 20230033 _ B

// Author3 and ID and Group:Fatma Hashim Mohammed _ 20230285 _ B

// Teaching Assistant: Ahmed lotfy S 17&18

// Who did what  Abdelrahaman yasser created 2,5,8,11 and 17 _Ahmed mohamed created 1,4,7,13 and 10_fatma hashim created 3,6,9,16 and 12

#include <iostream>
#include <string>
#include "Image_Class.h" // Assuming Image_Class.h contains the Image class definition
#include <cstdlib> // Needed for exit

using namespace std;
string filename;
//Function to save the edited photo or exit the program.
void savePhoto(Image& image) {
    string choice;
    while (true) {
        cout << "\nMenu 2:" << endl;
        cout << "A) Save image and apply more filters." << endl << endl;
        cout << "B) Save image with a new filename and apply more filters." << endl << endl;
        cout << "C) Save and Exit." << endl << endl;
        cout << "D) Save image with a new filename and Exit." << endl << endl;
        cout << "E) Save the current and load a new picture." << endl << endl;
        cout << "F) Save the current with a new filename and load a new picture." << endl << endl;
        cout << "G) Don't save the current and load a new picture." << endl << endl;
        cout << "H) Exit without saving." << endl << endl;
        cout << "Enter your choice: ";
        getline(cin, choice);
        if (choice == "A" || choice == "a") {
            // Save image with the same filename
            image.saveImage(filename);
            cout << "Image saved successfully." << endl;
            break; // Break out of the loop after saving
        }
        else if (choice == "B" || choice == "b") {
            // Prompt user to enter a new filename
            string newName;
            cout << "Enter the name of the file to save the photo: ";
            getline(cin, newName);
            string ext = newName.substr(newName.find_last_of(".") + 1);
            if (ext != "png" && ext != "jpg" && ext != "bmp" && ext != "tga") {
                cout << "Invalid extension. Supported extensions are .jpg, .png, .bmp, and .tga." << endl;
                continue;
            }
            // Save image with the new filename
            image.saveImage(newName);
            cout << "Image saved successfully as '" << newName << "'." << endl;
            break; // Break out of the loop after saving
        }
        else if (choice == "C" || choice == "c") {
            // Save image with the same filename and exit
            image.saveImage(filename);
            cout << "Image saved successfully." << endl;
            cout << "Exiting Program..." << endl;
            exit(0); // Exiting the program
        }
        else if (choice == "D" || choice == "d") {
            // Save image with a new filename and exit
            string newName;
            cout << "Enter the name of the file to save the photo: ";
            getline(cin, newName);
            string ext = newName.substr(newName.find_last_of(".") + 1);
            if (ext != "png" && ext != "jpg" && ext != "bmp" && ext != "tga") {
                cout << "Invalid extension. Supported extensions are .jpg, .png, .bmp, and .tga." << endl;
                continue;
            }
            // Save image with the new filename
            image.saveImage(newName);
            cout << "Image saved successfully as '" << newName << "'." << endl;
            cout << "Exiting Program..." << endl;
            exit(0);
        }
        else if (choice == "E" || choice == "e") {
            // Save the current image and load a new one
            image.saveImage(filename);
            cout << "Image saved successfully." << endl;
            // Load a new picture here
            cout << "Enter the name of the new image to load: ";
            getline(cin, filename);
            string ext = filename.substr(filename.find_last_of(".") + 1);
            if (ext != "png" && ext != "jpg" && ext != "bmp" && ext != "tga") {
                cout << "Invalid extension. Supported extensions are .jpg, .png, .bmp, and .tga." << endl;
                continue;
            }
            image = Image(filename);
            break;
        }
        else if (choice == "F" || choice == "f") {
            // Save the current with a new filename and load a new picture
            string newName;
            cout << "Enter the name of the file to save the photo: ";
            getline(cin, newName);
            string ext = newName.substr(newName.find_last_of(".") + 1);
            if (ext != "png" && ext != "jpg" && ext != "bmp" && ext != "tga") {
                cout << "Invalid extension. Supported extensions are .jpg, .png, .bmp, and .tga." << endl;
                continue;
            }
            // Save image with the new filename
            image.saveImage(newName);
            cout << "Image saved successfully as '" << newName << "'." << endl;
            // Load a new picture here
            cout << "Enter the name of the new image to load: ";
            getline(cin, filename);
            string ext1 = filename.substr(filename.find_last_of(".") + 1);
            if (ext1 != "png" && ext1 != "jpg" && ext != "bmp" && ext1 != "tga") {
                cout << "Invalid extension. Supported extensions are .jpg, .png, .bmp, and .tga." << endl;
                continue;
            }
            image = Image(filename);
            break;
        }
        else if (choice == "G" || choice == "g") {
            // Don't save the current image and load a new one
            // Load a new picture here
            cout << "Enter the name of the new image to load: ";
            getline(cin, filename);
            string ext = filename.substr(filename.find_last_of(".") + 1);
            if (ext != "png" && ext != "jpg" && ext != "bmp" && ext != "tga") {
                cout << "Invalid extension. Supported extensions are .jpg, .png, .bmp, and .tga." << endl;
                continue;
            }
            image = Image(filename);
            break;
        }
        else if (choice == "H" || choice == "h") {
            cout << "Exiting Program..." << endl;
            exit(0); // Exiting the program without saving
        }
        else {
            cout << "Invalid choice. Please enter the corresponding letter for the action you want to take." << endl;
        }
    }
}

//Grey Scale.
void GreyScale(Image& image) {

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            unsigned int avg = 0; // set average to calculate RGB of pixel
            for (int k = 0; k < image.channels; k++)
            {
                avg += image(i, j, k);
            }
            avg = avg / 3; // get average of pixel from 0 to 255 gray from black to white 
            for (int k = 0; k < 3; k++)
            {
                image(i, j, k) = avg; // update value of each pixel
            }

        }

    }
    savePhoto(image);
}

//Black and White. 
void ConvertToBlackAndWhite(Image& image) {
    // Get the width and height of the colored image
    int width = image.width;
    int height = image.height;

    // Create a new image object with the same width and height for the grayscale image
    Image grayscaleImage(width, height);

    // Iterate through each pixel in the colored image
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int avg = 0;
            // Get the red, green, and blue values for the current pixel
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }
            // Calculate the average of the color values to convert the image to grayscale
            int gray = avg / 3;

            // Apply the threshold to convert the image to black and white
            int pixelValue = (gray < 128) ? 0 : 255;

            // Set the color values for the current pixel in the grayscale image
            for (int k = 0; k < 3; ++k) {
                grayscaleImage(i, j, k) = pixelValue;
            }
        }
    }
    savePhoto(grayscaleImage);
}

//Invert Image.
void invertImage(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = 255 - image(i, j, k); // subtract 255 from every channel color to get the invert pixel  
            }
        }
    }
    savePhoto(image);
}

//Flip.
void flipImageHorizontall(Image& image)
{
    // first loop for height 
    for (int j = 0; j < image.height; ++j)
    {
        //  loop for flipping horizontally  swapping pixels symmetrically around the vertical axis
        for (int i = 0; i < image.width / 2; ++i)
        {
            for (int k = 0; k < 3; ++k)
            {
                int temp = image(i, j, k); // set temp to save the  current vaule temporarily.
                image(i, j, k) = image(image.width - 1 - i, j, k); // this work like horizontally mirrored
                image(image.width - 1 - i, j, k) = temp; // get back the swapped part  
            }
        }
    }
    savePhoto(image);
}
void flipImageVertical(Image& image)
{
    for (int i = 0; i < image.width; ++i)
    {
        //loop for the image and swapping pixels from top to bottom within each column
        for (int j = 0; j < image.height / 2; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                int temp = image(i, j, k);// set temp to save the  current vaule temporarily.
                image(i, j, k) = image(i, image.height - j - 1, k);// copied to the current pixel position  effectively flipping the pixel vertically.
                image(i, image.height - j - 1, k) = temp;// get back the swapped part
            }
        }
    }
    savePhoto(image);
}
void flipMenu(Image& image)
{
    int choice;

    do
    {
        cout << "Choose an option:" << endl;
        cout << "1. flip horizontall" << endl;
        cout << "2. flip vertical" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        if (choice == 1)
            flipImageHorizontall(image);
        else if (choice == 2)
            flipImageVertical(image);
        else if (choice != 3)
        {
            cout << "Invalid choice, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice != 3);

    cout << "Exiting program..." << endl;
}

//Rotation.
void rotate90Degree(Image& image)
{
    // set new photo with new dimensions swap height and width
    Image image2(image.height, image.width);

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                image2(image.height - j, i, k) = image(i, j, k);// This calculates the new height index for the pixel in image2 as clockwise
            }
        }
    }
    savePhoto(image2);
}
void rotate180Degree(Image& image)
{
    // set new photo with same dimensions
    Image image2(image.width, image.height);

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                //calculates the width and height position in the rotated image
                image2(image.width - i - 1, image.height - j - 1, k) = image(i, j, k);
            }
        }
    }
    savePhoto(image2);
}
void rotate270Degree(Image& image)
{
    // set new photo with new dimensions swap height and width
    Image image2(image.height, image.width);

    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                // This calculates the new widh index for the pixel in image2 as clockwise
                image2(j, image.width - i - 1, k) = image(i, j, k);
            }
        }
    }
    // Save the image with the specified name and extension
    savePhoto(image2);

}
void rotationMenu(Image& image)
{
    int choice;

    do
    {
        cout << "Choose an option:" << endl;
        cout << "1. Rotate 90 degrees" << endl;
        cout << "2. Rotate 180 degrees" << endl;
        cout << "3. Rotate 270 degrees" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;

        if (choice == 1)
            rotate90Degree(image);
        else if (choice == 2)
            rotate180Degree(image);
        else if (choice == 3)
            rotate270Degree(image);
        else if (choice != 4)
        {
            cout << "Invalid choice, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice != 4);

    cout << "Exiting program..." << endl;
}

//infraredImage.
void infraredImage(Image& image) {
    Image image2(image.width, image.height);
    // Iterate through each pixel in the original image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            // Set red channel to maximum value (255)
            image2(i, j, 0) = 255;
            // Calculate green channel as the difference between 255 and the blue channel value of the original image
            image2(i, j, 1) = 255 - image(i, j, 2);
            // Calculate blue channel as the difference between 255 and the green channel value of the original image
            image2(i, j, 2) = 255 - image(i, j, 1);
        }
    }
    savePhoto(image2);
}

//cropImage.
void cropImage(Image& image) {
    int x, y, w, h;
    // Prompt the user to enter the starting coordinates and dimensions of the cropped image
    cout << "Please enter the width you want to start cutting from: ";
    cin >> x;

    cout << "Please enter the height you want to start cutting from: ";
    cin >> y;

    cout << "Please enter the width of the cropped image: ";
    cin >> w;

    cout << "Please enter the height of the cropped image: ";
    cin >> h;
    // Validate the cropping dimensions
    if (x < 0 || y < 0 || w <= 0 || h <= 0 || x >= image.width || y >= image.height) {
        cerr << "Error: Invalid cropping dimensions." << endl;
        return;
    }

    if (x + w > image.width || y + h > image.height) {
        cerr << "Error: Cropping dimensions exceed image boundaries." << endl;
        return;
    }
    // Iterate through each pixel in the cropped image and copy pixels from the original image
    Image image2(w, h);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            for (int k = 0; k < 3; k++) {
                image2(i, j, k) = image(i + x, j + y, k);
            }
        }
    }
    savePhoto(image2);
}

//resizeImage.
void resizeImage(Image& image) {
    int newWidth, newHeight;
    // Prompt user to enter the new width and height of the image
    cout << "please Enter the new width of the image: ";
    cin >> newWidth;
    cout << "please Enter the new height of the image: ";
    cin >> newHeight;
    // Check if the provided dimensions are valid
    if (newWidth <= 0 || newHeight <= 0) {
        cerr << "Error: Invalid dimensions for resizing." << endl;
        return;
    }

    // Calculate ratio for resizing
    double widthRatio = double(newWidth) / image.width;
    double heightRatio = double(newHeight) / image.height;
    // Iterate through each pixel in the new image and calculate the corresponding pixel in the original image after resizing
    Image image2(newWidth, newHeight);
    for (int i = 0; i < newWidth; ++i) {
        for (int j = 0; j < newHeight; ++j) {
            for (int k = 0; k < 3; ++k) {
                // Interpolate pixel values using the calculated ratios
                image2(i, j, k) = image(i / widthRatio, j / heightRatio, k);
            }
        }
    }
    savePhoto(image2);
}

//Merge.
void merge(Image& image) {
    string fileName2;
    //cin.ignore();
    cout << "Please enter the colored second image name: ";
    getline(cin, fileName2);
    string ext = fileName2.substr(fileName2.find_last_of(".") + 1);
    if (ext != "png" && ext != "jpg" && ext != "bmp" && ext != "tga") {
        cout << "Invalid extension. Supported extensions are .jpg, .png, .bmp, and .tga. Exiting merge program...." << endl;
        return;
    }
    // Create an object of Image class with the given image name
    Image image2(fileName2);
    // get the max width and height to the resize process
    int max_width = max(image.width, image2.width);
    int max_height = max(image.height, image2.height);
    // to change Dimensions to new size , width photo1
    Image resizedImage1(max_width, max_height);
    for (int i = 0; i < max_width; i++) {
        for (int j = 0; j < max_height; j++) {
            // get the new x,y axis
            int  X = i * image.width / max_width;
            int  Y = j * image.height / max_height;
            for (int k = 0; k < 3; k++) {
                //Copy pixel values from the original image to the resized image
                resizedImage1(i, j, k) = image(X, Y, k);
            }
        }
    }

    // to change Dimensions to new size , width photo1
    Image resizedImage2(max_width, max_height);
    for (int i = 0; i < max_width; i++) {
        for (int j = 0; j < max_height; j++) {
            // get the new x,y axis
            int  X = i * image2.width / max_width;
            int  Y = j * image2.height / max_height;
            for (int k = 0; k < 3; k++) {
                //Copy pixel values from the original image to the resized image
                resizedImage2(i, j, k) = image2(X, Y, k);
            }
        }
    }
    //merge the 2 photos nwith new size
    Image merged(max_width, max_height);
    for (int i = 0; i < max_width; i++) {
        for (int j = 0; j < max_height; j++) {
            //calculate every color channel
            merged(i, j, 0) = (resizedImage1(i, j, 0) + resizedImage2(i, j, 0)) / 2;
            merged(i, j, 1) = (resizedImage1(i, j, 1) + resizedImage2(i, j, 1)) / 2;
            merged(i, j, 2) = (resizedImage1(i, j, 2) + resizedImage2(i, j, 2)) / 2;
        }
    }
    savePhoto(merged);
}

//filter 7 Darken part.
void f7Darken(Image& image) {
    // loop for every pixel
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {

            for (int k = 0; k < image.channels; k++)
            {
                // decrease the light for every pixel
                image(i, j, k) = image(i, j, k) * 0.5;
                if (image(i, j, k) < 0)
                {
                    image(i, j, k) = 0;
                }

            }

        }

    }
    savePhoto(image);
}

//filter 7 Lighten part.
void f7lighten(Image& image) {
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {
            int avg = 0; //set avg to save pixel
            for (int k = 0; k < image.channels; k++)
            {
                avg = image(i, j, k) * 1.5; // increase the light of photo
                if (avg > 255)
                {
                    avg = 255;
                }
                image(i, j, k) = avg;

            }


        }

    }
    savePhoto(image);
}

//dark and light menu.
void darken_and_lighten_menu(Image& image)
{
    int choice;

    do
    {
        cout << "Choose an option:" << endl;
        cout << "1. Darken 50 % " << endl;
        cout << "2. Lighten 50 %" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        if (choice == 1)
            f7Darken(image);
        else if (choice == 2)
            f7lighten(image);
        else if (choice != 3)
        {
            cout << "Invalid choice, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice != 3);

    cout << "Exiting program..." << endl;
}

//filter 10 Detect Image. 
void detectImageEdges(Image& image) {

    // Get the width , height of the colored image
    int width = image.width;
    int height = image.height;

    // Create a new image object for the edge-detected image
    Image edgeImage(width, height);

    // Sobel operator for edge detection
    int sobelMask[3][3] = { {-1, 0, 1},
                            {-2, 0, 2},
                            {-1, 0, 1} };

    // go through each pixel in the colored image
    for (int i = 1; i < width - 1; ++i) {
        for (int j = 1; j < height - 1; ++j) {
            int gx = 0, gy = 0;
            // Convolve the Sobel mask with the neighborhood pixels
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    int pixelValue = image(i + x, j + y, 0); // Assuming grayscale
                    gx += pixelValue * sobelMask[x + 1][y + 1];
                    gy += pixelValue * sobelMask[y + 1][x + 1];
                }
            }
            // Calculate the gradient magnitude
            int magnitude = sqrt(gx * gx + gy * gy);
            // Invert the color
            int invertedValue = (magnitude > 128) ? 0 : 255;
            // Set the inverted value for the current pixel in the edge-detected image
            for (int k = 0; k < 3; ++k) {
                edgeImage(i, j, k) = invertedValue;
            }
        }
    }
    savePhoto(edgeImage);
}

//Natural Sun Light.
void sunLight(Image& image) {
    // loop for every pixel
    for (int i = 0; i < image.width; i++)
    {
        for (int j = 0; j < image.height; j++)
        {

            for (int k = 2; k < image.channels; k++)
            {
                // decrease the blue channel cause yellow contain red and green
                image(i, j, k) = image(i, j, k) * 0.8;
                if (image(i, j, k) < 0)
                {
                    image(i, j, k) = 0;
                }

            }

        }

    }
    savePhoto(image);
}

//frame.
void Frame(Image& image) {
    int colour, choice, R, G, B;
    bool valid = false;

    // Choose the colour frame.
    while (!valid) {
        cout << "Choose a colour (1-6):\n";
        cout << "1) Red\n2) Green\n3) Blue\n4) Yellow\n5) Purple\n6) Orange\n";
        cin >> colour;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 6.\n";
        }
        else {
            switch (colour) {
            case 1: R = 255, G = 0, B = 0; valid = true; break;
            case 2: R = 0, G = 255, B = 0; valid = true; break;
            case 3: R = 0, G = 0, B = 255; valid = true; break;
            case 4: R = 255, G = 255, B = 0; valid = true; break;
            case 5: R = 128, G = 0, B = 128; valid = true; break;
            case 6: R = 255, G = 165, B = 0; valid = true; break;
            default: cout << "Invalid input! Please enter a number between 1 and 6.\n";
            }
        }
    }

    // Create the frame.
    //UPPER ROW.
    for (int i = 0; i < 20; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, 0) = R;
                image(i, j, 1) = G;
                image(i, j, 2) = B;
            }
        }
    }

    //LEFT COLUMN
    for (int j = 0; j < 20; ++j)
    {
        for (int i = 0; i < image.width; ++i)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, 0) = R;
                image(i, j, 1) = G;
                image(i, j, 2) = B;
            }
        }

    }

    //GROUND ROW.
    for (int i = image.width - 20; i < image.width; ++i)
    {
        for (int j = 0; j < image.height; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, 0) = R;
                image(i, j, 1) = G;
                image(i, j, 2) = B;
            }
        }

    }

    //RIGHT COLUMN.
    for (int j = image.height - 20; j < image.height; ++j)
    {
        for (int i = 0; i < image.width; ++i)
        {
            for (int k = 0; k < 3; ++k)
            {
                image(i, j, 0) = R;
                image(i, j, 1) = G;
                image(i, j, 2) = B;
            }
        }
    }

    // Decide if decorated or simple.
    valid = false;
    while (!valid) {
        cout << "Choose if decorated or simple:\n1) Simple\n2) Decorated\n";
        cin >> choice;

        if (cin.fail() || (choice != 1 && choice != 2)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter 1 or 2.\n";
        }
        else {
            valid = true;
        }
    }

    // Apply decoration if needed.
    if (choice == 2) {
        for (int i = 30; i <= 35; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 255;
                }
            }
        }

        for (int j = 30; j <= 35; ++j) {
            for (int i = 0; i < image.width; ++i) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 255;
                }
            }
        }

        for (int i = image.width - 50; i <= image.width - 45; ++i) {
            for (int j = 0; j < image.height; ++j) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 255;
                }
            }
        }

        for (int j = image.height - 50; j <= image.height - 45; ++j) {
            for (int i = 0; i < image.width; ++i) {
                for (int k = 0; k < 3; ++k) {
                    image(i, j, k) = 255;
                }
            }
        }
    }
    savePhoto(image);
}

//blur.
void Blur(Image& image) {
    int kernel = 10;
    // Iterate over 10x10 pixels at a time.
    for (int x = 0; x < image.width; x += kernel) {
        for (int y = 0; y < image.height; y += kernel) {
            for (int c = 0; c < image.channels; ++c) {
                int sum = 0;
                int count = 0;

                // Calculate the sum of the pixels.
                for (int i = x; i < min(x + kernel, image.width); ++i) {
                    for (int j = y; j < min(y + kernel, image.height); ++j) {
                        sum += image(i, j, c);
                        count++;
                    }
                }

                Image image2;
                // Apply the blur.
                unsigned char average = static_cast<unsigned char>(sum / count);
                for (int i = x; i < min(x + kernel, image.width); ++i) {
                    for (int j = y; j < min(y + kernel, image.height); ++j) {
                        image(i, j, c) = average;
                    }
                }
            }
        }
    }
    savePhoto(image);
}

//purple effect.
void Purple(Image& image) {
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned int prpl = 1;
            for (int k = 0; k < 3; ++k) {

            }
            prpl = 0.5 * image(i, j, 1);
            image(i, j, 1) = prpl;
        }
    }
    savePhoto(image);
}

void filtersMenu(Image& image) {
    int Choice;
    // d0_while loop for infinite loop Menu  
    do {
        cout << "\nMenu 1:" << endl;
        cout << "1. Grey Scale." << endl;
        cout << "2. Convert to Black and White." << endl;
        cout << "3. Invert Image." << endl;
        cout << "4. Flip Image." << endl;
        cout << "5. Rotate Image." << endl;
        cout << "6. Resize Image." << endl;
        cout << "7. Crop Image." << endl;
        cout << "8. infrared Image." << endl;
        cout << "9. Merge 2 Image." << endl;
        cout << "10. Darken and Lighten Image." << endl;
        cout << "11. Detect Image Edge." << endl;
        cout << "12. Natural Sunlight." << endl;
        cout << "13. Frame." << endl;
        cout << "14. Blur." << endl;
        cout << "15. purple." << endl;
        cout << "16. Exit." << endl;
        cout << "Enter your choice: ";
        cin >> Choice;
        cin.ignore(); // to ignore '\n' from the stream if we take getline in file name


        if (Choice == 1)
            GreyScale(image);
        else if (Choice == 2)
            ConvertToBlackAndWhite(image);
        else if (Choice == 3)
            invertImage(image);
        else if (Choice == 4)
            flipMenu(image);
        else if (Choice == 5)
            rotationMenu(image);
        else if (Choice == 6)
            resizeImage(image);
        else if (Choice == 7)
            cropImage(image);
        else if (Choice == 8)
            infraredImage(image);
        else if (Choice == 9)
            merge(image);
        else if (Choice == 10)
            darken_and_lighten_menu(image);
        else if (Choice == 11)
            detectImageEdges(image);
        else if (Choice == 12)
            sunLight(image);
        else if (Choice == 13)
            Frame(image);
        else if (Choice == 14)
            Blur(image);
        else if (Choice == 15)
            Purple(image);
        else if (Choice == 16)
            cout << "Exiting the filters menu " << endl;
        else if (Choice != 16)
        {
            // Validation for not integer numbers to repeate 
            cout << "Invalid choice, please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (Choice != 16);
}
void menu() {
    while (true) {
        cout << "Welcome to Baby Photoshop for image processing!" << endl;
        cout << "A) Start Program." << endl << "B) Exit Program." << endl;
        cout << "Enter your choice (A/B): ";
        string choice;
        getline(cin, choice);
        if (choice == "A" || choice == "a") {
            cout << "Enter the name of the image to process: ";
            getline(cin, filename);
            string ext = filename.substr(filename.find_last_of(".") + 1);
            if (ext != "png" && ext != "jpg" && ext != "bmp" && ext != "tga") {
                cout << "Invalid extension. Supported extensions are .jpg, .png, .bmp, and .tga." << endl;
                continue;
            }
            Image image(filename);
            filtersMenu(image);
        }
        else if (choice == "B" || choice == "b") {
            cout << "Exiting Program..." << endl;
            return;
        }
        else {
            cout << "Invalid choice. Please enter 'A' to start the program or 'B' to exit." << endl;
        }
    }
}
int main() {
    menu();
}
