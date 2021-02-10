from rubik_solver import utils
f=open("str.txt","r")
a=f.readline()
ff=open('solve.txt',"w")
c=utils.solve(cube, 'Kociemba')
for i in c:
    ff.write(i)
