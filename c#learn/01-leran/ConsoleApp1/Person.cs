using System;
using System.Collections.Generic;
using System.Text;

namespace ConsoleApp1
{
    class Person
    {
        public Person() { }
        public Person(int a)
        {
            this.Age = a;
        }
        public int _age;
        public int Age
        {
            get { return _age; }
            set { _age = value; }
        }
    }
    class People : Person
    {

    }
}
