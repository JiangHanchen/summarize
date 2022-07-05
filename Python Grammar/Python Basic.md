## 输入输出

### input()

1. 通过`input()`进行输入输出，可以带有提示性文字

   ```python
   name = input("请输入姓名")
   ```

2. 一次性输入多个数据

   ```python
   chinese, math = input("请输入语文和数学成绩（中间用,分隔）").split(",")
   ```

   ```python
   a = []
   a = input().split(' ')
   ```

### print()

1. `end`和`sep`参数

   `end`参数是输出末尾紧跟的字符，sep参数是输出多个数据是中间的分隔字符

   ```python
   s = [1, 2, 3, 4, 5]
   for i in s:
       print(i, end=',')
   ```

   > 1,2,3,4,5,
   > Process finished with exit code 0

   

   ```python
   a = 1
   b = 5.5
   c = 'coco'
   print(a, b, c, sep=',')
   ```

   > 1,5.5,coco
   >
   > Process finished with exit code 0

​	

## 基本数据类型

### 整数

### 浮点数

### 字符串

1. 用`" "`或者`' '`引起来。若要包含单引号，需用双引号；要表示双引号，需用单引号

2. 特殊字符需要用转义字符`\`

3. 如果想完全表示字符串本身，可以使用r.比如：

   ```python
   print(r"Hello\tWorld!")
   ```

   > Hello\tWorld!
   >
   > Process finished with exit code 0

4. 三引号表示多行字符串

   ```python
   print('''hello
   world''')
   ```

   > hello
   > world
   >
   > Process finished with exit code 0

   

### 布尔值

​	直接用`True`和`False`表示布尔值



## 基本运算

加`+` 减`-` 乘`* `

除`/`：得到浮点数

整除`//`：得到整数

取余`%`

幂运算`**`

增强运算`+=` ` -=` ` *=`  `/= ` `//=` `%=`  `**=`



## 字符串

1.  `ord()`函数获取字符Unicode编码，`chr()`函数把编码转换为字符

    ```python
    print(ord('J'))
    print(chr(74))
    ```
    
    > 74
    > J
    >
    > Process finished with exit code 0

2. `len()`函数返回字符串长度

   ```python
   print(len("abc"))
   ```

3. 字符串格式化

   1. 占位符

      ```python
      print('Hi, %s, you have $%d.' % ('Nixx', 1000000))
      ```

      > Hi, Nixx, you have $1000000.
      >
      > Process finished with exit code 0

   

   | 占位符 | 替换内容 |
   | :----- | :------- |
   | %d     | 整数     |
   | %f     | 浮点数   |
   | %s     | 字符串   |

   ​		 不太确定应该用什么，`%s`永远起作用，它会把任何数据类型转换为字符串 
   2. `format()`格式化

      ```python
      f = 1.2345
      print("答案是{:.2f}".format(f))
      print("今天（{}）{}地区的天气{}，气温{}-{}℃".format("2021.9.2", "西安", "晴", 20, 26))
      ```

      > 答案是1.23
      > 今天（2021.9.2）西安地区的天气晴，气温20-26℃
      >
      > Process finished with exit code 0

   3. `f-string`格式化

      ```python
      a = 1.234
      b = "正确"
      c = 5
      print(f"最终{b}的答案是{a:.2f}，你获得了{c}分")
      ```

      > 最终正确的答案是1.23，你获得了5分
      >
      > Process finished with exit code 0

4. 使用`+`连接两个字符串，`*`复制字符串

   ```python
   a = "123"
   b = "456"
   c = a + b
   d = a * 2
   print(c + "\n" + d)
   ```

   > 123456
   > 123123
   >
   > Process finished with exit code 0

5. 判断子串是否在字符串内

   ```python
   str1 = '123456'
   if '345' in str1:
       print("yes")
   else:
       print("no")
   ```

   > yes
   >
   > Process finished with exit code 0

6. 强制类型转换为字符串

   ```python
   str1 = str(666)
   print(str1, type(str1))
   ```

   > 666 <class 'str'>
   >
   > Process finished with exit code 0

7. `str.upper()`和`str.lower()`完成大小写转换

8. 字符串转列表

   ```python
   str3 = "1,2,3,4,5"
   print(str3.split(","))
   ```

   > ['1', '2', '3', '4', '5']
   >
   > Process finished with exit code 0

9. `str.count(sub_str)`计算子串sub_str在str中出现的次数

10. `str.replace(str, new_str)`替换子串

    ```python
    str1 = '12123456'
    print(str1.replace("12", "54"))
    ```

    > 54543456
    >
    > Process finished with exit code 0

