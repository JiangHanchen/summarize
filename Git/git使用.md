# git使用



## 设置用户名和邮箱

第一次使用git需要设置用户名和邮箱，以便知晓不同版本的提交者：

>**git config --global user.name "xxxx"**
>
>**git config --global user.email "xxxx"**

查看用户名和邮箱：

> **git config user.name**
>
> **git config user.email**



## 初始化仓库

初始化仓库，创建.git隐藏文件夹：

> **git init**



## 添加缓存区

添加缓存区：

> **git add filename**     添加某个文件
>
> **git add .**     添加全部文件

查看缓存区：

> **git status**
>
> 红色字体代表缓存区中没有被追踪到的文件，需要添加到缓存区；绿色字体代表成功添加到缓存区中的文件，需要提交



## 提交本地库

提交本地库：

> **git commit -m "版本信息" filename**     提交某个文件
>
> **git commit -m "版本信息"**     提交所有文件

查看历史版本：

> **git log**
>
> 黄色字体代表提交的版本号，白色字体代表提交信息，HEAD所在版本为当前指针指向版本
>
> **git reflog**
>
> 查看简略的版本信息



## 版本穿梭

切换当前版本：

> **git reset --hard 版本号**



## 分支操作

查看分支：

> **git branch -v**
>
> 展示所有分支和该分支当前版本

创建分支：

> **git branch** 分支名
>
> 将当前的分支进行复制，粘贴到新创建的分支当中

切换分支：

> **git checkout** 分支名



## 合并分支

正常合并：

> **git merge 分支名**     当前分支与目标分支合并，改变的是当前分支

冲突合并：

> **git merge 分支名**失败后，使用**vim 文件名**打开文件
>
> 直接输入**dd**删除行。完成后输入**:wq**保存并退出，注意要再次提交本地库



## 远程库

远程库别名：

> **git remote add 别名 https网址**      创建别名
>
> **git remote -v**      查看已有别名

创建远程分支：

> **git remote add 分支名 仓库** 

推送远程库：

> **git push 仓库 分支**      要求远程库和本地库都有该分支

拉取远程库：

> **git pull 仓库 分支**

在push时遇到本地版本落后远程库版本的问题：

>**git pull 仓库 分支**
>
>**git config pull.rebase  false**
>
>**git pull 仓库 分支**
>
>观察提示，找出自动合并失败的文件，并进行手动合并
>
>**git add**
>
>**git commit -m**
>
>**git push 仓库 分支**

