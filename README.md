# ofxWatchBoot

### addon for meikyo power tap device
[MEIKYO Cooporation WATCH BOOT](http://www.meikyo.co.jp/product/?id=1492050202-128983)

### Usage
~~~
ofxWatchBoot watchBT;
watchBT.setup("192.168.7.70");

//power on port 1
watchBT.power(true, 1);

//power off port 1
watchBT.power(false, 1);

//power on port 2
watchBT.power(true, 2);

//power off port 2
watchBT.power(false, 2);
