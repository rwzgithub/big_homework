2020-6-14


##Changed:

-修改了发射子弹的原理，在炮塔成员中加入冷却时间，冷却结束后再次射出子弹


##added：

-完善了怪物类（enemy），并在mainwindow中增加怪物列表（enemies），使得怪物可以前进，受到伤害，并在血量减为零时消失

-增加了new_window和new_window_defeat两个类，分别用于胜利和失败后弹出的窗口

-在mainwindow类中增加成员kill_num和printed_num用来记录击杀数和出现数。（出现一定数量后不再产生怪物，击杀一定数量后，游戏结束）

-在mainwindow类中增加了over，win，stop_print_enemy三个bool变量，分别判断是否结束，是否胜利，是否已经产生所有怪物

-在mainwindow类中增加了tower_power变量，表示怪物摧毁炮塔所受的伤害

-在mainwindow::paintevent中，利用循环和遍历实现子弹碰到怪物就消失，怪物血量降低，降低到零怪物消失，怪物遇见炮塔可以摧毁炮塔，但自身也会受到伤害。

-在mainwindow中增加了游戏结束的条件：击杀所有怪物即胜利，一旦有怪物越过底线则失败


##removed：

-清理了enemy，tower，bullet以及mainwindow类中一些原本觉得需要而实际上没有用的变量和函数
