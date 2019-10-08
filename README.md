# Project-one

***预计完成这个项目所需要的时间:15-20小时***

## 简介

我们需要用C++来完成一个五子棋对战的小游戏，其中所需要的功能有:

- 人人对战
- 人机对战

## 框架代码说明

- `N` 棋盘大小
- `ChessBoard` 空位置的标志
- `flag[2]` 玩家的标志
- `now` 当前轮到谁下棋
- `InitChessBoard()` 初始化棋盘
- `ChoiceMode()`选择模式
- `PrintChessBoard()` 打印棋盘

采用了类的设计，但是不影响后续代码的编写和对框架代码的理解，方法具体内容需要大家自己看框架

## 你的任务

- 完成方法`void Play()`，该方法要求：
    - 初始化两个Player
    - 选择模式
    - 走棋且判断胜负
    - 是否再来一局
- 完成方法`void PlayChess()` 该方法要求:
    - 打印棋盘
    - 让玩家能够输入坐标
    - 判断输赢
    - 坐标不合法时需要重新输入
- 完成方法`int Judgelegal()` 判断落子合理性:
    - 落子必须在棋盘上
    - 所落子的地方为空
- 完成方法`int JudgeVictory()`，判断是否有人获胜:
    - 行满足？列满足？对角线满足？
    - 是否平局？

***以上任务可以在4-5小时内完成***

- 完成方法`void ComputerChess()`，此方法为本次项目的重点对象，在下文中讲解

允许大家在coding的时候任意增加新的方法，文件，类，对于我们已经给出的函数，你也可以自行修改，无需被局限在条条框框之中！与此同时，如果框架中有你认为***不合理***的地方，可以***自行修改***。

## ComputerChess

`void ComputerChess()`方法中，大家需要实现一个比较有智能的AI，具体怎么实现呢？下面给大家介绍几种常用的手段，需要大家自己去学习。

# Don't panic :)

### 如果你时间不多，推荐你使用 ***基础搜索算法***
- DFS
    - 深度优先遍历图的方法是，从图中某顶点v出发：
    （1）访问顶点v；
    （2）依次从v的未被访问的邻接点出发，对图进行深度优先遍历；直至图中和v有路径相通的顶点都被访问；
    （3）若此时图中尚有顶点未被访问，则从一个未被访问的顶点出发，重新进行深度优先遍历，直到图中所有顶点均被访问过为止。

- BFS
    - 最基础的搜索算法之广度优先搜索（BFS）。bfs相当于将整个图分层，从起始点u出发，u处在第0层，定义两个点之间的距离d(u,v)是u到v最少通过几条边可以走到。那么其他点所在的层数就是它到起始点u的距离。Bfs访问点的顺序就是逐层访问


### 如果你时间比较充裕，而且有算法设计和数据结构的基础，推荐你使用 ***博弈树***

博弈树是指由于动态博弈参与者的行动有先后次序，因此可以依次将参与者的行动展开成一个树状图形。

对于任何一种博弈竞赛，我们可以构成一个博弈树。它类似于状态图和问题求解搜索中使用的搜索树。博弈树的结点对应于某一个棋局，其分支表示走一步棋；根部对应于开始位置，其叶表示对弈到此结束。在叶节点对应的棋局中，竞赛的结果可以是赢、输或者和局。 

#### ***博弈树搜索——极大极小算法***

在二人博弈问题中，为了从众多可供选择的行动方案中选出一个对自己最为有利的行动方案，就需要对当前的情况以及将要发生的情况进行分析，通过某搜索算法从中选出最优的走步。
　基本思想或算法是：
- (1) 设博弈的双方中一方为MAX，另一方为MIN。然后为其中的一方寻找一个最优行动方案。
- (2) 为了找到当前的最优行动方案，需要对各个可能的方案所产生的后果进行比较，具体地说，就是要考虑每一方案实施后 ***对方可能采取的所有行动*** ，并计算可能的得分。
- (3) 为计算得分，需要根据问题的特性信息定义一个 ***估价函数*** ，用来估算当前博弈树端节点的得分。此时估算出来的得分称为 ***静态估值*** 。
- (4) 当端节点的估值计算出来后，再推算出父节点的得分，推算的方法是：
    - 对“或”节点，选其子节点中一个最大的得分作为父节点的得分，这是为了使自己在可供选择的方案中选一个对自己最有利的方案
    - 对“与”节点，选其子节点中一个最小的得分作为父节点的得分，这是为了立足于最坏的情况。这样计算出的父节点的得分称为倒推值。
- (5) 如果一个行动方案能获得较大的倒推值，则它就是当前最好的行动方案。

当MAX（我方）走步时，MAX总是考虑最好的情况，选择f(p)值最大的走步
当MIN（敌方）走步时，MAX总是考虑最好的情况，选择f(p)值最小的走步

