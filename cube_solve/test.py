import cv2
import numpy as np
import math 
import random

img=cv2.imread('11.jpg')
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
print(Judge(img))