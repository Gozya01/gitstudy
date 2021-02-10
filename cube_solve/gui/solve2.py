from rubik_solver import utils
f=open("str.txt","r")
a=f.readline()
ff=open('solve.txt',"w")
c=utils.solve(cube, 'CFOP')
for i in c:
    ff.write(i)
