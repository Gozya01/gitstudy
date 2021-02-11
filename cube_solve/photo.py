import cv2
import numpy as np
import math 
import random


#first
#彩色图转灰度图
imgobj = cv2.imread('E:\gitstudy\gitstudy\cube_solve\\test_photo\IMG_20210211_161807.jpg')
gray = cv2.cvtColor(imgobj, cv2.COLOR_BGR2GRAY)
#cv2.imwrite("2.jpg", gray)

#second
#高斯滤波去噪
blurred = cv2.GaussianBlur(gray, (3, 3), 0)
#cv2.imwrite('3.jpg',blurred)

#third
#canny边缘检测
canny = cv2.Canny(blurred,30,30)
#cv2.imwrite('4.jpg',canny)

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

#颜色识别 点
def Check(a):
    h=a[0]
    s=a[1]
    v=a[2]
    if 0<=s<=40 and 150<=v<=255:
        return 0
        return 'w'
    if ((0<=h<=7) or (156<=h<=180)) and 43<=s<=255 and 46<=v<=255:
        return 1
        return 'r'
    if (7<=h<=25)and 43<=s<255  and 46<=v<=255:
        return 2
        return 'o'
    if (26<=h<=40)and 46<=v<=255 and 43<=s<=255:
        return 3
        return 'y'
    if (40<=h<=80)and 43<=s<=255 and 46<=v<=255:
        return 4
        return 'g'
    if 100<=h<=124 and 43<=s<=255 and 46<=v<=255:
        return 5
        return 'b'
    
    return 6
#颜色识别 块
def Judge(b):
    b=cv2.cvtColor(b,cv2.COLOR_BGR2HSV)
    lst=[0 for i in range(0,7)]
    l=b.shape[0]
    ll=b.shape[1]
    for i in range(1000):
        x=random.randint(0,l-1)
        y=random.randint(0,ll-1)
        c=Check(b[x][y])
        lst[c]+=1
    '''for i in b:
        for j in i:
            c=Check(j)
            lst[c]+=1
    '''
    ans=0
    id=0
    for i in range(0,6):
        if lst[i]>ans:
            ans=lst[i]
            id=i
    if id==0:
        return 'w'
    if id==1:
        return 'r'
    if id==2:
        return 'o'
    if id==3:
        return 'y'
    if id==4:
        return 'g'
    if id==5:
        return 'b'
#寻找轮廓
content,d=cv2.findContours(img_four,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
#最大轮廓
c=sorted(content,key=lambda x:cv2.contourArea(x),reverse=True)
a=c[0]


#极点
leftmost=tuple(a[a[:,:,0].argmin()][0])
rightmost=tuple(a[a[:,:,0].argmax()][0])
topmost=tuple(a[a[:,:,1].argmin()][0])
bottommost=tuple(a[a[:,:,1].argmax()][0])
sx=min(leftmost[0],rightmost[0],topmost[0],bottommost[0])
sy=min(leftmost[1],rightmost[1],topmost[1],bottommost[1])
tx=max(leftmost[0],rightmost[0],topmost[0],bottommost[0])
ty=max(leftmost[1],rightmost[1],topmost[1],bottommost[1])
#cv2.imwrite('17.jpg',imgobj[sy:ty,sx:tx])
#图像分割

#cv2.imwrite('8.jpg',imgobj[sy:ty,sx:tx])
xd=(tx-sx)/3
yd=(ty-sy)/3
lst=[]
for i in range(0,3):
    for j in range(0,3):
       b=imgobj[int(sy+i*yd):int(sy+(i+1)*yd),int(sx+j*xd):int(sx+(j+1)*xd)]
       cv2.imwrite(str(8+i*3+j)+'.jpg',b)
       f=Judge(b)
       lst.append(f)
print(lst)