11. `new_str.join(str)`插入新字符串

    ```python
    print("#".join("你好吗"))
    ```

    > 你#好#吗
    >
    > Process finished with exit code 0

12. 格式化输出

    字符串格式化输出format{:填充 对齐 宽度 千位分隔 精度 类型}

    ```python
    print("{:-^20,.2f}".format(123456.789))
    # :表示使用格式化方法
    # -表示填充字符，可以是任意字符
    # ^表示对齐方式，>是右对齐，<是左对齐，^是居中对齐
    # 20表示开辟的宽度位数
    # ,表示千位分隔字符
    # .2表示输出精读
    # f表示数据类型
    ```

    > -----123,456.79-----
    >
    > Process finished with exit code 0


13. `exec()`函数

    执行字符串语句

    ```python
    str = "x = 5"
    exec(str)
    print(x)
    ```

    > 5
    >
    > Process finished with exit code 0



## 高级数据类型

### 序列类型`list`、`tuple`、`str`共同操作

1. 索引体系：首元素索引为0，正向递增；末尾元素索引为-1，反向递减

2. 切片：`s[i: j: k]`从i开始（含），到j结束（不含），每隔k个索引去一个元素（一定取i）；

   i、j省略时，分别表示0和-1；k省略时，表示0

   ```python
   l = [0, 1, 2, 3, 4, 5, 6, 7]
   print(l[0:3])
   print(l[0:5:3])
   print(l[0::3])
   print(l[::-1])
   ```

   > [0, 1, 2]
   > [0, 3]
   > [0, 3, 6]
   > [7, 6, 5, 4, 3, 2, 1, 0]
   >
   > Process finished with exit code 0

3. 判断元素是否在序列中

   ```python
   x in s
   x not in s
   ```

   

4. 连接两个序列

   ```python
   s + t
   ```

   

5. 将序列复制n次

   ```python
   s * n
   ```

   

6. `len(s)`返回长度

7. `s.min()`和`s.max()`：如果序列中元素可以比较大小，返回最大和最小的元素

8. `s.index(x)`返回第一次出现x的索引

9. `s.count(x)`计算元素x出现的次数

### list

1. 定义和初始化

   ```python
   l = []
   l = [1, 2, 3]
   print(l)
   ```

   > [1, 2, 3]
   >
   > Process finished with exit code 0

   

2. 替换元素或子列表：`s[i] = x`、`s[i:j:k] = [1,2,3,4]`

3. 删除元素或字列表：`del s[i]`、`del s[i:j:k]`

4. 将列表添加在另一列表末尾：`s += t`

5. 在末尾添加元素：`s.append(x)`

6. 清空列表：`s.clear()`

7. 复制列表：`s.copy()`

8. 插入元素：`s.insert(i, x)`

9. 根据索引返回并删除元素：`s.pop(i)`

10. 根据元素删除元素（只删除第一次出现的该元素）：`s.remove(x)`

11. 逆序所有元素：`l.reverse()`

12. 与list有关的赋值语句

    ```python
    a = [1, 2, 3, "py", "thon"]
    b, c, d, e, f = a
    print(b, c, d, e, f, sep='  ')
    b, *c, d = a  # 用c接收多个数据，是序列类型
    print(b, c, d, sep='  ')
    ```

    > 1  2  3  py  thon
    > 1  [2, 3, 'py']  thon
    >
    > Process finished with exit code 0



### tuple

1. 特点：一旦创建，就不可进行改动

2. 创建和初始化：

   ```python
   t = ()
   t = (1, 2, 3)
   print(t)
   ```

   > (1, 2, 3)
   >
   > Process finished with exit code 0

3. 对于只有一个元素的元组，为防止产生歧义，应这么定义：

   ```python
   t = (1,)
   ```



### set

1. 特点：与数学上集合特点相同，能够自动排除重复元素、元素无序

2. 定义和初始化：

   ```python
   A = set()
   A = {1, 2, 3}
   B = set([1, 2, 3])
   C = set((1, 2, 3))
   D = set("123")
   print(A, B, C, D)
   ```

   > {1, 2, 3} {1, 2, 3} {1, 2, 3} {'1', '3', '2'}
   >
   > Process finished with exit code 0

3. 运算：

   ```python
   print(A | B)  # 并
   print(A - B)  # 差
   print(A & B)  # 交
   print(A ^ B)  # 返回非相同元素
   print(A >= B)  # 判断包含关系
   # 集合运算支持增强操作符
   ```

4. `A.add(x)` 增加元素

5. `A.discard(x)` 删除元素  若元素不在集合内，不报错

6. `A.remove(x) ` 删除元素  若元素不在集合内，报错KeyError

7. `A.clear()`  删除所有元素

