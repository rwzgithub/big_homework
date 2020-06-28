2020-6-28

##Changed:

-将mainwindow中的enemy列表改变为enemy*类列表，用来存指向怪物的指针，这个改变方便于不同子类存在同一个列表中，并且方便血条和怪物的关联

-将游戏胜利条件更改为击败boss，


##added：

-增加了怪物类的派生类（enemy1，enemy2，boss），分别代表不同怪物和boss，三种怪物血量不同，boss移速更慢。

-增加了新的炸弹类，炸弹不会远程攻击，但是碰到怪物就会爆炸，伤害很高。

-在mainwindow类中增加了QMediaPlayer，可以播放背景音乐

-增加了血条类（enemy_hp），继承于QProgressBar，用来显示怪物的血量

-在mainwindow::paintevent中，利用循环和遍历实现血条的绘制，血条随怪物移动，怪物消失血条也消失。

-增加了金钱机制，初始金额100，tower消耗15，bomb消耗30，击杀不同怪物奖励不同的金钱，金钱不足无法购买炮塔；

##removed：

-清理了rpjobj类以及mainwindow类中一些原本觉得需要而实际上没有用的变量和函数
