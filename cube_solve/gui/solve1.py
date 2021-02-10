from rubik_solver import utils
f=open("str.txt","r")
a=f.readline()
ff=open('solve.txt',"w")
print(a)
c=utils.solve(a, 'Beginner')
for i in c:
    ff.write(i)
