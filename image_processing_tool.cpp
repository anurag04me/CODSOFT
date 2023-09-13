#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main() {
    Mat image;

    // Load an image
    std::string imagePath;
    std::cout << "Enter the path to the image: ";
    std::cin >> imagePath;

    image = imread(imagePath);

    if (image.empty()) {
        std::cout << "Error: Could not open or find the image." << std::endl;
        return -1;
    }

    while (true) {
        // Display menu
        std::cout << "Image Processing Menu:" << std::endl;
        std::cout << "1. Display Image" << std::endl;
        std::cout << "2. Convert to Grayscale" << std::endl;
        std::cout << "3. Apply Blur Filter" << std::endl;
        std::cout << "4. Apply Sharpen Filter" << std::endl;
        std::cout << "5. Save Processed Image" << std::endl;
        std::cout << "6. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                imshow("Original Image", image);
                waitKey(0);
                break;
            case 2:
                cvtColor(image, image, COLOR_BGR2GRAY);
                std::cout << "Image converted to grayscale." << std::endl;
                break;
            case 3:
                blur(image, image, Size(5, 5));
                std::cout << "Blur filter applied." << std::endl;
                break;
            case 4:
                Mat kernel = (Mat_<float>(3, 3) << -1, -1, -1, -1, 9, -1, -1, -1, -1);
                filter2D(image, image, -1, kernel);
                std::cout << "Sharpen filter applied." << std::endl;
                break;
            case 5:
                std::string outputPath;
                std::cout << "Enter the path to save the processed image: ";
                std::cin >> outputPath;
                imwrite(outputPath, image);
                std::cout << "Processed image saved." << std::endl;
                break;
            case 6:
                std::cout << "Exiting the program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
