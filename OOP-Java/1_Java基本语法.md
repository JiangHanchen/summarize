# Java基础知识

## 1.1 Java SE、EE、ME区别

[链接](https://blog.csdn.net/xiha_zhu/article/details/79854484?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164065104516780265482527%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164065104516780265482527&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-1-79854484.first_rank_v2_pc_rank_v29&utm_term=ME+EE+SE&spm=1018.2226.3001.4187)

## 1.2 JVM、JRE、JDK区别

[链接](https://blog.csdn.net/ancientear/article/details/79483592?ops_request_misc=&request_id=&biz_id=102&utm_term=Jdk%E5%92%8CJre%E5%92%8CJVM%E7%9A%84%E5%8C%BA%E5%88%AB&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-0-79483592.nonecase&spm=1018.2226.3001.4187)

1. JVM提供.class字节码文件的运行环境，是纯软件计算机，屏蔽和操作平台相关的内容，实现跨平台
2. JRE = JVM + lib库，能够运行字节码文件，是java的运行环境
3. JDK有更多的开发工具包，包含调试器，编译器（javac把.java文件编译成.class文件），是java的开发环境

## 1.3 基本数据类型

[链接](https://blog.csdn.net/qq_42225047/article/details/107094715?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164065370616780357225577%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164065370616780357225577&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-107094715.first_rank_v2_pc_rank_v29&utm_term=java%E6%95%B0%E6%8D%AE%E7%B1%BB%E5%9E%8B&spm=1018.2226.3001.4187)

## 1.4 常量

[链接](https://blog.csdn.net/weixin_45183530/article/details/104811829?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164065419016780357273426%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=164065419016780357273426&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-1-104811829.first_rank_v2_pc_rank_v29&utm_term=java%E5%B8%B8%E9%87%8F&spm=1018.2226.3001.4187)

## 1.5 基本数据类型的转换

[链接](https://blog.csdn.net/jdliyao/article/details/84557310?ops_request_misc=&request_id=&biz_id=102&utm_term=java%E7%B1%BB%E5%9E%8B%E8%BD%AC%E6%8D%A2&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-4-84557310.nonecase&spm=1018.2226.3001.4187)

[parseXxx()和valueOf()方法](https://blog.csdn.net/CSDN_fzs/article/details/84332062?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522164065604116780271949598%2522%252C%2522scm%2522%253A%252220140713.130102334.pc%255Fall.%2522%257D&request_id=164065604116780271949598&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~first_rank_ecpm_v1~rank_v31_ecpm-1-84332062.first_rank_v2_pc_rank_v29&utm_term=java%E6%95%B0%E6%8D%AE%E8%BD%AC%E6%8D%A2parse%E6%96%B9%E6%B3%95&spm=1018.2226.3001.4187)

## 1.6 输入输出

```java
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Demo {
    public static void main(String[] args) throws IOException {
        InputStreamReader is = new InputStreamReader(System.in);
        BufferedReader br = new BufferedReader(is);
        
        System.out.println("请输入字符串");
        String str = br.readLine();
        System.out.println("您输入的是" + str);

        System.out.println("请输入一个整数");
        str = br.readLine();
        int i = Integer.parseInt(str);
        System.out.println("您输入的整数是" + i);
    }
}
```

## 1.7 数组

```java
public class Demo {
    public static void main(String args[]) {
        int data[] = new int[3];//存储在栈内存中

//        也可以这么定义
//        int data[];
//        data = new int[3];

//        定义静态数组并初始化
//        int data[] = {10, 20, 30};

        data[0] = 10;
        data[1] = 20;
        data[2] = 30;//存储在堆内存中
        for(int x = 0; x < data.length; x++) {
            System.out.println(data[x]);
        }

        int b[] = new int[3];
        b = data;//数组的引用  本质上是不同的栈可以指向相同的堆
        for(int x = 0; x < data.length; x++) {
            System.out.println(data[x]);
        }
    }
}
```

1. > 