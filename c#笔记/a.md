# 输入输出
- Console.readline() 读入
- Console.writeline() 输出
- 均为字符串类型
- 类型转换
- Convert.Todouble()
- Convert.ToInt32()
- int.Parse()
- double.Parse()
- int.tryParse()
- bool b=int.tryParse("123",out number)
- 枚举 enum
`public enum Gender
    {
            男,
            女.
    }
`
- 结构 struct
`
public struct People{
    int a;int b;
    int c;
}
`
- 数组
`
int []nums=new int[10];
`
# 异常
try{

}
catch{

}
# 函数
- 产生随机数
- Random r=new Random();
- int a=r.Next(l,r);
- 左闭右开