# 文件夹存档，不再使用QT

***

### 文件夹目录对应功能

> demo1 ————简单的按键槽与窗口信息的传递
> 
> demo3 ————硬代码登陆+转跳（弄不懂当初怎么在login_dialog.ui里面exitbutton控件实现点击退出，没有用到槽）
> 
> demo6 ————模块整合：文件位置/颜色选择/字体选择、框体位置信息、显示各种消息框、用户列表框
>  
> demo7 ————信息填写表格
> 
> demo8 ————硬代码计算器（+ - x /）
> 
> demo11 ————硬代码图片处理，纯CPU运算的代码效率非常低，学习图片处理的理论过程![Screenshot_20210815_155648](https://user-images.githubusercontent.com/45527640/129484183-8062a51b-1448-498a-aaf3-e89d6f723366.png)
> 
> demo12 ————画的类似outlook的界面
>
> downloader ————画的下载界面（用过FDW）
>
> Oracle_test ————Oracle数据库连接，有另一个比较全的数据库demo但分量比不上它（***版本需要对应***）
> 
> release_projection ————Windows环境下：图形化执行windeployqt发布程序，代替命令行（全部库都打包出来，文件不轻便，不如QT自带打包程序且全平台适用）
> 
> untitled ————Windows环境下：QProcess（）调用CMD进行ping和tracert、调用多线程并发执行函数、QNetworkAccessManager（）调用互联网API查询信息进行显示、QAxObject（）打开word、excel文件并读取各行各列的内容
> 
>https://github.com/foreverlz1111/CuTe
### 编译运行后发现输入框无法输入中文（Linux平台）
`原因：安装qt的时候缺少输入法库`

方法一：从系统与编译好的qt库中提取（系统编译版本需要和自己安装的qt版本一致）
- 查看系统编译好的输入法库：

```
cd /usr/lib/x86_64-linux-gnu/qt5/plugins/platforminputcontexts
```

- 将库复制到qt安装目录下（手动修改路径）：

```
cp *.so /home/{你的系统用户名}/Qt/5.15.2/gcc_64/plugins/platforminputcontexts
```

方法二：根据官方[编译源码](https://github.com/qt/qt5)
```
从生成文件中找到库文件 /plugins/platforminputcontexts，然后参照方法一复制到安装目录
```
   
