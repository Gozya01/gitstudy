from  tkinter import *
import time
import os
root = Tk()
root.geometry('500x500')
t=time.time()
def Show():
    str_one=str(time.time()-t)+'ms'
    lb = Label(root,text=str_one,\
            bg='#d3fbfb',\
            fg='red',\
            font=('Consolas',32),\
            width=20,\
            height=2,\
            relief=SUNKEN)
    lb.pack()    
def run1():
    t=time.time()
    os.system('E:\opencv_cube\gui\dist\photo.exe')
def run2():
    os.system('E:\opencv_cube\gui\dist\solve1.exe')
    Show()
def run3():
    os.system('E:\opencv_cube\gui\dist\solve2.exe')
    Show()
def run4():
    os.system('E:\opencv_cube\gui\dist\solve3.exe')
    Show()
lb = Label(root,text='Cube-solve',\
        bg='#d3fbfb',\
        fg='red',\
        font=('Consolas',32),\
        width=20,\
        height=2,\
        relief=SUNKEN)
lb.pack()

btn1 = Button(root, text='开始运行', font=('Consolas',32),bg='#d3fbfb',width=20,height=1,command=run1)
btn2 = Button(root, text='层先法', bg='#FFC0CB',font=('Consolas',25),width=20,height=1,command=run2)
btn3 = Button(root, text='Cfop',  font=('Consolas',25),bg='#00FF00',width=20,height=1,command=run3)
btn4 = Button(root, text='Kociemba',  font=('Consolas',25),bg='#FF4500',width=20,height=1,command=run4)

btn1.pack()
btn2.pack()
btn3.pack()
btn4.pack()
root.mainloop()