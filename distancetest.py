# Importing all modules
import cv2
import numpy as np


img = cv2.imread('image1.jpg', 0)
template = cv2.imread('template1.jpg', 0)
h,w = template.shape
pixels=w
print(pixels)
focal=105.3
width=40
dist = (width*focal)/pixels
print(dist)

# print(video.shape)

while True:
    cv2.imshow('img', img)
    cv2.imshow('temp', template)
    if cv2.waitKey(1) == ord('q'):
        break
cv2.destroyAllWindows()