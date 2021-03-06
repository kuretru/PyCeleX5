# PyCeleX5

## 环境

* 编译并安装好OpenCV 3.3
* 确保`ldd lib/libCeleX.so`中的所有库可以正确找到

## 编译

```bash
git clone git@github.com:kuretru/PyCeleX5.git --recurse-submodules
mkdir build
cd build
cmake ..
make
```

## 测试

```bash
sudo python3 main.py
```

## 文档

| 方法                                                |         功能         |                     说明                     |
| :-------------------------------------------------- | :------------------: | :------------------------------------------: |
| `void setRotateType(int type)`                      |   设置图像翻转类型   | 若type&1==1则上下翻转，若type&2==2则左右翻转 |
| `int getRotateType()`                               | 获取当前图像翻转类型 |                                              |
| `void startRippingBinFile()`                        |   开始翻录Bin文件    |                                              |
| `void stopRippingBinFile()`                         |   结束翻录Bin文件    |                                              |
| `void enableImageFileOutput(string &directoryPath)` | 启用翻录图片文件功能 |         应传入一个用于存放图片的目录         |
| `void enableEventDataOutput(string &filePath)`      | 启用翻录事件csv功能  |       应传入一个用于保存事件数据的文件       |
| `bool rippingBinFileFinished()`                     |   判断翻录是否完成   |                                              |