![1](https://raw.githubusercontent.com/pppppkun/pppppkun.github.io/master/img/boyitree.png)

#### ***博弈树搜索——期望搜索算法***

期望搜索算法来源于极大极小算法，通常被运用于双人零和随机性博弈。

它在极大极小算法的基础上，通过在MAX层与MIN层之间加入PRO（概率）层，其中PRO层用来模拟随机性博弈过程中随机事件的期望值。

![2](https://raw.githubusercontent.com/pppppkun/pppppkun.github.io/master/img/boyitree2.png)

#### ***博弈树搜索——随机搜索算法***

根据计算步骤的确定与否，可将算法分为 ***确定性算法*** 和 ***随机性算法***。若确定了步骤，即为确定性算法；若容许算法在运行中可随意选择下一个计算步骤，即随机性算法。通常来讲，算法运行中面对多个选择的时候，随机性算法比确定性算法更加节省时间，大大降低算法的时间复杂度。

目前，随机搜索算法中主要有 ***拉斯维加斯算法*** 和 ***蒙特卡洛算法***，其基本思想是在有限的采样中获得最优解。在相同的采样越多的情况下，拉斯维加斯算法强调的是每一次迭代都在进步就越接近最优解；蒙特卡洛算法则是越有可能找到最优解，强调的是直接找到最优解。

蒙特卡洛算法是计算机博弈研究过程中运用最多的随机搜索算法，它主要是通过建立一个概率模型或者随机过程并采用抽样实验的方法来获得最优值。其基本思想就是通过大量且反复的抽样来得到结果，也就是说，蒙特卡洛算法的精确性前来依赖于随机模拟的次数。算法流程如图。

![2](https://raw.githubusercontent.com/pppppkun/pppppkun.github.io/master/img/boyitree3.png)

#### ***博弈树搜索——UCT算法***  ★★★

> UCT算法（Upper Confidence Bound Apply to Tree），即上限置信区间算法，是一种博弈树搜索算法，最初是为了限制围棋博弈树的搜索空间而产生的。
该算法将蒙特卡洛树搜索(Monte—Carlo Tree Search，MCTS)方法与UCB公式结合，在超大规模博弈树的搜索过程中相对于传统的搜索算法有着时间和空间方面的优势。
2006年UCT算法的出现改变了计算机围棋博弈领域止步不前的局面，互联网上有大量的资料可自行学习。因较为复杂，在此不再赘述。

下面附上学习资料：

- [UCT算法与四子棋](https://blog.csdn.net/u014397729/article/details/27366363)
- [数学原理与伪代码](https://blog.csdn.net/yw2978777543/article/details/70799799)
- [可视化讲解](https://jeffbradberry.com/posts/2015/09/intro-to-monte-carlo-tree-search/)


### ***优化搜索算法：α-β剪枝***

在博弈问题中，每一个格局可供选择的行动方案都有很多，因此会生成十分庞大的博弈树。试图利用完整的博弈树来进行极小极大分析是困难的。所以才有了α-β剪枝。为了提高搜索的效率，引入了通过对评估值的上下限进行估计，从而减少需进行评估节点的范围。
***主要概念：***

- MAX节点的评估下限值α：
    - 作为MAX节点，假定它的MIN节点有N个，那么当它的第一个MIN节点的评估值为α时，则对于其它节点，如果有高于α的节点，就取那最高的节点值作为MAX节点的值；否则，该点的评估值为α。
- MIN节点的评估上限值β：
    - 作为MIN节点，同样假定它的MAX节点有N个，那么当它的第一个MAX节点的评估值为β时，则对于其他节点，如果有低于β的节点，就取最低的节点值作为MIN节点的值；否则，该点的评估值为β。


### ***启发式搜索算法——A* 搜索***

### ***机器学习算法***

- *强化学习*
- *规则学习*
- *概率图模型*
- *度量学习*
- *……*

## 一些可能比较有帮助的话

根据实际情况来说，大家能通过简单的搜索算法就可以实现一个不败的计算机了，所以希望参与项目的每个人至少能在空余时间研究一下如何通过搜索算法打造一个比较强的AI。当然，如果大家空余时间比较多的话，还是推荐大家学习一下 ***UCT算法***。

关于如何使用搜索算法实现一个小AI呢？我们不妨考虑某条直线上所有落子的情况组成的集合 $S$ ，我们很容易就可以知道 $S$ 这个集合中元素的数量是有限的。那么，根据每种情况，我们可以给出AI走此处的一个 ***权值***,

那么在遍历棋盘给每个点赋值的过程中，我们同时也能找到棋盘上权值最大的点，让小AI走这个点即可。根据权值的设计，我们可以打造出有不同倾向的小AI，比如：
（假设AI是1，玩家是2）
- 进攻型 "01101"的权值大于"02202"
- 防守型 "01101"的权值小于"02202"

关于集合 $S$ 的元素有哪些，请看仓库中的另一个文件


### 项目的周期会比较长，希望大家可以坚持下来，最后可以让不同的同学之间进行对战。