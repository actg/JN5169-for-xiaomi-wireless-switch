# NXP JN5169 zigbee 3.0 协议栈 for 绿米无线开关86贴墙面板

#### 备注
- 基于DimmerSwitch示例工程开发
- 工作在end device模式，休眠功耗0.3uA，工作功耗比较高，入网功耗大概十几毫安，组播发送指令2毫安左右

#### 分支
- master 小米无线开关(白色圆形)
- lvmi_wxkg 绿米无线开关(86面板贴墙式，包含1键，2键，3键)，默认project编译选项TRACE=0禁止log输出

#### 硬件线序
![pic](wire.png)
- 指示灯D1接到DIO10引脚，指示灯D2接到DIO11引脚，拉低点亮
- S2按键上拉1K，同时串接1K电阻接到DIO13引脚
- S3按键上拉1K，同时串接1K电阻接到DIO15引脚
- S4按键上拉1K，同时串接1K电阻接到DIO17引脚

#### 备注
- 配置、编译等参考master分支

#### picture
![pic](https://qnam.smzdm.com/202002/07/5e3d6ae2341ea2426.jpg_e680.jpg)
![pic](https://am.zdmimg.com/202002/11/5e4273c532bc05289.jpg_e680.jpg)