8. `A.pop()`   随机返回一个元素，并删除该元素，若A为空报错KeyError

9. `A.copy()`  返回一个副本

10. `len(A)`  返回元素个数

11. `x in A `、 `x not in A`判断元素是否在集合中

12. `set(X)`  强制类型转换



### dict

1. 定义、初始化和访问

   ```python
   d = {}
   d = {'Michael': 95, 'Bob': 75, 'Tracy': 85}
   print(d['Michael'])
   ```

   > 95
   >
   > Process finished with exit code 0

2. `del d[k]`删除键k对应的数据值
3. `k in d`判断键是否在字典中
4. `d.keys()`返回字典中所有键信息
5. `d.values()`返回字典中所有值信息
6. `d.items()`返回字典中所有键值对信息
7. `d.get(k,default)`返回键k对应值，若不存在则返回default
8. `d.pop(k,default)`取出(返回并删除)键k对应值，若不存在则返回default
9. `d.popitem()`随机取出(返回并删除)一个键值对，以元组形式返回
10. `d.clear()`删除所有键值对
11. `len(d)`返回字典中键值对个数



## 条件判断

```python
if <条件判断1>:
    <执行1>
elif <条件判断2>:
    <执行2>
elif <条件判断3>:
    <执行3>
else:
    <执行4>
```



## 循环

for循环

```python
for i in range(5):
    print(i, end=' ')
```

> 0 1 2 3 4 
> Process finished with exit code 0



```python
for i in range(1, 10, 2): 
    print(i, end="")
```

> 13579
> Process finished with exit code 0



while循环

```python
i = 0
str = "abcdefg"
while str[i] != 'g':
    print(str[i], end='')
    i += 1
```

> abcdef
> Process finished with exit code 0



循环中的else语句

```python
i = 0
str = "abcdefg"
while str[i] != 'g':
    print(str[i], end='')
    i += 1
else: print("  OK")# 当循环没有被break时，执行else语句，否则不执行
```

> abcdefOK
>
> Process finished with exit code 0

```python
i = 0
str = "abcdefg"
while str[i] != 'g':
    print(str[i], end='')
    i += 1
    if i == 3:
        break
else: print("  OK")# 当循环没有被break时，执行else语句，否则不执行
```

> abc
> Process finished with exit code 0



## 自定义函数



自定义函数及调用

```python
def fun(a, b, c=1):  # 参数列表中的参数可以多于调用时的参数;调用时可以覆盖预设值
    return (a + b) // c

print(fun(1, 2))  # 调用时也可以fun(a = 2,c = 2,b = 1)来改变调用顺序
```



传入参数数量不确定时

```python
def addFunction(*a):  # a是一个列表，可以接受不确定个数的参数
    sum = 0
    for i in a:
        sum += i
    return sum

print(addFunction(1, 2, 3, 4))
```



使用lambda自定义函数：函数名 = lambda [参数列表]: 返回值

```python
add = lambda x, y: x + y
```





## 迭代

对于可迭代的变量，可以使用迭代对其中所有元素进行遍历

```python
d = {'a': 1, 'b': 2, 'c': 3}
for key in d:
    print(d[key])
```

> 1
> 2
> 3
>
> Process finished with exit code 0

同理，其他可迭代的数据类型有：

```python
for ch in 'ABC':
for x in [1,2,3]:
for x in (1,2,3);
for x, y in [(1, 1), (2, 4), (3, 9)]:
```



通过`enumerate()`方法可以同时访问索引和内容

```python
for i, value in enumerate ([1, 2, 3]):
    print(i, value, sep=',', end='---')
```

> 0,1---1,2---2,3---
> Process finished with exit code 0



## 列表生成式

格式：

​	[表达式1 if 条件 else 表达式2 数据来源]

​	对于数据来源中的所有取值，判断if语句，满足则根据表达式1生成元素放入列表，不满足则根据表达式2生成元素放入列表。

```python
[x + y if x % 2 == 0 else -x for x in range(1, 11) for y in range(11,22)]
[m + n for m in 'ABC' for n in 'XYZ']
```



## 列表生成器

1. generator原理：

   如果列表元素可以按照某种算法推算出来时，就不必创建完整的list，通过一边循环一边计算的机制遍历列表 

2. 创建generator：

   将列表生成式的`[]`改为`()`即可

   ```python
   g = (x * x for x in range(10))
   ```

3. 访问：

   ```python
   for n in g:
   	print(n)
   ```



## 高阶函数

### map()

将可迭代对象中的元素依次完成某种操作，并返回一个新的map对象

```python
def fun(x):
    return x * x
s = [1, 2, 3, 4]
t = list(map(fun, s))
print(t)
```

> [1, 4, 9, 16]
>
> Process finished with exit code 0



