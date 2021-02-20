import cv2
import cv2
import numpy as np
import math 
import random


#first
#彩色图转灰度图
imgobj = cv2.imread('E:\gitstudy\gitstudy\cube_solve\\test_photo\\notest1.jpg')
gray = cv2.cvtColor(imgobj, cv2.COLOR_BGR2GRAY)
#cv2.imwrite("2.jpg", gray)

#second
#高斯滤波去噪
blurred = cv2.GaussianBlur(gray, (3, 3), 0)
#cv2.imwrite('3.jpg',blurred)

#third
#canny边缘检测
canny = cv2.Canny(blurred,20,30)
cv2.imwrite('tt.jpg',canny)

#fourth
#膨胀处理合并线
kernel = np.ones((3,3), np.uint8)
dilated = cv2.dilate(canny, kernel, iterations=2)
#cv2.imwrite('5.jpg',dilated)

#腐蚀处理
eroded= cv2.erode(dilated,kernel)
#cv2.imwrite('6.jpg',eroded)

#膨胀处理
k=np.ones((3,3),np.uint8)
img_four=cv2.dilate(eroded,k)
#cv2.imwrite('7.jpg',img_four)
contours,d=cv2.findContours(img_four,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
contours=sorted(contours,key=lambda x:cv2.contourArea(x),reverse=True)
rect=cv2.minAreaRect(contours[0])
points=cv2.boxPoints(rect)
points=np.int0(points)
cv2.drawContours(imgobj,[points],0,(255,255,255),2)
cv2.imwrite('E:\gitstudy\gitstudy\cube_solve\\test_photo\IMG_20210215_164932.jpg',imgobj)