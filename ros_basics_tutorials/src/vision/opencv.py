import numpy as np 
import cv2


print("read imafe from file" )
img  = cv2.imread("panda.jpg")

print("create a window holder for the image")
cv2.namedWindow("Image",cv2.WINDOW_NORMAL)

print ('display the image ')
cv2.imshow("Image",img)

print ('press a key inside the image to make a copy')
cv2.waitKey(0)

