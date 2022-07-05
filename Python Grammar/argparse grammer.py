# argparse
import argparse



def add2Nums(a, b):
    return a + b

#创建参数容器
parser = argparse.ArgumentParser(description='Get Adding Result')
                                                #容器的作用
#为容器添加参数
parser.add_argument('-a', '--num1', type=int, metavar='', help='The First Number')
                #   flag    全称     类型    使帮助文档更简单    参数解释信息
parser.add_argument('-b', '--num2', type=int, metavar='', help='The Second Number')


#创建互斥组
group = parser.add_mutually_exclusive_group()
group.add_argument('-m', '--mode1', action='store_true', help='Print The Result')
                                #  默认store_false，
#                               在命令行中被调用时激活
group.add_argument('-n', '--mode2', action='store_true', help='Print Error')


#创建容器变量，方便调用参数
arg = parser.parse_args()


if __name__ == '__main__':#这条语句内的程序只能在当前文件执行，不得被调用
    if arg.mode1:
        print(add2Nums(arg.num1, arg.num2))
    elif arg.mode2:
        print('Error')
    else:
        print(add2Nums(arg.num1, arg.num2))

#cmd命令行：
# 当前文件位置 cd desktop
# python demo.py -h    python demo.py --help  查看帮助信息
# python demo.py -a 5 -b 4  输入参数
# python demo.py -a 5 -b 4 -m 选择m模式
# python demo.py -a 5 -b 4 -n 选择n模式