```python
for i in range(3):
    (x, y) = tuple(map(int, input().split(' ')))
    print(x, y)
```

> 2 3
> 2 3
> 5 6
> 5 6
> 7 7
> 7 7
>
> Process finished with exit code 0



### reduce()

`reduce`把一个函数作用在一个序列`[x1, x2, x3, ...]`上，这个函数必须接收两个参数，`reduce`把结果继续和序列的下一个元素做累积计算，相当于`reduce(f, [x1, x2, x3, x4]) = f(f(f(x1, x2), x3), x4)`

```python
from functools import reduce
def add(x, y):
    return x + y
s = [1, 2, 3]
ans = reduce(add, s)
print(ans)
```

> 6
>
> Process finished with exit code 0



### fiilter()

根据返回的布尔值决定保留或删除元素

```python
def is_odd(n):
    return n % 2 == 1

print(list(filter(is_odd, [1, 2, 4, 5, 6, 9, 10, 15])))
```

> [1, 5, 9, 15]
>
> Process finished with exit code 0



### sorted()

默认由小到大进行排序

```python
s = [5, 6, 3, 2, 1, 4, 0, -2, -1]
print(sorted(s))
print(sorted(s, reverse=True))
print(sorted(s, key=abs))  # 先对元素进行abs()处理，再进行排序

t = ["Nixx", "Bob", "Tina", "apple", "baby"]
print(sorted(t))  # 按照首字母Unicode排序
print(sorted(t, key=str.lower))  # 不按照Unicode，而是只按照首字母字母序排列
```

> [-2, -1, 0, 1, 2, 3, 4, 5, 6]
> [6, 5, 4, 3, 2, 1, 0, -1, -2]
> [0, 1, -1, 2, -2, 3, 4, 5, 6]
> ['Bob', 'Nixx', 'Tina', 'apple', 'baby']
> ['apple', 'baby', 'Bob', 'Nixx', 'Tina']
>
> Process finished with exit code 0



## 文件

1. 打开文件

   变量名 = open("目录", "打开方式", encoding="编码模式")

   ```python
   f = open("C:\\Users\\Administrator\\Desktop\\file.txt", "rt+", encoding="UTF-8")
   ```

   打开方式：

   > t默认值，文本文件模式
   > b二进制文件模式
   >
   > r默认值只读模式，如果文件不存在返回FileNotFoundError
   > w覆盖写模式，文件不存在则创建，存在则完全覆盖
   > x创建写模式，文件不存在则创建，存在则返回FileExistsError
   > a追加写模式，文件不存在则创建，存在则在文件后追加写
   > r+既可读，又可写

2. 文件遍历

   f.read(x)读取文件前x个字符 无参数则读取整个文件
   f.readline(x)读取文件第一行前x个字符  无参数则读取整个第一行
   f.readlines(x)读取文件前x行 无参数则读取整个文件

   ```python
   txt = f.read(2)
   while txt != '':
       # 处理操作
       txt = f.read(2)
   
   for i in f.readlines():  # 一次性读入，逐行遍历
       print(i)
   
   for i in f:  # 逐行读入，逐行遍历
       print(i)
   ```



## 面向对象编程

1. 类的定义和对象的创建

   ```python
   class Student(object): #创建类；其中()中是继承的类；所有的类都继承object
   
       def __init__(self, name, score): # 构造函数
           self.name = name
           self.score = score
   
       def print_name_score(self): # 方法
           print(self.name + str(self.score))
   
   
   stu1 = Student("Nixx", 95) # 创建对象
   stu1.print_name_score() # 调用方法
   ```

   > Nixx95
   >
   > Process finished with exit code 0

2. 访问限制

   成员变量名前如果加上__，表明该变量是该类私有变量，不允许外部访问

   如果要访问或修改，需要增加get或set方法

   ```python
   class Student(object):
   
       def __init__(self, name, score):
           self.__name = name
           self.__score = score
   ```

3. 继承

   子类继承父类后，能够继承父类中所有属性和方法；同时可以添加新的属性、方法，还可以对父类的方法进行覆写

   ```python
   class Person(object):
       nationality = "China" # 类变量
       def __init__(self, name, age, gender):
           self.__name = name
           self.__age = age
           self.__gender = gender
   
       def get_name(self):
           return self.__name
   
       def get_age(self):
           return self.__age
   
       def get_gender(self):
           return self.__gender
   
   class Student(Person):
       def __init__(self, name, age, gender, stu_id):
           super().__init__(name, age, gender) # 调用父类的构造函数
           self.stu_id = stu_id
   
   stu = Student("Nixx", 18, "M", "123")
   print(stu.get_age())
   ```

   