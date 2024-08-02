#include <Arduino.h>
#include "ESP32_Servo.h"
#include <Wire.h>
#include "esp_camera.h"
#include "img_converters.h"
#include "Arduino.h"
#include "camera_index.h"
#include <opencv2/opencv.hpp>

using namespace cv;

#define SERVO_PIN 2

#define PWDN_GPIO_NUM     32
#define RESET_GPIO_NUM    -1
#define XCLK_GPIO_NUM      0
#define SIOD_GPIO_NUM     26
#define SIOC_GPIO_NUM     27
#define Y9_GPIO_NUM       35
#define Y8_GPIO_NUM       34
#define Y7_GPIO_NUM       39
#define Y6_GPIO_NUM       36
#define Y5_GPIO_NUM       21
#define Y4_GPIO_NUM       19
#define Y3_GPIO_NUM       18
#define Y2_GPIO_NUM        5
#define VSYNC_GPIO_NUM    25
#define HREF_GPIO_NUM     23
#define PCLK_GPIO_NUM     22

Servo cameraServo;

void setup() {
  Serial.begin(115200);

  cameraServo.attach(SERVO_PIN);

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_SVGA;
  config.jpeg_quality = 10;
  config.fb_count = 2;

  // Initialize the camera
  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    return;
  }
}

void loop() {
  camera_fb_t * fb = NULL;
  fb = esp_camera_fb_get();
  if (!fb) {
    Serial.println("Camera capture failed");
    return;
  }

  // Process the image
  processImage(fb->width, fb->height, fb->format, fb->buf);

  // Return the frame buffer back to the camera library
  esp_camera_fb_return(fb);
}

void processImage(size_t width, size_t height, pixformat_t format, uint8_t *data) {
  // Your image processing code goes here
  // Example: Convert the image to grayscale
    Mat img(height, width, CV_8UC3, data);
  Mat gray;
  cvtColor(img, gray, COLOR_BGR2GRAY);

  // Example: Detect green color
  Mat hsv;
  cvtColor(img, hsv, COLOR_BGR2HSV);
  inRange(hsv, Scalar(40, 40, 40), Scalar(80, 255, 255), hsv);

  // Example: Find contours and draw them
  vector<vector<Point>> contours;
  findContours(hsv, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);
  drawContours(img, contours, -1, Scalar(0, 255, 0), 2);

  // Example: Rotate servo motor based on color detection
  if (contours.size() > 0) {
    cameraServo.write(90); // Rotate the servo to 90 degrees
  } else {
    cameraServo.write(0); // Rotate the servo to 0 degrees
  }

  // Display the processed image
  imshow("Processed Image", img);
  waitKey(1);
}
