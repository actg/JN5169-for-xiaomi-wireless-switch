# NXP JN5169 zigbee 3.0 协议栈source code for 小米39元无线开关

#### 备注
- 针对小米39元无线开关，在NXP JN5169平台的代码实现，在按键按下之后能够实现组播的方式向外发送信号，而不是官方自带的固件，只能实现向网关(短地址0x0000)发送report attribute单播指令，这样就必须依赖网关才能实现对其他设备的控制,组播的方式可以脱离网关
- 基于DimmerSwitch示例工程开发
- 工作在end device模式，休眠功耗0.3uA，工作功耗比较高，入网功耗大概十几毫安，组播发送指令2毫安左右
- 入网之后默认唤醒周期为60minutes，符合child aging特性
- LED连接的是DIO11引脚，拉高灭，拉低亮，入网成功LED闪烁3次
- 配置按钮连接的是DIO0引脚，点击一下直接steering入网
- 板子中间功能键连接的是DIO16 DIO17引脚，默认为高阻状态，因外外部有很大的上下拉电阻，大概0.9M，下降沿中断
- 长按配置按钮3S时间，自动删除PDM恢复出厂设置，之后自动深度休眠(必须外部按键唤醒，且只有配置按钮能够实现入网操作)
- 默认工作在11信道上，destination endpoint为8
- 可以通过指令配置组播的地址，并写入PDM保存，重新上电自动读取组播地址
- 入网阶段单个信道尝试3次，如果失败，直接进入深度休眠
- 通过BASIC cluster可以配置组播地址
- 实现了LED控制，入网成功之后，LED闪烁3次，占空比为50,
- 长按网络配置按钮3s，LED闪烁3次之后Leave网络并删除PDM，占空比为10
- 修复了长按恢复出厂后LED闪烁4次又重新加入网络的问题
- 修复了rejoin失败之后，无法再rejoin必须reset才能rejoin成功的问题
- [app.zpscfg编辑方法参考](https://blog.csdn.net/code_style/article/details/90487512)

#### 已知问题
- 暂无

#### 烧写方法
- 先进入ISP模式
```
JN51xxProgrammer.exe -s COM7 -P115200 --eraseflash=full -f C:\NXP\bstudio_nxp\Application\JN-AN-1219-Zigbee-3-0-Controller-and-Switch\DimmerSwitch\Build\DimmerSwitch_JN5169_DR1199.bin
```

![pic](https://am.zdmimg.com/201603/10/56e1344deed61.jpg_e600.jpg)
![pic](https://am.zdmimg.com/201609/25/57e74c058d09f.jpg_e600.jpg)
